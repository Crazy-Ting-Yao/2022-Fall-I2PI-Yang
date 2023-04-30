//11146 
#include<stdio.h>
#include<stdlib.h>
int main(){
    int r,c;
    scanf("%d %d",&r,&c);
    int arr[10][10];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int max=arr[0][0],min=arr[0][0];
    int maxlo[2]={0}, minlo[2]={0};
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j]>max){
                max = arr[i][j];
                maxlo[0]=i;
                maxlo[1]=j;
            }
            else if(arr[i][j]<min){
                min = arr[i][j];
                minlo[0]=i;
                minlo[1]=j;
            }
        }
    }
    int res1 = abs(maxlo[0]-minlo[0])+abs(maxlo[1]-minlo[1]);
    int res2 = max-min;
    printf("%d %d",res1,res2);
    return 0;
}