#include<stdio.h>
int r,c;
short finalx,finaly;
short map[501][501];
short path[30000][3];
int largest;
int BFS(int index){
    short x=path[index][1],y=path[index][2];
    if(x==finalx&&y==finaly){
        return path[index][0];
    }
    if(x>0){
        if(map[x-1][y]){
            largest++;
            path[largest][0] = path[index][0]+1;
            path[largest][1] = x-1;
            path[largest][2] = y;
            map[x-1][y]=0;
        }
    }
    if(y>0){
        if(map[x][y-1]){
            largest++;
            path[largest][0] = path[index][0]+1;
            path[largest][1] = x;
            path[largest][2] = y-1;
            map[x][y-1]=0;
        }
    }
    if(x<(r-1)){
        if(map[x+1][y]){
            largest++;
            path[largest][0] = path[index][0]+1;
            path[largest][1] = x+1;
            path[largest][2] = y;
            map[x+1][y]=0;
        }
    }
    if(y<(c-1)){
        if(map[x][y+1]){
            largest++;
            path[largest][0] = path[index][0]+1;
            path[largest][1] = x;
            path[largest][2] = y+1;
            map[x][y+1]=0;
        }
    }
    return -1;
}
int main(){
    int N;
    scanf("%d",&N);
    while(N--){
        int res=-1;
        largest=0;
        scanf("%d %d",&r,&c);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                char temp;
                scanf(" %c",&temp);
                switch (temp){
                case 'S':
                    path[0][0]=0;
                    path[0][1]=i;
                    path[0][2]=j;
                case '#':
                    map[i][j]=0;
                    break;
                case 'F':
                    finalx = i;
                    finaly = j;
                default:
                    map[i][j]=1;
                    break;
                }
            }
        }
        for(int i=0;(i<=largest)&&(res==-1);i++){
            res = BFS(i);
        }
        printf("%d\n",res);
    }   
    return 0;
}