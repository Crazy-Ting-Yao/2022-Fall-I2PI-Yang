//13613
#include<stdio.h>
int main(){
    int a[100][100],b[100][100];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
            b[i][j]=a[i][j];
        }
    }
    int size,deg;
    scanf("%d %d",&size,&deg);
    deg%=360;
    int max=a[0][0],index_x=0,index_y=0;
    for(int i=0;i<=n-size;i++){
        for(int j=0;j<=n-size;j++){
            if(max<a[i][j]){
                max = a[i][j];
                index_x = i;
                index_y = j;
            }
        }
    }
    if(deg==90){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                b[i+index_x][j+index_y] = a[j+index_x][size-i-1+index_y];
            }
        }
    }
    if(deg==270){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                b[i+index_x][j+index_y] = a[size-1-j+index_x][i+index_y];
            }
        }
    }
    if(deg==180){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                b[i+index_x][j+index_y] = a[size-1-i+index_x][size-1-j+index_y];
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