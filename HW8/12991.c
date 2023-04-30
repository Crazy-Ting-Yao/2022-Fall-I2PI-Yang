#include<stdio.h>
#include<stdlib.h>
short occupied[15];
short c[15];
int h[15];
int size;
int S,T;
int jumps;
int max=0;
void recursion(int pos,int num,int times){
    if(pos==T){
        if(max<num){
            max = num;
            jumps = times;
        }
        return;
    }
    for(int i=0;i<size;i++){
        if(c[i]==c[pos]||i==pos-1||i==pos+1){
            if(occupied[i]){
                occupied[i]=0;
                int add = abs((i-pos)*(h[i]-h[pos]));
                recursion(i,num+add,times+1);
                occupied[i]=1;
            }
        }
    }
    return;
}
int main(){
    scanf("%d %d %d",&size,&S,&T);
    S--;
    T--;
    for(int i=0;i<size;i++){
        scanf("%d",&h[i]);
        occupied[i]=1;
    }
    for(int i=0;i<size;i++){
        scanf("%hd",&c[i]);
    }
    occupied[S]=0;
    recursion(S,0,0);
    printf("%llu %d\n",max,jumps);
    return 0;
}