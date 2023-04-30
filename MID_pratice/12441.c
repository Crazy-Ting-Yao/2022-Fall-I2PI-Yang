#include<stdio.h>
#include<string.h>
int main(){
    char c[100001];
    while(scanf("%s",c)!=EOF){
        int len=strlen(c);
        int flag=1;
        int k=len/2;
        for(int i=0;i<k;i++){
            if(c[i]!=c[len-i-1]){
                printf("No\n");
                flag=0;
                break;
            }
        }
        if(flag){printf("Yes\n");}
    }
    return 0;
}