//12893
#include <stdio.h>
int main(){
    int N;
    scanf("%d",&N);
    int a[200],b[200];
    scanf("%d %d %d",&a[0],&a[1],&a[2]);
    b[0] = a[1] - a[0];
    b[1] = a[2] - a[1];
    int d = b[1] - b[0];
    for(int i=3;i<N;i++){
        b[i-1] = b[i-2]+d;
        a[i] = b[i-1] + a[i-1];
    }
    for(int i=0;i<N-1;i++){
        printf("%d ",a[i]);
    }
    printf("%d\n",a[N-1]);
}