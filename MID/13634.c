#include<stdio.h>
#include<string.h>
int main(){
    char c[10000];
    while(scanf("%[^\n]",c)!=EOF){
        getchar();
        int flag=1;
        int len = strlen(c);
        c[len] = '\0';
        int i=0;
        for(;c[i]==' ';i++){
            c[i] = ';';
        }
        if(c[len-1] == ';'){
            c[len-1]=0;
        }
        printf("%s\n",c);
        char r=getchar();
        while(r =='\n'){
            r = getchar();
            printf("\n");
        }
        ungetc(r,stdin);
    }
    printf("// surprise<3\n");
    return 0;
}
