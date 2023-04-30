#include<stdio.h>
#include<string.h>
char res[1000][31];
char place[31];
int r=0;
char comment[31];
char id[20]="under construction";
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%[^:]s",place)!=EOF){//the scanf will scan until it reaches ':'
        getchar();//remove the ':'(optional)
        getchar();//remove the space after the ':'(optional)
        scanf("%[^\n,]s",comment);//the scanf will scan until it reaches '\n' or ','
        int len=strlen(comment);
        for(int i=0;i<len;i++){
            if(comment[i]<='Z'&&comment[i]>='A'){
                comment[i]+=32;
            }
        }
        char* pc = strstr(comment,id);
        if(pc!=NULL){
            int flag=1;
            for(int i=0;i<r;i++){
                if(strcmp(place,res[i])==0){
                    flag=0;
                    break;
                }
            }
            if(flag){
                strcpy(res[r++],place);
            }
        }
        char c = getchar();//remove the ',' or '\n'
        if(c==','){//if the previous char is ',', remove the space behind it
            getchar();
        }
    }
    for(int i=0;i<r;i++){
        printf("%s\n",res[i]);
    }
    return 0;
}
/*
you can check 
https://sites.google.com/site/9braised/fan-si/c1 
for more information about string scanning when using scanf
*/