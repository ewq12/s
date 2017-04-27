#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node* link;
}*temp,*head=NULL,*q,*temp1,*temp2,*last,*last2;

void insert();

void display();

void delete1();

void search(int );

void sort();

void concat();

void main()
{ 
    int x,ele;

	printf("\n 1. Insert ");
	printf("\n 2. Delete");
	printf("\n 3. Display");
	printf("\n 4. Search");
	printf("\n 5. Sort");
	printf("\n 6. Concatenate");
	printf("\n 7. Exit");
	
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
					
		    case 3: display();
			        break;	
					
			case 4: printf("Enter element to be searched: ");
			        scanf("%d",&ele);
					search(ele);
					break;	
					
			case 5: sort();
			        break;	
					
			case 6: concat();
					break;						 
				
	        case 7:	exit(0);		  	    
		      
		    default: printf("Wrong choice");	    
	    }
	}while(x!=7);
		
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
   
     if(head==NULL)
       {
	     head=temp;  
	     q=temp;
	     last=temp;
       } 
  
     else
     {
  	     temp->link=head;
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
     
      while(q!=last)
     {
  	     q=q->link;
     }
     
     temp->data=d;
     temp->link=NULL;
     
	 q->link=temp;
     
	 temp->link=head;
	 
	 last=temp;
     
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
 }
}	
}


void delete1()
{
	int op,l,i;
	
	printf("\n1. Delete at front  2. Delete at end  3. Delete at middle: ");
	scanf("%d",&op);
	
	if(op==1)
	{
		temp=head;
		head=temp->link;
		
		free(temp);
		printf("Delete successful");
	}
	
	else if(op==2)
	{	
		q=head;
		
		while(q!=last)
		{
			temp=q;
			q=q->link;
		}
		
		last=temp;
		free(q);
		last->link=head;		
		
	}
	
	else
	{
		int i=0,n;
	printf("\nEnter the postion at which you want delete operation: ");
	scanf("%d",&n);
	
	temp=head;
	
     while(temp != NULL)
     {
     	if(i==(n-1))
     	{
     		temp1=temp->link;
     		temp2=temp1->link;
     		temp->link=temp2;
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


void display()
{
	q=head;
	
	 while(q!=last)
   {	
		printf("%d -> ",q->data);
		q=q->link;
   }
	printf("%d -> Head",q->data);
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
		
		if(head2==NULL)
		{
			head2=new2;
			q2=new2;

		}
		
		else
		{
			q2->link=new2;
			q2=new2;
		}
				
	}	
	
	temp=head;
		
		while(temp->link != NULL)
		{
			temp=temp->link;
		}
		
	  temp->link=head2;
	  last=new2;
	  last->link=head;
	  	
}
