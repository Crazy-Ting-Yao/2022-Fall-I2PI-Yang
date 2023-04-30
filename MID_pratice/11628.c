#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    for(int p=0;p<t;p++){
        int n;
        scanf("%d",&n);
        char c[n][n+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                c[i][j]=' ';
            }
            c[i][n]='\0';
        }
        int dir=0;
        int x=0,y=-1;
        for(int i=n;i>0;i--){
            if(dir==0){
                for(int j=0;j<i;j++){
                    c[x][++y]='#';
                }
                dir++;
            }
            else if(dir==1){
                for(int j=0;j<i;j++){
                    c[++x][y]='#';
                }   
                dir++;             
            }
            else if(dir==2){
                for(int j=0;j<i;j++){
                    c[x][--y]='#';
                }   
                dir++;             
            }
            else if(dir==3){
                for(int j=0;j<i;j++){
                    c[--x][y]='#';
                }   
                dir=0;             
            }            
        }
        for(int i=0;i<n;i++){
            printf("%s\n",c[i]);
        }
    }
    return 0;
}