#include <stdio.h>
int main() {
    char c[4];
    long int n;
    scanf("%s %ld",c,&n);
    n = n%26;
    for(int i=0;i<3;i++){
        c[i] += n;
        if(c[i]>'Z'){c[i]-=26;}
        if(c[i]<'A'){c[i]+=26;}
    }
    printf("%s\n",c);
    return 0;
}