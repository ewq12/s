#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node {
  int data;
  struct node *left;
  struct node *right;
  
}*root=NULL,*temp=NULL;

void create()
{
char ch;
 do
 {
 struct node *new_node,*current;
 new_node=(struct node *)malloc(sizeof(struct node));
int d;
 printf("\nEnter the data ,if first time it would be the root node : ");
 scanf("%d",&d);
 new_node->left=NULL;
 new_node->right=NULL;
new_node->data=d;

  if(root==NULL)
  
  root=new_node;
  
  
  else
  {
  	temp=root;
  	
  	while(1)
  	{
  		if(d<(temp->data)&&temp->left==NULL)
  		{temp->left=new_node;
  		break;}
  		else if(d>(temp->data)&&temp->right==NULL)
  		{
  			temp->right=new_node;
  			break;
		  }
		  else if(d<(temp->data)&&temp->left!=NULL)
		  temp=temp->left;
		  else if(d>(temp->data)&&temp->right!=NULL)
		  temp=temp->right;
	  }
	  temp=root;
  }
  printf(" \n Do you want to creat another : ");
 ch=getche();
 }while(ch!='n');
}
 search()
 {
 	printf("Enter the data to be found ");
 	int d;
 	
 	scanf("%d",&d);
 	int c=0;
 	temp=root;
  		while(temp!=NULL)
  	{
  		if(d==(temp->data))
  		{printf("Found");
  		c++;
  		//temp->right=NULL;
  		
  		break;}
  		else if(d<(temp->data))
  			temp=temp->left;
  		else if(d>(temp->data))
  		{
  			temp=temp->right;
  		
		  }
		  
	  }
	  if(c==0)
	  printf("Not found");
	
 }
 void inorder(struct node *x)
 {
 	if(x==NULL)
 	return;
 	inorder(x->left);
 	printf("%d ,",x->data);
 	
 	inorder(x->right);
 	
 	
 }
void preorder(struct node *x)
 {
 	if(x==NULL)
 	return;
 	printf("%d ,",x->data);
 	preorder(x->left);
 	preorder(x->right);
 	
 	
 }
void postorder(struct node *x)
 {
 	if(x==NULL)
 	return;
 	
 	postorder(x->left);
 	postorder(x->right);
 	printf("%d ,",x->data);
 	
 	
 }
 struct node * minValueNode(struct node* node)
{
    struct node* current = node;
 

    while (current->left != NULL)
        current = current->left;
 
    return current;
}

struct node* deleteNode(struct node* root, int data)
{
    
    if (root == NULL) return root;
        if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
         root->data = temp->data;
         root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
 void delete1()
 {
 printf("Enter the data to be deleted ");
 	int d;
 	
 	scanf("%d",&d);
 	int c=0;
 	temp=root;
 		struct node *new_node,*current;
 		new_node->data=d;
 new_node=(struct node *)malloc(sizeof(struct node));
  	
  	while(temp!=NULL)
  	{
  		if(d==(temp->data))
  		{c++;
  		break;
		  }
  		else if(d<(temp->data))
  		temp=temp->left;
	
  		else if(d>(temp->data))
  		temp=temp->right;
  	 }
	  if(c==0)
	  printf(" Data not found and hence cannot be deleted");
	  if(c>0)
	  {
	  	
	 deleteNode(root,d); 
	  }
}
 
   main()
 { int x=0;
 	do{
 	printf(" \n \n Enter\n 1. Create \n 2.Search \n 3.Inorder \n 4.Preorder \n 5.Postorder \n 6.Delete \n");
 	scanf("%d",&x);
 	if(x==1)
 	create();
 	else if(x==2)
 	search();
 	else if(x==3)
 	inorder(root);
 	else if(x==4)
 	preorder(root);
 	else if(x==5)
 	postorder(root);
 	else if(x==6)
 	delete1();	
 }while(x!=12);
 
 }
