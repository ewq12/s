#include<stdio.h>
#include<conio.h>

int top=-1, stack[20], adj[20][20], vis[20], x, y, flag=0, q[20], front=-1, rear=-1;

void push(int );

int pop();

main()
{
	int i,j,n,v,w,source;
	
	printf("\nEnter the number of vertices: ");
	scanf("%d",&n);
	
	printf("\n1 for connected and 0 for not.\n\n");
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("Is %d and %d Connected: ",i,j);
			scanf("%d",&adj[i][j]);			
		}
		printf("\n");
	}
	
	printf("\n\n");
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("\t%d",adj[i][j]);			
		}
		printf("\n");
	}
	
	for(i=1;i<=n;i++)
	{
		vis[i]=0;
	}
	
	printf("\n\n");
	
	printf("Enter the source Vertex: ");
	scanf("%d",&source);
	
	v=source;
	
	vis[v]=1;
	
	printf("\nDFS: ");
	
	printf("%d",v);
	
	push(v);
	
	flag++;
	
	while(flag!=n)
	{	
		for(i=1;i<=n;i++)
		{
			if(adj[v][i]==1 && vis[i]==0)
			{
				vis[i]=1;
				printf("%d",i);
				push(i);
				v=i;
				flag++;																;
			}
		}
	v=pop();	
   }
}

void push(int x)
{
	top++;
	stack[top]=x;
}

int pop()
{
	y=stack[top--];
	return y;	
}


