#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

int v;

int minkey(int key[],int mstset[]){
int min=INT_MAX,min_index;
for(int count=0;count<v;count++){
if(mstset[count]==0 && key[count]<min)
{
 min=key[count];
 min_index=count;
}
}
return min_index;
}

void primMst(int graph[][v]){
int parent[v];
int key[v];
int mstset[v];

for(int i=0;i<v;i++)
	{ 
	key[i]=INT_MAX;
        parent[i]=-1;
        mstset[i]=0;
        }
key[0]=0;
parent[0]=-1;

for(int count=0;count<v-1;count++){
	int u=minkey(key,mstset);
	mstset[u]=1;
		 for(int i=0;i<v;i++){
		 	if(graph[u][i] && mstset[i]==0 &&graph[u][i]<key[i]){
 			 key[i]=graph[u][i];
 			 parent[i]=u;
		 	} 
	 	}
}

printgraph(parent,graph);

}

void printgraph(int parent[],int graph[][v]){
int sum=0;
 printf("Edge \t edge weight \t weight\n");
 for(int i=1;i<v;i++)
 {
 sum+=graph[i][parent[i]];
 printf("%d----%d\t %d\t %d\n",parent[i],i,graph[i][parent[i]],sum);
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

primMst(graph);
return 0;
}
