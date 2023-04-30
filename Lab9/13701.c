#include<stdio.h>
int w[20];
int v[20];
int n;
int target;
int max=0;
void recursion(int index,int value,int weight){
    if(weight>target) return;
    if(max<value) max = value;
    for(int i=index+1;i<n;i++){
        recursion(i,value+v[i],weight+w[i]);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&w[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
    }
    scanf("%d",&target);
    recursion(-1,0,0);
    printf("%d\n",max);
    return 0;
}