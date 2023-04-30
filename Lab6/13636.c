#include<stdio.h>
#include<string.h>
void output(char a,int num){
    switch(num){
        case 2:
            printf("Two");
            break;
        case 3:
            printf("Three");
            break;
        case 4:
            printf("Four");
            break;
        case 5:
            printf("Five");
            break;
        case 6:
            printf("Six");
            break;
        case 7:
            printf("Seven");
            break;
        case 8:
            printf("Eight");
            break;
        case 9:
            printf("Nine");
            break;
    }
    switch(a){
        case '0':
            printf("Zero");
            break;            
        case '1':
            printf("One");
            break;
        case '2':
            printf("Two");
            break;
        case '3':
            printf("Three");
            break;
        case '4':
            printf("Four");
            break;
        case '5':
            printf("Five");
            break;
        case '6':
            printf("Six");
            break;
        case '7':
            printf("Seven");
            break;
        case '8':
            printf("Eight");
            break;
        case '9':
            printf("Nine");
            break;
    }
    return;    
}
int main(){
    char c[1001];
    scanf("%[^\n]",c);
    int len = strlen(c);
    int num=1;
    char n=c[0];
    for(int i=1;i<len;i++){
        if(c[i]==' '){
            continue;
        }
        if(c[i]==n){
            num++;
        }
        else{
            output(n,num);
            n = c[i];
            num=1;
        }
    }
    output(n,num);
    printf("\n");
}