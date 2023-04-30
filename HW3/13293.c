#include <stdio.h>
int main() {
    char c[10],m[5];
    scanf("%s",c);
    scanf("%s",m);
    for(int i=0;i<4;i++){
        if(m[i]>='1'&&m[i]<='9'){
            int num = m[i] - '0';
            printf("%c",c[num-1]);
        }
        else{
            for(int j=0;j<9;j++){
                if(m[i]==c[j]){
                    printf("%d",j+1);
                    break;
                }
            }
        }
    }
    return 0;
}