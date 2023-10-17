//1.generate random number and store them in the file.
//2.use the file and apply the quick sort on them.
//3.apply randomized quick sort on the same
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void quicksort(int[],int,int);
void quicksortrandom(int[],int,int);
int partition(int[],int,int);
int partitionrandom	(int[],int,int);
void swap(int*,int*);

//swap function
void swap(int* a,int* b){
int temp=*a;
*a=*b;
*b=temp;
}

//dividing the array
void quicksort(int arr[],int start,int end){
if(start<end){
int p = partition(arr,start,end);
 //printf("%d\n",p); //printing pivot point
quicksort(arr,start,p-1);
quicksort(arr,p+1,end);
}

}

//main code for quick sort
/*------------Usual implementation of quick sort--------------------------*/
int partition(int arr[],int low,int high){
 
 int pivot=arr[high];
 int i,j;
 i=low-1;
 j=low;
 for(;j<=high-1;j++){
 if(arr[j]<pivot){
 i++;
 swap(&arr[i],&arr[j]);
 }
 }
 i++;
 swap(&arr[i],&arr[high]);
 
 return i;

}

/*-----------------------randomized quick sort----------------------------------*/
void quicksortrandom(int arr[],int start,int end){
if(start<end){
int p = partitionrandom(arr,start,end);
 //printf("%d\n",p); //printing pivot point
quicksortrandom(arr,start,p-1);
quicksortrandom(arr,p+1,end);
}

}

int partitionrandom(int arr[],int low,int high){
 
 int pivot=low+rand()%(high-low+1); //high-low+1 [select random index as pivot
 printf("\n pivot element : %d\n",pivot);
 swap(&arr[pivot],&arr[high]);  //swap pivot indexed with last element in the array
 pivot = arr[high];
 
 int i,j;
 i=low-1;
 j=low;
 for(;j<=high-1;j++){
 if(arr[j]<pivot){
 i++;
 swap(&arr[i],&arr[j]);
 }
 }
 i++;
 swap(&arr[i],&arr[high]);
 
 return i;

}

int main(){

 /*int n=6,i;
 int arr[]={10,7,8,9,1,5};
 quicksort(arr,0,n-1);
for(i=0;i<n;i++) printf("%d\t",arr[i]);
*/
srand(time(NULL));

/*---------------generating random numbers and saving it to file------------------------*/
FILE *input = fopen("randomnumbers.txt","w");
if(!input){ printf("error in opening file"); return 1;}

int n=10; //total number of random numbers generated
for(int i=0;i<n;i++){
int num = rand()%100;
fprintf(input,"%d\n",num);
}

fclose(input);

/*-----------------taking input from file-------------------------*/

FILE *fp=fopen("randomnumbers.txt","r");
if(!fp){ printf("error in opening file"); return 1;}

int arr[n]; //size declared above
for(int i=0;i<n;i++){
 	if(fscanf(fp,"%d",&arr[i])!=1) {
		 printf("error while readin values to array");
 		 fclose(fp);
 	         return 1;
                }
              }
fclose(fp);

/*----------------------quick sort algorithm----------------------------------*/
 quicksort(arr,0,n-1);
 for(int i=0;i<n;i++) printf("%d\t",arr[i]);
 printf("\n");
 quicksortrandom(arr,0,n-1);
 for(int i=0;i<n;i++) printf("%d\t",arr[i]);
return 0;
}
