//12434
#include<stdio.h>
void pollute(char a[101][101],int ver,int hor){
    char temp[101][101];
    for (int i=0;i<ver;i++){
        for(int j=0;j<hor;j++){
            temp[i][j]=a[i][j];
        }
    }
    for (int i=0;i<ver;i++){
        for(int j=0;j<hor;j++){
            if(temp[i][j]=='F'){
                if(i!=0&&a[i-1][j]!='#'){
                    a[i-1][j]='F';
                }
                if(j!=0&&a[i][j-1]!='#'){
                    a[i][j-1]='F';
                }
                if(i!=ver-1&&a[i+1][j]!='#'){
                    a[i+1][j]='F';
                }
                if(j!=hor-1&&a[i][j+1]!='#'){
                    a[i][j+1]='F';
                }
            }
        }
    }
    return;
}
int main(){
    int v,h,t;
    scanf("%d %d %d",&v,&h,&t);
    char c[101][101];
    for(int i=0;i<v;i++){
        scanf("%s",c[i]);
    }
    for(int i=0;i<t;i++){
        pollute(c,v,h);
    }
    for(int i=0;i<v;i++){
        printf("%s\n",c[i]);
    }
    return 0;
}