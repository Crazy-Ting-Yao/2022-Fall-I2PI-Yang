#include<stdio.h>
int calories[20];
int n,k;
int recursion(int cal,int ind){
    if(cal==k){
        return 1;
    }
    if(cal>k){
        return 0;
    }
    int flag=0 ;
    for(int i=ind+1;i<20;i++){
        int r = recursion(cal+calories[i],i);
        if(r){
            return 1;
        }
    }
    return 0;
}
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&calories[i]);
    }
    int res = recursion(0,-1);
    if(res){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}