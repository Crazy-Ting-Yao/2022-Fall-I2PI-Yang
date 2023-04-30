#include<stdio.h>
#include<string.h>
int main(){
    char c[100000];
    while(scanf("%[^\n]",c)!=EOF){
        getchar();
        if(c[0]=='#'){
            printf("%s\n",c);
            continue;
        }
        int len=strlen(c);
        int i=0;
        for(;c[i]==';';i++){
            c[i]=' ';
        }
        if(c[len-1]=='{'){
            printf("%s\n",c);
        }
        else if((c[i]=='}')&&(i==len-1)){
            printf("%s\n",c);
        }
        else{
            printf("%s;\n",c);
        }
    }
    return 0;
}