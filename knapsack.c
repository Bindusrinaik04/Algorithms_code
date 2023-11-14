
#include<stdio.h>
#define MIN -1

int max(int a,int b){
return (a>b)?a:b;
}
int knapsackprofit(int weights[],int profits[],int n,int cap){
if(n<=0 || cap<=0)
return 0;
int knapsack[n+1][cap+1];
int i,w;
for(i=0;i<=n;i++)
{
for(w=0;w<=cap;w++){
if(i== 0 || w == 0) knapsack[i][w]=0;
else if ( weights[i-1]<=w)
 knapsack[i][w]=max(knapsack[i-1][w],profits[i-1]+knapsack[i-1][w-weights[i-1]]);
 else
 knapsack[i][w]=knapsack[i-1][w];
}
}
for(int i=0;i<=n;i++)
{
for(int j=0;j<=cap;j++)
printf("%d ",knapsack[i][j]);
printf("\n");
}
return knapsack[n][cap];
}

int main(int argc,char* argv[]){

if(argc<2){
printf("enter file name for input \n");
return 1;
}
FILE *fp=fopen(argv[1],"r");

if(fp==NULL){
printf("the file does not exists\n");
return 1;
}
int n,cap;
if(fscanf(fp,"%d %d\n",&n,&cap)==0){
printf("error while reading input\n");
return 1;
}
int profits[n],weights[n];
int count=0,readw,readp;
while(count<n && fscanf(fp,"%d ",&readw) !=0){
weights[count]=readw;
count++;
}
count=0;
while(count<n && fscanf(fp,"%d",&readp) !=0){
//weights[count]=readw;
profits[count]=readp;
count++;
}
int maxp=knapsackprofit(weights,profits,n,cap);
printf("%d is the capacity,%d is maximum profit\n",cap,maxp);
return 0;
}
