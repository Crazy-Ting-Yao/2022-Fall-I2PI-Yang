//13290
#include<stdio.h>
#include<string.h>
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    char lst[100][1001];
    for(int i=0;i<a;i++){
        scanf("%s",lst[i]);
    }
    for(int i=0;i<b;i++){
        char ref[1001];
        scanf("%s",ref);
        int flag=1;
        for(int j=0;j<a;j++){
            if(strcmp(ref,lst[j])==0&&flag){
                printf("Yes\n");
                flag=0;
            }
        }
        if(flag){printf("No\n");}
    }
    return 0;
}