#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*****max function******/
int max(int a,int b){
return (a>b)?a:b;
}

/**********cut Rod problem using recursive method************/
int cutRodrecursively(int profit[],int n){
int i;
if(n==0)
	return 0;
int max_val=0;
for(i=1;i<=n;i++){
	max_val=max(max_val,profit[i-1]+cutRodrecursively(profit,n-i));
}
	return max_val;

}
/******cut rod problem using Dynamic programming********/
int cutRodusingdp(int profit[],int n){
int stored_val[n+1];
stored_val[0]=0;
int i,j;
for(i=1;i<=n;i++)
{
	int max_value=0;
	for(j=0;j<i;j++){
	max_value= max(max_value,profit[j]+stored_val[i-j-1]);
	}
	stored_val[i]=max_value;
}
return stored_val[n];
}

int main(int argc,char *argv[]){
	if(argc!=2){
		printf("enter the file name to read input\n");
		return 1;
	}
	FILE *fp=fopen(argv[1],"r");
	if(fp==NULL){
		printf("error while opening file\n");
		return 1;
	}
	int n;
	if(fscanf(fp,"%d\n",&n)!=1){
		printf("error while reading n value from the file\n");
		return 1;
	}
	int count=0;
      clock_t t,t1;
	//initializing the array block for storing profits for every cut value
	int *profit =(int *)malloc(n*sizeof(int));
	if(profit==NULL){
		printf("error while allocating memory to the profit array\n");
		return 1;
	}
	int read=0;
	while(count < n && fscanf(fp,"%d",&read)==1){
	profit[count]=read;
	count++;
	}
        printf("the values read from file are:\n");
       printf("n value is = %d\n",n);
 for(int i=0;i<n;i++) printf("%d \t ",profit[i]);
       
        t=clock(); //time calculation for recursive method
        int max_profit_recursively=cutRodrecursively(profit,n);
       printf("\n the maximum profit gained using recursive method is :%d",max_profit_recursively);	
       
       //recursuve method call and time calculation
       t=clock()-t;
       double time_taken1=((double)t)/CLOCKS_PER_SEC;
       printf("\nthe time taken by the recursive method :%f sec\n",time_taken1);
       //dynamic method call and time calculation
       t1=clock(); //time calculation starts here for dynamic programming
       int max_profit=cutRodusingdp(profit,n);
	printf("\nthe maximum profit gained using dynamic programming is : %d\n",max_profit);
t1=clock()-t1;
double time_taken=((double)t1)/CLOCKS_PER_SEC;
printf("the function where dynmaic programming is used takes :%f sec\n",time_taken);
}
