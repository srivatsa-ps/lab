#include<stdio.h>

int main(){
    int n; scanf("%d",&n); // cache size
    int m; scanf("%d",&m);// queue size

    int cache[10],queue[20];

    for(int i=0; i<n; i++) scanf("%d",&cache[i]);
    for(int i=0; i<m; i++) scanf("%d",&queue[i]);

    int cachesize=0;

    for(int i=0; i<m; i++){
        if(cachesize<n){
            int flag=0;
            for(int j=0; j<cachesize; j++){
                if(queue[i]==cache[j]) {flag=1; break;}
            }
            if(flag==0){
                cache[cachesize++]=queue[i];
            }
        }
        else{
            int flag=0;
            for(int j=0; j<n; j++){
                if(queue[i]==cache[j]) {flag=1; break;}
            }
            if(flag==0){
                int check[10]={0},fill=0;
                for(int k=i+1; k<m; k++){
                    if(fill==n-1) break;
                    else{
                        for(int j=0; j<n; j++){
                            if(cache[j]==queue[k]){
                                fill++;
                                check[j]=1;
                            }
                        }
                    }
                }
                int replace;
                for(replace=0; replace<n; replace++){
                    if(check[replace]==0) break;
                }
                cache[replace]=queue[i];
            }
        }
    }
}

1 2 2 3 4 2 3 1 3 4