#include<stdio.h>
#include<stdlib.h>

typedef struct item{
 int weight;
 int profit;
 float ratio;
 int include;
 }item;
 
 void swap(item *a,item* b){
 item temp=*a;
 *a=*b;
 *b=temp;
 }
 
 void heapify(item items[],int n,int i){
 int small=i;
 int left=2*i+1;
 int right=2*i+2;
 
 if(left<n && items[small].ratio > items[left].ratio) small=left;
 if(right<n && items[small].ratio >items[right].ratio) small = right;
 if(small !=i){
 swap(&items[small],&items[i]);
 heapify(items,n,small);
 }
 }
 
 void heapsort(item items[],int n){
 
 //building heap
 for(int i=n/2-1;i>=0;i--)
 heapify(items,n,i); //builds max heap
 
 for(int i=n-1;i>=0;i--){
 swap(&items[i],&items[0]);
 heapify(items,i,0);
 }
 
 }
 
 void knapsack(item items[],int capacity,int n){
 //calsulate the ratio for each item
 for(int i=0;i<n;i++)
 items[i].ratio= (float) items[i].profit/items[i].weight;
 
 //heapsort the items according to their ratios
 heapsort(items,n);
 for(int i=0;i<n;i++){
 printf("after sorting: %d %d %.3f\n",items[i].weight,items[i].profit,items[i].ratio);
 }
 
 int result=0;
 for(int i=0;i<n;i++){
 if(items[i].weight < capacity){
  result+=items[i].profit;
  capacity-=items[i].weight;
  items[i].include=1;
 }
 else items[i].include=0;
 }
 printf("the weights and profits that are included are:\n");
 for(int i=0;i<n;i++){
 if(items[i].include){
 printf("%d\t %d\n",items[i].weight,items[i].profit);
 }
  
 }
 printf("totals profit:%d\n",result);
 }
 
 int main(int argc,char* argv[]){
 if(argc<2)
 {
 	printf("enter the file name also\n");
 	return 1;
 }
 FILE* fp=fopen(argv[1],"r");
 if(fp==NULL){
 	printf("file error\n");
 	return 1;
 }
 int n,capacity; //number of items and capacity
 if(fscanf(fp,"%d %d",&n,&capacity)==0){
 printf("error while readin the input\n");
 return 1;
 }
 item* items=malloc(n*sizeof(item));
 if(items==NULL){
 	printf("error while allocating the memory to array of items\n");
 	return 1;
 }
 int i;
 for(i=0;i<n;i++){
 fscanf(fp,"%d %d",&items[i].weight,&items[i].profit);
 }
 for(i=0;i<n;i++){
 printf("%d %d\n",items[i].weight,items[i].profit);
 }
 
 knapsack(items,capacity,n);
 }
