//13591
#include<stdio.h>
int main(){
    int l;
    scanf("%d",&l);
    int max=0,max2=0;
    for(int i=0;i<l;i++){
        int a;
        scanf("%d",&a);
        if(a>=max){
            max2=max;max=a;
        }
        else if(a>max2){
            max2 = a;
        }
        if(i!=l-1)printf("%d ",max2);
        else printf("%d",max2);
    }
    printf("\n");
}