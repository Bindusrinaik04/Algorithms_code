#include<stdio.h>
#include<stdlib.h>
 
#define MINIMUM 0

//max utility function
int max(int a,int b) 
{
 return (a>b)?a:b;
 }
 
 /**** using dynamic programing****/
 int cutRod(int price[],int n)
 {
  int val[n+1]; //val stores the maximum profits obtained by cutting the rod,rod[n] is the final answer
  val[0]=0;
  int i,j;
  
  for(i=1;i<=n;i++) {
  int max_value = MINIMUM;
  for(j=0;j<i;j++){
  max_value = max(max_value,price[j]+val[i-j-1]);
  }
  val[i]=max_value;
  }
  
  return val[n];
  }

int main(int argc ,char *argv[])
 {
 if(argc<2)
 { 
  printf("enter the input file name\n");
  return 1;
  }
  
  FILE *fp=fopen(argv[1],"r");
  if(fp==NULL){
  printf("error in opening file\n");
  return 1;
  }
 int n;
 if(fscanf(fp,"%d\n",&n) !=1) {
  printf("unable to read the n value from the file\n");
  fclose(fp);
  return 1;
  }
  
  int *price = (int *)malloc(n*sizeof(int));
  if(price==NULL){
   printf("memory allocation failed\n");
   fclose(fp);
   return 1;
   }
   
   int count=0;
   int read;
   while(count < n && fscanf(fp,"%d",&read)==1){
    price[count]=read;
    count++;
    }
    int i;
    printf("total number of elements:%d \n",n);
    for(i=0;i<n;i++)
    printf("%d\t",price[i]);
   
    int max_value=cutRod(price,n);
    printf("\nmaximum value obtained using dp = %d\n",max_value);
}
