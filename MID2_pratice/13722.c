#include<stdio.h>
#include<string.h>
#define max(a,b) (a>b ? a:b)
int dp[21][21][21][21][21][21],p[21];
int height,n,t;
int solve(int ti,int a,int b,int c,int d,int e){
    if(dp[ti][a][b][c][d][e]!=-1) return dp[ti][a][b][c][d][e];//如果做過，就用之前的結果就好
    if(ti>=n) return dp[ti][a][b][c][d][e]=n+1;//執行這行則代表是Win
    int val=ti+1,tmp;
    if(p[ti]==1){//straight-stick
        if(a+4<=height) val=max(val,solve(ti+1,a+4,b,c,d,e));
        if(b+4<=height) val=max(val,solve(ti+1,a,b+4,c,d,e));
        if(c+4<=height) val=max(val,solve(ti+1,a,b,c+4,d,e));
        if(d+4<=height) val=max(val,solve(ti+1,a,b,c,d+4,e));
        if(e+4<=height) val=max(val,solve(ti+1,a,b,c,d,e+4));
        tmp=max(max(a,b),max(c,d));//stick
        if(tmp+1<=height) val=max(val,solve(ti+1,tmp+1,tmp+1,tmp+1,tmp+1,e));
        tmp=max(max(b,c),max(d,e));
        if(tmp+1<=height) val=max(val,solve(ti+1,a,tmp+1,tmp+1,tmp+1,tmp+1));
    }
    else if(p[ti]==2){//square
        tmp=max(a,b);
        if(tmp+2<=height) val=max(val,solve(ti+1,tmp+2,tmp+2,c,d,e));
        tmp=max(b,c);
        if(tmp+2<=height) val=max(val,solve(ti+1,a,tmp+2,tmp+2,d,e));
        tmp=max(c,d);
        if(tmp+2<=height) val=max(val,solve(ti+1,a,b,tmp+2,tmp+2,e));
        tmp=max(d,e);
        if(tmp+2<=height) val=max(val,solve(ti+1,a,b,c,tmp+2,tmp+2));
    }
    else if(p[ti]==3){//cross
        tmp=max(max(a,b+1),c);
        if(tmp+2<=height) val=max(val,solve(ti+1,tmp+1,tmp+2,tmp+1,d,e));
        tmp=max(max(b,c+1),d);
        if(tmp+2<=height)  val=max(val,solve(ti+1,a,tmp+1,tmp+2,tmp+1,e));
        tmp=max(max(c,d+1),e);
        if(tmp+2<=height) val=max(val,solve(ti+1,a,b,tmp+1,tmp+2,tmp+1));
    }
    else{//right-snake
        tmp=max(max(a+1,b+1),c);
        if(tmp+1<=height) val=max(val,solve(ti+1,tmp,tmp+1,tmp+1,d,e));
        tmp=max(max(b+1,c+1),d);
        if(tmp+1<=height) val=max(val,solve(ti+1,a,tmp,tmp+1,tmp+1,e));
        tmp=max(max(c+1,d+1),e);
        if(tmp+1<=height) val=max(val,solve(ti+1,a,b,tmp,tmp+1,tmp+1));
        tmp=max(a,b+1);//revolve-snake
        if(tmp+2<=height) val=max(val,solve(ti+1,tmp+2,tmp+1,c,d,e));
        tmp=max(b,c+1);
        if(tmp+2<=height) val=max(val,solve(ti+1,a,tmp+2,tmp+1,d,e));
        tmp=max(c,d+1);
        if(tmp+2<=height) val=max(val,solve(ti+1,a,b,tmp+2,tmp+1,e));
        tmp=max(d,e+1);
        if(tmp+2<=height) val=max(val,solve(ti+1,a,b,c,tmp+2,tmp+1));
    }
    return dp[ti][a][b][c][d][e]=val;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&height);
        for(int i=0;i<n;i++) scanf("%d",&p[i]);
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,0,0,0,0,0);
        if(ans==n+1) printf("Win\n");
        else printf("Lose at %d\n",ans);
    }
    return 0;
}