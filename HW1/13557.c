#include<stdio.h>
int main(){
    unsigned int p;
    int a[4];
    int b[]={1,5,10,50};
    int count=0;
    scanf("%d %d %d %d %d",&p,&a[0],&a[1],&a[2],&a[3]);
    for(int i=3;i>=0;i--){
        int r;
        r = p/b[i];
        if(r>a[i]){
            count += a[i];
            p -= b[i]*a[i];
        }
        else{
            count += r;
            p -= b[i]*r;
        }
    }
    if(p){
        printf("-1\n");
        return 0;
    }
    printf("%d\n",count);   
}