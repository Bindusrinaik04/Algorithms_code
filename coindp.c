#include<stdio.h>
#define MAX 100

int min(int a,int b){
return (a>b)?b:a;
}

int coinchange(int coins[],int n,int amount){

if(amount ==0 || n==0)
return 0;

int table[n+1][amount+1];
for(int i=0;i<=amount;i++) table[0][i]=0;
for(int i=0;i<=n;i++) table[i][0]=0;
for(int i=1;i<=n;i++){
for(int j=1;j<=amount;j++)
 table[i][j]=MAX;
}
for(int i=1;i<=n;i++)
{
for(int j=1;j<=amount;j++){
 if(coins[i]>j) table[i-1][j];
 else{
 table[i][j]=min(table[i-1][j],1+table[i][j-coins[i-1]]);
 }
}
}
for(int i=0;i<=n;i++){
for(int j=0;j<=amount;j++)
printf("%d ",table[i][j]);
printf("\n");
}
 return 1;
}

int main(int argc,char* argv[]){

if(argc<2){
printf("enter file name for input \n");
return 1;
}
FILE *fp=fopen(argv[1],"r");

if(fp==NULL){
printf("the file does not exists\n");
return 1;
}
int n,amount;
if(fscanf(fp,"%d %d\n",&n,&amount)==0){
printf("error while reading input\n");
return 1;
}
int coins[n];
int count=0,read;
while(count<n && fscanf(fp,"%d",&read) !=0){
coins[count]=read;
count++;
}
int minCoins=coinchange(coins,n,amount);
printf("%d is the minimum required amount of coins for %d",minCoins,amount);
return 0;
}
