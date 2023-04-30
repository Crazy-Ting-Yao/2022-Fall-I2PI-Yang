#include<stdio.h>
#include<math.h>
char c[4096][4096];
int countsize(int n){
    return (4 * pow(2,n-1));
}
void altering(int i,int j,int posx,int posy,int s){
    c[i+posx][j+posy]='#';
    c[j+posx][i+posy]='#';
    c[(s-i)+posx-1][(s-j)+posy-1]='#';
    c[(s-j)+posx-1][(s-i)+posy-1]='#';
}
void fun(int n,int posx,int posy){
    if(n==1){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(((i==0)||(i==3))&&((j==0)||(j==3))){
                    continue;
                }
                else{
                    c[posx+i][posy+j]='#';
                }
            }
        }
        return;
    }
    int s = countsize(n);
    int smallers = countsize(n-1);
    if((n%2)==0){
        fun(n-1,posx,posy);
        fun(n-1,posx+(s/2),posy);
        fun(n-1,posx,posy+(s/2));
        fun(n-1,posx+(s/2),posy+(s/2));
    }
    else{
        int r = (s-smallers)/2;
        fun(n-1,posx+r,posy+r);
        for(int i=r;i<r+(smallers/4);i++){
            for(int j=0;j<r;j++){
                altering(i,j,posx,posy,s);
            } 
        }
        for(int i=r+(3*smallers/4);i<r+smallers;i++){
            for(int j=0;j<r;j++){
                altering(i,j,posx,posy,s);
            } 
        }
        for(int i=r+(smallers/4);i<r+(3*smallers/4);i++){
            for(int j=r/2;j<r;j++){
                altering(i,j,posx,posy,s);
            } 
        }        
    }
    return;
}
int main(){
    int n;
    scanf("%d",&n);
    int size = countsize(n);
    fun(n,0,0);
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(c[i][j]=='#'){
                printf("#");
            }
            else{
                printf(".");
            }
        }
        printf("\n");
    }
}