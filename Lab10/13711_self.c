#include<stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        char s[506];
        scanf("%s",s);
        int index=-1,counter=0;
        while(s[++index]!='\0'){
            if(s[index]=='(') counter++;
            else{
                counter--;
                if(counter<0) break;
            }
        }
        if(counter!=0) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}