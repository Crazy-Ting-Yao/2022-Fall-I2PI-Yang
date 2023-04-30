#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char** sentences;
void reverse(){
    int x;
    scanf("%d",&x);
    int len = strlen(sentences[--x]);
    for(int i=0;i<(len/2);i++){
        char temp = sentences[x][i];
        sentences[x][i] = sentences[x][len-i-1];
        sentences[x][len-i-1] = temp;
    }
}
void printing(){
    int x;
    scanf("%d",&x);
    printf("%s\n",sentences[--x]);
}
void append(){
    int x,y;
    scanf("%d %d",&x,&y);
    int lenx = strlen(sentences[--x]);
    int leny = strlen(sentences[--y]);
    if(lenx>leny){
        int len = lenx+leny;
        char* temp = malloc(sizeof(char)*(len+1));
        strcpy(temp,sentences[y]);
        strcat(temp,sentences[x]);
        free(sentences[y]);
        sentences[y] = temp;
    }
    else{
        int len = lenx+leny;
        char* temp = malloc(sizeof(char)*(len+1));
        strcpy(temp,sentences[x]);
        strcat(temp,sentences[y]);
        free(sentences[x]);
        sentences[x] = temp;
    }
}
void del(){
    char s[10002];
    scanf("%s",s);
    int x;
    scanf("%d",&x);
    char* token=strstr(sentences[--x],s);
    if(token!=NULL){
        int lenx = strlen(sentences[x]);
        int lens = strlen(s);
        for(int i=(token-(&sentences[x][0]));i<=lenx-lens;i++){
            sentences[x][i] = sentences[x][i+lens];
        }
    }
}
int main(){
    freopen("input.txt","r",stdin);
    int n,op;
    scanf("%d %d",&n,&op);
    sentences = (char**)malloc(sizeof(char*)*n);
    for(int i=0;i<n;i++){
        char s[100000];
        scanf("%s",s);
        int len = strlen(s);
        sentences[i] = (char*)malloc(sizeof(char)*(len+1));
        strcpy(sentences[i],s);
    }
    char opsentence[10];
    for(int i=0;i<op;i++){
        scanf("%s",opsentence);
        if(!strcmp(opsentence,"reverse")) reverse();
        else if(!strcmp(opsentence,"append")) append();
        else if(!strcmp(opsentence,"delete")) del();
        else if(!strcmp(opsentence,"print")) printing();
    }
    for(int i=0;i<n;i++) free(sentences[i]);
    free(sentences);
    return 0;
}