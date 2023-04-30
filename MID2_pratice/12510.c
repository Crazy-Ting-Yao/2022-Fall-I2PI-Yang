#include<stdio.h>
typedef struct 
{
    int posx;
    int posy;
}Node;
Node steps[1000000];
int t_number;
int ind;
Node ts[1000000];
int map[1000][1000];
int n,m;
void teleport(){
    for(int j=0;j<t_number;j++){
            ind++;
            steps[ind].posx = ts[j].posx;
            steps[ind].posy = ts[j].posy;
            map[ts[j].posx][ts[j].posy]=0;
    }
}
int bfs(int i){
    int x = steps[i].posx;
    int y = steps[i].posy;
    if(x==n-1&&y==m-1) return 1;
    map[x][y]=0;
    if(x>0&&map[x-1][y]){
        if(map[x-1][y]==-1){
            teleport();
        }
        else map[x-1][y]=0;
        ind++;
        steps[ind].posx = x-1;
        steps[ind].posy = y;
    }
    if(y>0&&map[x][y-1]){
        if(map[x][y-1]==-1){
            teleport();
        }
        else map[x][y-1]=0;
        ind++;
        steps[ind].posx = x;
        steps[ind].posy = y-1;
    }
    if(x<n-1&&map[x+1][y]){
        if(map[x+1][y]==-1){
            teleport();
        }
        else map[x+1][y]=0;
        ind++;
        steps[ind].posx = x+1;
        steps[ind].posy = y;
    }
    if(y<m-1&&map[x][y+1]){
        if(map[x][y+1]==-1){
            teleport();
        }
        else map[x][y+1]=0;
        ind++;
        steps[ind].posx = x;
        steps[ind].posy = y+1;
    }
    return 0;
}
int main(){
    //freopen("input.txt","r",stdin);
    int r;
    scanf("%d",&r);
    while(r--){
        scanf("%d %d",&n,&m);
        t_number=0;
        char temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf(" %c",&temp);
                switch (temp){
                case '#':
                    map[i][j]=0;
                    break;
                case 'T':
                    ts[t_number].posx=i;
                    ts[t_number++].posy=j;
                    map[i][j]=-1;
                    break;
                default:
                    map[i][j]=1;
                    break;
                }
            }
        }
        if(map[0][0]==0||map[n-1][m-1]==0){
            printf("No\n");
            continue;
        }
        ind=0;
        steps[ind].posx=0;
        steps[ind].posy=0;
        int flag=0;
        if(map[0][0]==-1){
            teleport();
        }
        else map[0][0]=0;
        for(int i=0;i<=ind;i++){
            flag = bfs(i);
            if(flag) break;
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}