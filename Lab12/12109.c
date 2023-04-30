#include<stdio.h>
#include<string.h>
char input[502];
char command[1001];
int cursor=0;
int inputlen;
int main(){
    fgets(input,502,stdin);
    fgets(command,1001,stdin);
    inputlen = strlen(input);
    input[--inputlen]='\0';
    for(int i=0;command[i]!='\0';i++){
        i++;
        switch (command[i]){
        case 'b':
            if(!cursor) break;
            for(int j=cursor;j<=inputlen;j++){
                input[j-1] = input[j];
            }
            cursor--;
            inputlen--;
            break;
        case 'r':
            cursor++;
            if(cursor>inputlen) cursor = inputlen;
            break;
        }
    }
    printf("%s",input);
    return 0;
}