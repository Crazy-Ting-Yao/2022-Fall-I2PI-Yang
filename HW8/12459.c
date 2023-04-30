#include<stdio.h>
unsigned long long int a=0;
void Sierpinski(int n){
    if(n==0) return;
    a+=1;
    if(n==1) return;
    for(int i=0;i<8;i++){
        Sierpinski(n-1);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    Sierpinski(n);
    printf("%llu\n",a);
    return 0;
}