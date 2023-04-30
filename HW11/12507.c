#include<stdio.h>
#include<string.h>
char data[10000000];
char tmp[10000000];
int main(){
    //freopen("input.txt","r",stdin);
    int res=0;
    char k[21];
    char space[13]=" \n-/:()[],.";
    char *token;
    scanf("%s",k);
    getchar();
    while(fgets(tmp,10000000,stdin)!=NULL){
        int len = strlen(data);
        data[len++]=' ';
        data[len]='\0';
        strcat(data,tmp);
    }
    for(int i=0;data[i]!='\0';i++){
        if(isupper(data[i])) data[i]+=32;
    }
    for(int i=0;k[i]!='\0';i++){
        if(isupper(k[i])) k[i]+=32;
    }
    token = strtok(data,space);
    while(token!=NULL){
        if(!strcmp(token,k)) res++;
        token = strtok(NULL,space);
    }
    printf("%d\n",res);
    return 0;
}
