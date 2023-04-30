#include<stdio.h>
#define min(a,b) ((a) < (b) ? (a) : (b))
short DP[1000][1000];
char string[1000];
int k,n;
int check(int start,int end){
    if(start>=end) return 0;
    if(DP[start][end]!=-1) return DP[start][end];
    if(string[start]!=string[end]) DP[start][end] = min(check(start,end-1)+1,check(start+1,end)+1);
    else DP[start][end] = check(start+1,end-1);
    return DP[start][end];
}
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf(" %c",&string[i]);
        for(int j=i+1;j<n;j++) DP[i][j]=-1;
    }
    if(check(0,n-1)<=k) printf("Yes\n");
    else printf("No\n");
    return 0;
}