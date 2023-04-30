//13586
#include<stdio.h>
#include<string.h>
int main(){
    char c1[200],c2[200];
    int arr1[50]={0},arr2[50]={0},arr3[50]={0};
    scanf("%s",c1);
    scanf("%s",c2);
    int a=strlen(c1);
    for(int i=49;a>=0;i--){
        arr1[i] = (c1[a-1]-'0');
        if(a>=2){
            arr1[i] += 10*(c1[a-2]-'0');
        }
        if(a>=3){
            arr1[i] += 100*(c1[a-3]-'0');
        }
        a-=4;
    }
    int b=strlen(c2);
    for(int i=49;b>=0;i--){
        arr2[i] = (c2[b-1]-'0');
        if(b>=2){
            arr2[i] += 10*(c2[b-2]-'0');
        }
        if(b>=3){
            arr2[i] += 100*(c2[b-3]-'0');
        }
        b-=4;
    }
    a=strlen(c1)/4+1;
    if(a<strlen(c2)/4+1){a = strlen(c2)/4+1;}
    int addone=0;
    for(int i=49;i>=49-a;i--){
        if(addone){arr3[i]+=1;}
        arr3[i]+=arr1[i]+arr2[i];
        if(arr3[i]>=1000){
            addone=1;
            arr3[i]-=1000;
        }
        else{
            addone=0;
        }
    }
    if(arr3[49-a]!=0){a++;}
    if(a==1){
        printf("%d",arr3[49]);
        return 0;
    }
    printf("%d,",arr3[50-a]);
    for(int i=51-a;i<49;i++){
        printf("%03d,",arr3[i]);
    }
    printf("%03d\n",arr3[49]);
    return 0;
}