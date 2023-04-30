//13309
#include<stdio.h>
#include<string.h>
int main(){
    short alph[26]={0};
    char value[27];
    char zero[2]={'0','\0'};
    char end[4]={'e','n','d','\0'};
    scanf("%s",value);
    int vlen=strlen(value);
    for(int i=0;i<vlen;i++){
        alph[value[i]-'a']=i+1;
    }
    char c[101];
    char ch;
    getchar();
    while(1){
        int index=0;
        while(1){
            ch = getchar();
            if(ch=='\n')break;
            c[index]=ch;
            index++;
        }
        c[index]='\0';
        if(strcmp(c,zero)==0){
            return 0;
        }
        if(strcmp(c,end)==0){
            return 0;
        }
        int counter=0;
        for(int i=0;i<index;i++){
            if(c[i]>='a'&&c[i]<='z'){
                counter+=alph[c[i]-'a'];
            }
        }
        printf("%d\n",counter);
    }
}