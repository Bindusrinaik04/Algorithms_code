#include<stdio.h>
#include<stdlib.h>

struct job {
 int id;
 int dead;
 int profit;
 };
 
typedef struct job job;

void swap(job *a,job *b){
job temp =*a;
*a=*b;
*b=temp;
}

void heapify(job jobs[],int n,int i){

int smallest=i;
int left=2*i+1;
int right=2*i+2;

if(left <n  && jobs[left].profit < jobs[smallest].profit) smallest=left;
if(right < n && jobs[right].profit < jobs[smallest].profit) smallest=right;

if(smallest!= i) {
swap(&jobs[i],&jobs[smallest]);
heapify(jobs,n,smallest);
}

}

void heapsort(job jobs[],int n){
for(int i=n/2-1;i>=0;i--)
	heapify(jobs,n,i);
for(int i=n-1;i>=0;i--){
swap(&jobs[0],&jobs[i]);
heapify(jobs,i,0);
}

printheap(jobs,n);
}
//printing function
void printheap(job jobs[],int n){
for(int i=0;i<n;i++){
printf("%d \t %d \t %d\n",jobs[i].id,jobs[i].dead,jobs[i].profit);
}
}
int min(int a,int b){
return (a>b)?b:a;
}
//job scheduling function

void jobscheduling(job jobs[],int n){
int result[n];
int slot[n];
for(int i=0;i<n;i++) slot[i]=0;

	for(int i=0;i<n;i++){
		for(int j=min(n,jobs[i].dead)-1;j>=0;j--){
		if(slot[j]==0)
		{
		 result[j]=jobs[i].id;
		 slot[j]=1;
		 break;
		}
		}	
	}
	printf("\n");
	for(int i=0;i<n;i++){
	if(slot[i]){
	printf("%d \t",result[i]);
	}
	}
}

int main(int argc,char* argv[]){

if(argc<2) {
	printf("Give the file as input\n");
	return 1;
}
FILE *fp=fopen(argv[1],"r");
if(fp==NULL){
 printf("file does not exist");
 return 1;
}
int n; //to read total number of jobs

if(fscanf(fp,"%d\n",&n)==0){
 printf("error while reading the input variable\n");
 return 1;
}

job *jobs=malloc(n*sizeof(job));
if(jobs==NULL) {
 printf("error while allocating memory \n");
 return 1;
}
int count,id,dead,profit;
while(count<n && fscanf(fp,"%d %d %d",&id,&dead,&profit)!=0){
	jobs[count].id=id;
	jobs[count].dead =dead;
	jobs[count].profit=profit;
	count++;
}
printf("\n befor sorting:\n");
printheap(jobs,n);
printf("\n after sorting:\n");
heapsort(jobs,n); //to sort the jobs in decreasing order of there profits.

jobscheduling(jobs,n);
}
