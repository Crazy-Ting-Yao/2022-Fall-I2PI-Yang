#include<stdio.h>
#include<string.h>
#define MAX_SIZE 500
char content[MAX_SIZE];
char input[MAX_SIZE];
int main(){
    fgets(input, MAX_SIZE, stdin);
    int cur=0;
    int input_len = strlen(input);
    for(int i=0;i<input_len;i++){
        char temp[501];
        int len=strlen(content);
        if(input[i]=='/'){
            switch (input[i+1]){
            case 'b':
                if(cur==0){
                    i+=9;
                    break;
                }
                for(int i=cur;i<=len;i++){
                    temp[i-cur] = content[i];
                }
                content[--cur]='\0';
                strcat(content,temp);
                i+=9;
                break;
            case 'n':
                for(int i=cur;i<=len;i++){
                    temp[i-cur] = content[i];
                }
                content[cur++]='\n';
                strcat(content,temp);
                i+=7;
                break;
            case 'l':
                if(cur==0){
                    i+=4;
                    break;
                }
                cur--;
                i+=4;
                break;
            case 'r':
                if(cur==strlen(content)){
                    i+=5;
                    break;
                }
                cur++;
                i+=5;
                break;
            }
        }
        else{
            for(int i=cur;i<=len;i++){
                temp[i-cur] = content[i];
            }
            content[cur++]=input[i];
            content[cur]='\0';
            strcat(content,temp);
        }
    }
    printf("%s", content);
    return 0;
}