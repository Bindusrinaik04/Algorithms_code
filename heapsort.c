//heapsort

#include<stdio.h>
#include<stdlib.h>

void swap(int* a,int* b){
int temp=*a;
*a=*b;
*b=temp;
}

//heapify part
void heapify(int arr[],int n,int i){
int largest=i;
int left=2*i+1;
int right=2*i+2;

if(left < n && arr[left] > arr[largest]){
largest=left;
}
if(right <n && arr[right]>arr[largest]){
 largest = right;
}

if(largest !=i){
 swap(&arr[i],&arr[largest]);
 heapify(arr,n,largest);
}
}

//heapsort part
void heapsort(int arr[],int n){

//building heap

for(int i=n/2-1;i>=0;i--){
heapify(arr,n,i);
}

//heapsort
//starting from last index valuuuue
for(int i=n-1;i>=0;i--){
//swap the last element with first element
swap(&arr[0],&arr[i]);
//check for heap property of the first element
heapify(arr,i,0);
}
printf("\n");
for(int i=0;i<n;i++) printf("%d\t",arr[i]);
}

int main(int argc,char* argv[]){
if(argc!=2){
	printf("No file name entered\n");
	return 1;
}
FILE* fp= fopen(argv[1],"r");
if(fp==NULL) {
	printf("file doesn't exists\n");
	return 1;
}
int n;
if(fscanf(fp,"%d\n",&n)==0){
 printf("error: reading n value failed\n");
 return 1;
 
}
int *arr=(int *)malloc(n*sizeof(int));
int count=0,read;
while(count<n && fscanf(fp,"%d",&read)==1){
arr[count]=read;
count++;
}
for(int i=0;i<n;i++) printf("%d\t",arr[i]);
heapsort(arr,n);
printf("\n");
 
}

