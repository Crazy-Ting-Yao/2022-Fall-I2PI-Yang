#include <stdio.h>
void swap(int a[], int r1, int r2,int N){
    for(int i=0;i<N;i++){
        if(a[i]==r1){r1=i;break;}
    }
    for(int i=0;i<N;i++){
        if(a[i]==r2){r2=i;break;}
    }
    int temp=a[r1];
    a[r1] = a[r2];
    a[r2] = temp;
    return;
}
int main() {
    int N,M;
    scanf("%d %d",&N,&M);
    int arr[1001];
    for(int i=0;i<N;i++){
        arr[i] = i+1;
    }
    for(int i=0;i<M;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        swap(arr,a,b,N);
    }
    for(int i=0;i<N;i++){
        printf("%d",arr[i]);
        if(i!=N-1)printf(" ");
    }
    printf("\n");
}