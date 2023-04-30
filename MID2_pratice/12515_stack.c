#include <stdio.h>
#include <limits.h>
int stack[10000000];
int a[10000000];
int ans[10000000];
int main() {
    int n, x, indexstack=0,indexans=0;
    scanf("%d %d", &n, &x);
    stack[indexstack]=INT_MAX;
    a[indexstack]=0;
    for(int i=1;i<=n;i++){
        int num;
        scanf("%d",&num);
        while(num>stack[indexstack])indexstack--;
        stack[++indexstack]=num;
        a[indexstack]=i;
        if(i-a[indexstack-1]==x+1) ans[indexans++]=i;
    }
    if(!indexans) printf("ouo\n");
    else {
        for(int i=0;i<indexans-1;i++){
            printf("%d ",ans[i]);
        }
        printf("%d\n",ans[indexans-1]);
    }
    return 0;
}