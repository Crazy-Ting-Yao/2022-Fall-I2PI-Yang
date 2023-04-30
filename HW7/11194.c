#include<stdio.h>
int recur(int a){
    if(a==2) return 2;
    else if(a==1) return 1;
    else return recur(a-2)+recur(a-1);
}
int main(){
    int T;
    scanf("%d",&T);
    while (T--){
        int a;
        scanf("%d",&a);
        printf("%d\n",recur(a));
    }
    
}