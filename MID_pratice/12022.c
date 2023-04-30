#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int e[n+1];
    int d10=n/1000+1;
    int e10[d10];
    int temp=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&e[i]);
        temp+=e[i];
        if(i%1000==0){
            e10[i/1000]=temp;
            temp=0;
        }
    }
    int times;
    scanf("%d",&times);
    for(int i=0;i<times;i++){
        int s,end;
        scanf("%d %d",&s,&end);
        long long int counter=0;
        if(end-s<=1000){
            for(int j=s;j<=end;j++){
                counter+=e[j];
            }
            printf("%lld\n",counter);
            continue;
        }
        for(int j=(s-1)/1000+2;j<=end/1000;j++){
            counter+=e10[j];
        }
        int r=((s-1)/1000+1)*1000;
        for(int j=s;j<=r;j++){
            counter+=e[j];
        }
        for(int j=(end/1000)*1000+1;j<=end;j++){
            counter+=e[j];
        }
        printf("%lld\n",counter);
    }
    return 0;
}