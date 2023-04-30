#include<stdio.h>
#define int long long int
int a,b,c,d;
int f(int i);
int g(int i);
int main(){
    int n;
    scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&n);
    printf("%lld %lld\n",f(n),g(n));
    return 0;
}
int f(int i){
    if(i==0) return a;
    if(i==1) return b;
    if((i%2)==0){
        return f(i-1)+g(i/2);
    }
    else{
        return f(i-1)+g(i-2);
    }
}
int g(int i){
    if(i==0) return c;
    if(i==1) return d;
    if((i%3)==0){
        return g(i-1)+f(i/3);
    }
    else{
        return g(i-1)+f(i-2);
    }
}