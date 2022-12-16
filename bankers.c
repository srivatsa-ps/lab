#include<stdio.h>
void main(){
    int available[100],max[20][100],need[20][100],allocation[20][100],flag,finish[20];
    int i,n,t,j,safe[20],k=0;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("Enter number of resources: ");
    scanf("%d",&t);
    printf("Enter availability of each resource: ");
    for(i=0;i<t;i++){
        scanf("%d",&available[i]);
    }
    safe[n];
    printf("Enter maximum number of each resource required by(max matrix) \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<t;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter maximum number of allocation to resource requestes by each process(allocation matrix) \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<t;j++)
        {
           scanf("%d",&allocation[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<t;j++)
        {
           need[i][j]=max[i][j]-allocation[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        finish[i]=0;
    }
    for(int x = 0;x<n;x++)
    {
    for(i=0;i<n;i++)
    {
        for(j = 0;j<t;j++)
        {
            if(finish[i]==0)
            {
                if (need[i][j]<=available[j])
                {
                    flag=0;
                }  
                else
                {
                    flag=1;
                    break;
                }
            }
            else
            {
                flag=1;
            }
        }
        if(flag==0)
        {
            finish[i]=1;
            safe[k++]=i;
            for(j=0;j<t;j++)
            {
                available[j]+=allocation[i][j];
            }
        }
    }
    }
    if(k==n){
    printf("Safe Sequence is:\n");
    for(i=0;i<n;i++)
    {
        printf("P%d ",safe[i]);
        
    }
    }
    else
    {
        printf("Not in safe state");
    }
    
}