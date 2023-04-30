//13606
#include<stdio.h>
int main(){
    int x[3000],y[3000],r[3000];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&x[i],&y[i],&r[i]);
    }
    for(int i=0;i<n;i++){
        int flag=0;
        for(int j=0;j<n;j++){
            if(i==j)continue;
            long int dis = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
            long int rsquared = (r[i]+r[j])*(r[i]+r[j]);
            if(dis<rsquared){
                flag=1;break;
            }
        }
        if(i!=n-1){
            printf("%d ",flag);
        }
        else{
            printf("%d\n",flag);
            return 0;
        }
    }
}