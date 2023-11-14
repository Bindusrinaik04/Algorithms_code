#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int v;

int minkey(int dist[],int spset[]){
int min=INT_MAX,min_index;

for(int count=0;count<v;count++){
if(spset[count]==0 && dist[count]<min){
min=dist[count];
min_index=count;
}
}
return min_index;
}

void dijkstra(int graph[][v],int source){

int dist[v];
int parent[v];
int spset[v];

for(int i=0;i<v;i++)
{
	dist[i]=INT_MAX;
	parent[i]=-1;
	spset[i]=0;
}
dist[source]=0;
parent[source]=-1;

for(int count=0;count<v-1;count++){
 int u=minkey(dist,spset);
 spset[u]=1;
 for(int j=0;j<v;j++){
 if(spset[j]==0 && graph[u][j] && dist[u] !=INT_MAX && dist[u]+graph[u][j]<dist[j])
 {
 dist[j]=dist[u]+graph[u][j];
 parent[j]=u;
 }
 }
}
printgraph(dist);
}

void printgraph(int dist[]){
 
 printf("vertex \t Dist from source\n");
 for(int i=1;i<v;i++)
 {
 //sum+=graph[i][parent[i]];
 printf("%d \t %d\n",i,dist[i]);
}

}

int main(int argc,char* argv[]){

if(argc<2){
	printf("give the file that consists of input\n");
	return 1;
}
FILE* fp= fopen(argv[1],"r");
if(fp==NULL){
	printf("file doesnot exists\n");
		return 1;
}

if(fscanf(fp,"%d",&v)==0){
	printf("error while reading number of vertices\n");
	return 1;
}
//reading is completed
int graph[v][v];
for(int i=0;i<v;i++)
{
	for(int j=0;j<v;j++)
	fscanf(fp,"%d",&graph[i][j]);
}

for(int i=0;i<v;i++)
{
 for(int j=0;j<v;j++)
 printf("%d ",graph[i][j]);
 printf("\n");
}
int root=0;
dijkstra(graph,root);
return 0;
}
