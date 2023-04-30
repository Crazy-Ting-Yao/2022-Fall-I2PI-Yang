//13559
#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[100][100],b[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int deg;
    scanf("%d",&deg);
    if(deg==0){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                b[i][j] = a[i][j];
            }
        }
    }
    if(deg==90){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                b[i][j] = a[j][n-i-1];
            }
        }
    }
    if(deg==270){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                b[i][j] = a[n-1-j][i];
            }
        }
    }
    if(deg==180){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                b[i][j] = a[n-1-i][n-1-j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            printf("%d ",b[i][j]);
        }
        printf("%d\n",b[i][n-1]);
    }
    return 0;
}