//Dijikstra's Algorithm
#include <stdio.h>
#include <conio.h>
#define max 10

int vertices;
int graphMatrix[10][10];
int theMatrix[15][15];
int distance[10];
int visited[10] = {0,0,0,0,0,0,0,0};

void input();
void displayMatrix();
void djAlgorithm();
void display();

void main(){
	printf("\n\t\t\tDijistra's Algorithm\n\n");
	input();
	displayMatrix();
	djAlgorithm();
}

void input(){
	int i, j;
	printf("Enter the number of vertices ");
	scanf("%d",&vertices);
	for(i=0;i<vertices;i++){
		for(j=0;j<vertices;j++){
			printf("Enter the cost of path from vertex %d to vertex %d (zero if no path) ",i,j);

			scanf("%d",&graphMatrix[i][j]);
		}
	}
}

void displayMatrix(){
	int i, j, k;
	printf("The graph matrix is as follows:\n");
	printf("   ");
	for(k=0;k<vertices;k++){
		printf("%d\t",k);
	}
	printf("\n");
	for(i=0;i<vertices;i++){
		printf(" %d ",i);
		for(j=0;j<vertices;j++){
			printf("%d\t",graphMatrix[i][j]);
		}
		printf("\n");
	}
}

void djAlgorithm(){
	int i, num, u, w;
	int startVertex, currentVertex;
	printf("Enter the starting vertex (index of vertex - 0,1,2,3..)");
	scanf("%d",&startVertex);
	for(i=0;i<vertices;i++){
		distance[i] = graphMatrix[startVertex][i];
	}
	display();
	visited[startVertex] = 1;
	num = 0;
	while(num < vertices){
		u = choose();
		num++;
		for(w=0;w<vertices;w++){
			if(graphMatrix[u][w] > 0 && visited[w] == 0){
				if(distance[w] < 0 || distance[u]+graphMatrix[u][w] < distance[w]){
					distance[w] = distance[u]+graphMatrix[u][w];
				}
			}
		}
		display();
	}
}

int choose(){
	int i, smallest, initial, final, flag=0;
	for(i=0;i<vertices;i++){
		if(distance[i]>0 && visited[i] == 0){
			smallest = distance[i];
			flag = 0;
			initial = i;
			break;
		}
	}
	for(i=0;i<vertices;i++){
		if(distance[i] < smallest && distance[i] > 0 && visited[i] == 0){
			smallest = distance[i];
			final = i;
			flag =  1;
		}
	}
	if(flag == 0){
		visited[initial] = 1;
		return initial;
	}
	else if(flag == 1){
		visited[final] = 1;
		return final;
	}
	return;
}

void display(){
	int i,j;
	for(i=0;i<vertices;i++){
		printf(" %d\t",distance[i]);
	}
	printf("\n");
}
