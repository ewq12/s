#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node* link;
	struct node* prev;
}*temp,*head=NULL,*q,*temp1,*temp2;

void insert();

void displaybeg();

void displayend();

void delete1();

void search(int );

void sort();

void concat();

void main()
{ 
    int x,ele;

	printf("\n 1. Insert ");
	printf("\n 2. Delete");
	printf("\n 3. Display from begining");
	printf("\n 4. Display from end");
	printf("\n 5. Search");
	printf("\n 6. Sort");
	printf("\n 7. Concatenate");
	printf("\n 8. Exit");
	
	do
	{
		printf("\n\nEnter option: ");
	    scanf("%d",&x);
	    switch(x)
	    {
	    	
		    case 1: insert();
		            break;  
			
			case 2: delete1();
			        break;
					
		    case 3: displaybeg();
			        break;	
			        
			case 4: displayend();
			        break;        
					
			case 5: printf("Enter element to be searched: ");
			        scanf("%d",&ele);
					search(ele);
					break;	
					
			case 6: sort();
			        break;	
					
			case 7: concat();
					break;						 
				
	        case 8:	exit(0);		  	    
		      
		    default: printf("Wrong choice");	    
	    }
	}while(x!=8);
		
 getch();
}


void insert()
{
	int i,n,d,op,l;
printf("Enter the number of nodes: ");
  scanf("%d",&n);
  
  for(i=0;i<n;i++)
 {
   temp=(struct node*)malloc(sizeof(struct node));
   
   printf("\n1.Insert at front  2.Insert at end  3.Insert at middle: ");
   scanf("%d",&op);
  
  if(op==1) 
   {
     printf("Enter data: ");
     scanf("%d",&d);   
     temp->data=d;
     temp->link=NULL;
     temp->prev=NULL;
    
     if(head==NULL)
       {
	     head=temp;  
	     q=temp;
       } 
  
     else
     {
  	     temp->link=head;
  	     head->prev=temp;
  	     head=temp;		    
     }
 }
 
 else if(op==2)
 {
 	 printf("Enter data: ");
     scanf("%d",&d);   
     temp->data=d;
     temp->link=NULL;
     
     q=head;
     
      while(q->link!=NULL)
     {
	     q=q->link;
     }
     
     temp->data=d;
     temp->link=NULL;
     q->link=temp;
     temp->prev=q;
     
 }
 
 else
 {
 	printf("Enter the position: ");
 	scanf("%d",&l);
 	
 	printf("Enter data: ");
    scanf("%d",&d);   
    temp->data=d;
    temp->link=NULL;
 	
 	q=head;
 	
 	for(i=1;i<l-1;i++)
 	{
 		q=q->link;
	}
	temp->link=q->link;
	q->link=temp;	
	temp->prev=q;	
 }
}	
}


void delete1()
{
	int op,l,i;
	
	printf("\n1. Delete at front  2. Delete at end  3. Delete at middle");
	scanf("%d",&op);
	
	if(op==1)
	{
		temp=head;
		head=temp->link;
		q=temp->link;
		q->prev=head;
		
		free(temp);
		printf("Delete successful");
	}
	
	else if(op==2)
	{	
		q=head;
		
		while(q->link!=NULL)
		{
			temp=q;
			q=q->link;
		}
		
		free(q);
		temp->link=NULL;		
	}
	
	else
	{
		int i=0,n;
	printf("\nEnter the postion at which you want delete operation:");
	scanf("%d",&n);
	
	temp=head;
	
     while(temp != NULL)
     {
     	if(i==(n-1))
     	{
     		temp1=temp->link;
     		temp2=temp1->link;
     		temp->link=temp2;
     		temp2->prev=temp;
     		free(temp1);
     		break;
		}
		
		else
		{
			i++;
			temp=temp->link;
		}
	 }	 	
    }	
}


void displaybeg()
{
	q=head;
	
	 while(q->link!=NULL)
   {	
		printf("%d <--> ",q->data);
		q=q->link;
   }
	printf("%d",q->data);
}


void displayend()
{
	temp=head;
	
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}
	
	q=temp;
	
	while(q->prev!=NULL)
	{
		printf("%d <--> ",q->data);
		q=q->prev;
	}
	printf("%d",q->data);
}

void search(int n)
{
	q=head;
	int i=1,flag=1;
	
	while(q->link!=NULL)
	{
		if(q->data==n)
		{
			flag=0;
			printf("\nElement found at location: %d",i);
			break;
		}
		else
		{
			i++;
			q=q->link;
		}
	}
	if(flag==1)
	  printf("\nElement not found");
}


void sort()
{
	temp=head;
	temp2=head;
	int t;
	
	while(temp->link != NULL)
	{
		temp2=temp;
		
		while(temp2 != NULL)
		{
			if(temp->data > temp2->data)
			{
				t = temp->data;
				temp->data = temp2->data;
				temp2->data = t;
			}
			temp2 = temp2->link;
		}
		temp=temp->link;
	}
}

void concat()
{
	struct node *head2=NULL,*new2,*q2;
	int m,i,d;
	
	printf("Enter the number of nodes: ");
	scanf("%d",&m);
	
	for(i=0;i<m;i++)
	{
		new2=(struct node*)malloc(sizeof(struct node));
			
		printf("Enter data: ");
		scanf("%d",&d);
		
		new2->data=d;
		new2->link=NULL;
		new2->prev=NULL;
		
		if(head2==NULL)
		{
			head2=new2;
			q2=new2;
		}
		
		else
		{
			q2->link=new2;
			head2->prev=new2;
			q2=new2;
		}
		
		q2->link=NULL;
				
	}	
	
	temp=head;
		
		while(temp->link != NULL)
		{
			temp=temp->link;
		}
		
	  temp->link=head2;	
	  head2->prev=temp;
}
