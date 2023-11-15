#include<stdio.h>
#include<stdlib.h>

#define MAXI 1000

float sum(float freq[],int row,int col){
int s=0;
float val=0;
for(s=row;s<=col;s++)
{
 val+=freq[s];
}
return val;
}

float optimalbinary(float freq[],int n){

	float cost[n][n];
	int root[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		
		if(i==j) {
			cost[i][i]=freq[i];
			root[i][i]=i+1;
		}
		else { cost[i][j]=0;
			root[i][j]=0;
		     }
		}
	}
	
	int len,row;
	for(len=2;len<=n;len++){
	//len =2,3,...n
	for(row=0;row<n-len+1;row++){
	 int col=row+len-1;
	float val=sum(freq,row,col);
	cost[row][col]= MAXI;
        int k;
	for(k=row;k<=col;k++){
		float c = ( (k > row) ? cost[row][k-1]:0)+ ( (k < col) ? cost[k+1][col]:0) + val;
	if(c < cost[row][col]) {
		cost[row][col]=c;
		//cost[col][row]=0;
		root[row][col]=k+1;
		//root[col][row]=0;
	}
	}
	}
	}
	
	printf("\nroot table:\n");
	for(int i=0;i<n;i++)
	      {	for(int j=0;j<n;j++)
			printf("%d \t ",root[i][j]);
              printf("\n");
	      }
	printf("cost table:\n");
	for(int i=0;i<n;i++)
	      {	for(int j=0;j<n;j++)
			printf("%.2f \t ",cost[i][j]);
              printf("\n");
	      }

	return cost[0][n-1];
}

int main(int argc ,char* argv[]){
	if(argc<2)
	{
		printf("give the input file name\n");
		return 0;
	}
	FILE* fp = fopen(argv[1],"r");
	if(fp==NULL){
		printf("error in opening file\n");
		return 0;
	}
	int n;
	if(fscanf(fp,"%d\n",&n)!=1){
		printf("error while reading n value from the file\n");
		return 0;
	}
	float *freq=(float*)malloc(n*sizeof(float));
	if(freq==NULL){
		printf("error while allocating the memory using malloc()\n");
		return 0;
	}
	float read=0;int count=0;
	while(count<n && fscanf(fp,"%f",&read)==1){
		freq[count]=read;
		count++;
	}
	printf("the values read from the file are:\n");
	for(int i=0;i<n;i++) printf("%.2f\t",freq[i]);
        float min_comp_cost=optimalbinary(freq,n);
	printf("\n %.2f is the minimum search cost\n",min_comp_cost);
	return 0;
}

