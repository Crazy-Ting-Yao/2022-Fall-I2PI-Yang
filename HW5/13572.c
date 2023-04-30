//13573
#include<stdio.h>
#include<string.h>
int main(){
    char c[1000001],alph[26];
    for(int i=0;i<26;i++){
        alph[i]='a'+i;
    }
    scanf("%s",c);
    int len=strlen(c);
    int num;
    scanf("%d",&num);
    char r,t;
    short ty;
    int index;
    for(int i=0;i<num;i++){
        scanf("%hd",&ty);
        if(ty==1){
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
        else if(ty==2){
            scanf("%d %c",&index,&t);
            int flag=1;
            for(int j=0;j<26;j++){
                if(alph[j]==t){
                    c[index]=j+'a';
                    flag=0;
                    break;
                }
            }
            if(flag){
                for(int k=0;k<len;k++){
                    c[k]=alph[c[k]-'a'];
                }
                c[index]=t;
                for(int i=0;i<26;i++){
                    alph[i]='a'+i;
                }
            }
        }
    }
    for(int i=0;i<len;i++){
        printf("%c",alph[c[i]-'a']);
    }
    printf("\n");
    return 0;
}