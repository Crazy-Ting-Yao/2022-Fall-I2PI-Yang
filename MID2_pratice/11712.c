#include<stdio.h>
#include<string.h>
char res[1000];
int ind;
char map[26][5]={"*_","_***","_*_*","_**","*","**_*","__*","****","**","*___","_*_","*_**","__","_*","___","*__*","__*_","*_*","***","_","**_","***_","*__","_**_","_*__","__**"};
void translate(char c[]){
    for(int i=0;i<26;i++){
        if(strcmp(map[i],c)==0){
            res[ind++]=i+'A';
            return;
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    char c[1001];
    char tmp[30];
    scanf("%s",c);
    //n=strlen(c);
    int scanindex=0;
    for(int i=0;i<n;i++){
        if(c[i]=='='){
            if(i<=n-3&&c[i+1]=='='&&c[i+2]=='='){
                tmp[scanindex++]='_';
                i+=2;
            }
            else{
                tmp[scanindex++]='*';
            }
            continue;
        }
        else if(c[i]=='.'){
            if(i<=n-6&&c[i+1]=='.'&&c[i+2]=='.'&&c[i+3]=='.'&&c[i+4]=='.'&&c[i+5]=='.'){
                tmp[scanindex]='\0';
                translate(tmp);
                res[ind++]=' ';
                tmp[0]='\0';
                scanindex=0;
                i+=5;
            }
            else if(i<=n-3&&c[i+1]=='.'&&c[i+2]=='.'){
                tmp[scanindex]='\0';
                translate(tmp);
                tmp[0]='\0';
                scanindex=0;
                i+=2;
            }
        }
    }
    tmp[scanindex]='\0';
    translate(tmp);
    res[ind++]='\0';
    printf("%s\n",res);
    return 0;
}