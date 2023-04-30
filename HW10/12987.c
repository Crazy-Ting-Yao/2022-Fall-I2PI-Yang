#include<stdio.h>
#include<string.h>
char string[21];
char hash[21];
char res[20][21];
int len1,len2;
int success=0;
void check(int index1,int index2,int b,int pos){
    if(index1==len1){
        if(index2>len2-1){
            success=1;
            for(int i=0;i<b-1;i++){
                printf("%s ",res[i]);
            }
            printf("%s\n",res[b-1]);
        }
        return;
    }
    if(index2>=len2) return;
    if(hash[index2]=='#'){
        res[b][pos++]=string[index1];
        res[b][pos]='\0';
        check(index1+1,index2+1,b+1,0);
        check(index1+1,index2,b,pos);
    }
    else{
        if(hash[index2]!=string[index1]){
            return;
        }
        else{
            check(index1+1,index2+1,b,0);
        }
    }
    return;
}
int main(){
    int temp=0;
    scanf("%s",string);
    len1=strlen(string);
    scanf("%s",hash);
    len2=strlen(hash);
    check(0,0,0,0);
    if(!success){
        printf("What the hack!?\n");
    }
    return 0;
}