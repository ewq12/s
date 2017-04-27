#include <stdio.h>
#include <conio.h>
#define infinity 999

void dij(int n,int v,int cost[10][10],int dist[]);

int main()
{
 	int n,v,i,j,cost[10][10],dist[10];

 	printf("\n Enter the number of nodes: ");
 	scanf("%d",&n);
 
 	printf("\n");


	// For Input of the cost Matrix
 
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf(" Distance between V%d and V%d : ",i,j);
			scanf("%d",&cost[i][j]);
			   
			if(cost[i][j]==0)
			   cost[i][j]=infinity;  
			   
			if(i==j)
				cost[i][j]=0;   
		}
		printf("\n");
	}
	
	printf("\n");
	
	
	// To Display cost Matrix
	
	for(i=1;i<=n;i++)
	{
		printf("\tV%d",i);
	}
		
	printf("\n\n");
	
	for(i=1;i<=n;i++)
	{
		printf("V%d",i);
		for(j=1;j<=n;j++)
		{
			printf("\t");
						
			if(cost[i][j]==infinity)
			   printf("%c",236);
			   
			else if(i==j)
				printf("%d",0);    
			   
			else
			   printf("%d",cost[i][j]);  
		}
		printf("\n\n");
	}
	 

	 // Input the Source Vertex
	 
 	printf("\n Enter the source: ");
 	scanf("%d",&v);
 
 
 	 // To Calculate the minimum distance
 
 	dij(n,v,cost,dist);
 
 
 	 // Display the shortest path
 	 
 	printf("\n Shortest path: \n\n");
 	
 	for(i=1;i<=n;i++)
	{
		printf("\tV%d",i);
	}
	
	printf("\n\n");
	
	printf("V%d",v);
 
 	for(i=1;i<=n;i++)
  	{
  		if(i!=v)
   		{
   			printf("\t%d",dist[i]);
		}
		
		else
		{
			printf("\t0");
		}
  	}

 getch();
 
 return 0;
}


void dij(int n,int v,int cost[10][10],int dist[])
{
 	int i,u,count,w,flag[10],min,j;
 
 	for(i=1;i<=n;i++)
  	{
  		flag[i]=0;
		dist[i]=cost[v][i];
	}	
  
 	count=2;
 
    while(count<=n)
 	{
  		min=99;
  
 		for(w=1;w<=n;w++)
   		{
   			if(dist[w]<min && !flag[w])
            {
            	min=dist[w];
				u=w;
			}
		}
    
		flag[u]=1;
  		count++;
  
  		for(w=1;w<=n;w++)
  		{
  			if((dist[u]+cost[u][w]<dist[w]) && !flag[w])
      		{
      			dist[w]=dist[u]+cost[u][w];
			}	 		
		}
		
 	}
}

