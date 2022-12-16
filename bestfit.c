#include<stdio.h>
#include<stdlib.h>
void bestfit(int b,int block[10],int n,int p[10]){
  int allocation[10];
  for(int i=0;i<n;i++){
    allocation[i]=-1;
  }
  int bestidx;
  for(int i=0;i<n;i++){
    bestidx=-1;
    for(int j=0;j<b;j++){
      if(block[j]>=p[i]){
        if(bestidx==-1){
          bestidx=j;
        }
        else if(block[bestidx]>block[j]){
          bestidx=j;
        }
      }
    }
    if(bestidx!=-1){
      allocation[i]=bestidx;
      block[bestidx]-=p[i];
    }
  }
  printf("\nprocessNo.\tprocess size\tblockNo.\n");
  for(int i=0;i<n;i++){
    printf("%i\t\t\t",i+1);
    printf("%i\t\t\t",p[i]);
    if(allocation[i]!=-1){
      printf("%i",allocation[i]+1);
    }
    else{
      printf("Not allocated!");
    }
    printf("\n");
  }
}
int main(){
  int n,b,block[10],p[10];
  printf("Enter the number of blocks:");
  scanf("%d",&b);
  for(int i=0;i<b;i++){
    printf("Enter size of block%d:",i+1);
    scanf("%d",&block[i]);
  }
  printf("Enter the number of processes:");
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    printf("Enter size of process%d:",i+1);
    scanf("%d",&p[i]);
  }
  bestfit(b,block,n,p);
  return 0;
}