#include<stdio.h>
unsigned long long int fres[81];
unsigned long long int gres[81];
int a,b,c,d;
unsigned long long int f(int i);
unsigned long long int g(int i);
int main(){
    for(int i=0;i<81;i++){
        fres[i]=0;
        gres[i]=0;
    }
    int n;
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&n);
    printf("%llu %llu\n",f(n),g(n));
    return 0;
}
unsigned long long int f(int i){
    if(fres[i]){
        return fres[i];
    }
    if(i==0){
        return a;
    }
    if(i==1){
        return b;
    }
    unsigned long long int res;
    if((i%3)==0){
        res = f(i-1)+g((f(i/3))%i);
    }
    else{
        res = f(i-1)+g(i-2);
    }
    fres[i] = res;
    return res;
}
unsigned long long int g(int i){
    if(gres[i]){
        return gres[i];
    }
    if(i==0){
        return c;
    }
    if(i==1){
        return d;
    }
    unsigned long long int res;
    if((i%5)==0){
        res = g(i-1)+f((g(i/5))%i);
    }
    else{
        res = g(i-1)+f(i-2);
    }
    gres[i] = res;
    return res;
}