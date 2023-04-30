#include<stdio.h>
short check(short a[15][15],short x,short y,short color){
    short flag=0;
    for(short i=-4;i<=4;i++){
        if(x+i>=0){
            if(x+i==15){
                break;
            }
            else if(a[x+i][y]==color){
                flag++;
                if(flag==5)break;
            }
            else{
                flag=0;
            }
        }
    }
    if(flag==5){return 1;}
    flag=0;
    for(short i=-4;i<=4;i++){
        if(y+i>=0){
            if(y+i==15){
                break;
            }
            else if(a[x][y+i]==color){
                if(++flag==5)break;
            }
            else{
                flag=0;
            }
        }
    }
    if(flag==5){return 1;}    
    flag=0;
    for(short i=-4;i<=4;i++){
        if(y+i>=0&&x+i>=0){
            if(y+i>=15||x+i>=15){
                break;
            }
            else if(a[x+i][y+i]==color){
                if(++flag==5)break;
            }
            else{
                flag=0;
            }
        }
    }
    if(flag==5){return 1;} 
    flag=0;
    for(short i=-4;i<=4;i++){
        if(y-i<15&&x+i>=0){
            if(y-i<0||x+i>=15){
                break;
            }
            else if(a[x+i][y-i]==color){
                if(++flag==5)break;
            }
            else{
                flag=0;
            }
        }
    }
    if(flag==5){return 1;}   
    return 0;
}
int main(){
    short times,color;
    scanf("%hd",&times);
    short arr[15][15];
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            arr[i][j]=0;
        }
    }
    for(short i=1;i<=times;i++){
        short x,y;
        scanf("%hd %hd",&x,&y);
        if((i%2)==1){
            color=1;
        }
        else {
            color=-1;
        }
        arr[x-1][y-1]=color;
        if(check(arr,x-1,y-1,color)){
            if(color==1){
                printf("LSC wins at the %hdth step.\n",i);
                return 0;
            }
            else{
                printf("TSC wins at the %hdth step.\n",i);
                return 0;
            }
        }
    }
    printf("There's no winner.\n");
    return 0;
}