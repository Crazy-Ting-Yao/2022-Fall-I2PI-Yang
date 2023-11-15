//13572
#include<stdio.h>
#include<string.h>
int main(){
    char c[1000001],alph[26];
    for(int i=0;i<26;i++){
        alph[i]='a'+i;
    }
    scanf("%s",c);
    int num;
    scanf("%d",&num);
    char r,t;
    for(int i=0;i<num;i++){
        getchar(); 
        r = getchar();
        getchar();
        t = getchar();
        for(int j=0;j<26;j++){
            if(alph[j]==r){
                alph[j]=t;
            }
        } 
    }
    int len=strlen(c);
    for(int i=0;i<len;i++){
        printf("%c",alph[c[i]-'a']);
    }
    printf("\n");
    return 0;
}
