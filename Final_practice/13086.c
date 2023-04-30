#include<stdio.h>
#include<string.h>
char f[2][2001];
unsigned long long lenf[60];
unsigned long long lencount(int i){
    if(lenf[i]) return lenf[i];
    else lenf[i] = lencount(i-1)+lencount(i-2);
    return lenf[i];
}
char recursion(int n,unsigned long long * k){
    if(n==0){
        if((*k)<lenf[0]) return f[0][(*k)];
        else{
            (*k)-=lenf[0];
            return '\0';
        }
    }
    if(n==1){
        if((*k)<lenf[1]) return f[1][(*k)];
        else{
            (*k)-=lenf[1];
            return '\0';
        }
    }
    if((*k)<lenf[n-2]) return recursion(n-2,k);
    (*k) -= lenf[n-2];
    return recursion(n-1,k);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<60;i++) lenf[i]=0;
        scanf("%s",f[0]);
        scanf("%s",f[1]);
        lenf[0] = strlen(f[0]);
        lenf[1] = strlen(f[1]);
        int n;
        unsigned long long k;
        lencount(59);
        scanf("%d %llu",&n,&k);
        printf("%c\n",recursion(n,&k));
    }
    return 0;
}