#include<stdio.h>
#include<time.h>
/***Recursive solution****/

int fib(int a){
if(a==0 || a==1)
return a;

else
return fib(a-1)+fib(a-2);

}

/*******Dynamic ptogramming solution**********/
int fibd(int a){
int f[a];
int i;

f[0]=0;
f[1]=1;
for(i=2;i<=a;i++) f[i]=f[i-1]+f[i-2];

return f[a];
}

int main(int argc,char* argv[]){

 
if(argc<2){
printf("give the input fi;e name");
return 1;
}

FILE *fp=fopen(argv[1],"r");

if(fp==NULL) {
printf("file doesnot exists");
return 1;
}

int n;

if(fscanf(fp,"%d",&n)==0)
{	printf("error while reading number");
	 return 1;
 }
 
 clock_t start = clock();
 int rn=fib(n);
 clock_t end = clock();
 
double t;
t = (double)( end-start )/CLOCKS_PER_SEC;
printf(" time taken by the recusive method: %f sec\n",t);

clock_t start1=clock();
int rd=fibd(n);
clock_t end1=clock();
 
double td;
td = (double)(end1-start1)/CLOCKS_PER_SEC;
printf("time taken by the dp:%.3f\n",td);

 printf("%d is the result of naive method\n",rn);
 
 printf("%d is the result of dynmamic method",rd);

 return 0;
 }

