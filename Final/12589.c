#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
    char name[35];
    short occupation;
    int age;
}Cat;
int cmp(const void* pa, const void* pb){
    Cat* a = (Cat*)pa;
    Cat* b = (Cat*)pb;
    if(a->occupation==2)return -1;
    if(b->occupation==2)return 1;
    if((a->occupation)!=(b->occupation)) return ((b->occupation)-(a->occupation));
    else if((a->age)!=(b->age)) return ((b->age)-(a->age));
    else return strcmp(a->name,b->name);
}
int main(){
    int n,m;
    while (scanf("%d %d",&n,&m)!=EOF){
        if(m>n) m=n;
        Cat* cat = (Cat*)malloc(sizeof(Cat)*n);
        for(int i=0;i<n;i++){
            scanf("%s",cat[i].name);
            char oc[13];
            scanf("%s",oc);
            if(!strcmp(oc,"kitty")) cat[i].occupation=1;
            else if(!strcmp(oc,"elder")) cat[i].occupation=2;
            else cat[i].occupation=0;
            scanf("%d",&cat[i].age);
        }
        qsort(cat,n,sizeof(cat[0]),cmp);
        for(int i=0;i<m;i++) printf("%s\n",cat[i].name);
        free(cat);
    }
    return 0;
}