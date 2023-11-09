#include<stdio.h>
#include<stdlib.h>

struct act {
int start;
int finish;
};
typedef struct act act;

void swap(act *a,act *b){
act temp=*a;
*a=*b;
*b=temp;
}

void heapify(act activities[],int n,int i){
int largest=i;
int left = 2*i+1;
int right=2*i+2;

if(left<n   && activities[left].finish > activities[largest].finish) largest=left;
if(right<n   && activities[right].finish > activities[largest].finish) largest=right;

if(largest!=i))
{
 swap(&
}
}


void heapsort(act activities[],int n){

for(int i=n/2-1;i>=0;i--){
heapify(activities,n,i);
}
//heap sort
for(int i=n-1;i>=0;i--){
swap(&activities[0],&activities[i]);
heapify(activites,i,0);
}
}


int main(int argc,char* argv[]){
if(argc<2){
	printf("invalid number of arguments");
	return 1;
}
FILE* fp=fopen(argv[1],"r");

if(fp==NULL){
	printf("file does not exists\n");
	return 1;
}

int n;
if(fscanf(fp,"%d\n",&n)==0){
printf("error while reading total number of aactivities\n");
return 1;
}
act *activities = malloc(n*sizeof(act));
int count=0,start,finish;
while(count<n && fscanf(fp,"%d %d\n",&start,&finish)==1){
activities[count].start=start;
activities[count].finish=finish;
count++;
}
heapsort(activities,n);
printf("activities sorted according to their finish time:\n);
for(int i=0;i<n;i++) printf("%d\t %d\t %d \n",i,activities[i].start,activities[i].finish);
maxactivities(activites,n);

}
