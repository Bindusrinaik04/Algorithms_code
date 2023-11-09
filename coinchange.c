#include<stdio.h>
#include<stdlib.h>

void coinchange(int denom[],int amount,int denomn){
int i=0;
while(amount>0){
	int c=amount/denom[i];
	printf("use %d coins of %d\n",c,denom[i]);
	amount= amount-(c*denom[i]);
	i++;
	}

}

int main(int argc,char* argv[]){
if(argc<2){
	printf("enter the input file name");
	return 1;
}
FILE *fp=fopen(argv[1],"r");
if(fp==NULL){
printf("INvalid file name input\n");
return 1;
}

int denomn,amount;
if(fscanf(fp,"%d %d\n",&denomn,&amount)==0)
	{
		printf("error while reading the denomn,amount values from file");
		return 1;
	}
	
	
int count=0,read;
int *denom=(int *)malloc(denomn*sizeof(int));
while(fscanf(fp,"%d",&read)==1 && count<denomn){
	denom[count]=read;
	count++;
}
coinchange(denom,amount,denomn);


}
