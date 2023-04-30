#include<stdio.h>
#include<string.h>
typedef struct {
    char name[21];
    int c_hp;
    int max_hp;
}Data;
Data p_f[100];
int indexf,indexn;
Data p_nf[100];
Data tmp;
int num;
void sort(){
    for(int i=indexf-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(p_f[j].c_hp>p_f[j+1].c_hp){
                strcpy(tmp.name,p_f[j].name);
                tmp.max_hp=p_f[j].max_hp;
                tmp.c_hp=p_f[j].c_hp;
                strcpy(p_f[j].name,p_f[j+1].name);
                p_f[j].max_hp=p_f[j+1].max_hp;
                p_f[j].c_hp=p_f[j+1].c_hp;
                strcpy(p_f[j+1].name,tmp.name);
                p_f[j+1].max_hp=tmp.max_hp;
                p_f[j+1].c_hp=tmp.c_hp;
            }
        }
    }
    for(int i=indexn-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(p_nf[j].c_hp>p_nf[j+1].c_hp){
                strcpy(tmp.name,p_nf[j].name);
                tmp.max_hp=p_nf[j].max_hp;
                tmp.c_hp=p_nf[j].c_hp;
                strcpy(p_nf[j].name,p_nf[j+1].name);
                p_nf[j].max_hp=p_nf[j+1].max_hp;
                p_nf[j].c_hp=p_nf[j+1].c_hp;
                strcpy(p_nf[j+1].name,tmp.name);
                p_nf[j+1].max_hp=tmp.max_hp;
                p_nf[j+1].c_hp=tmp.c_hp;
            }
            else if(p_nf[j].c_hp==p_nf[j+1].c_hp){
                if(p_nf[j].max_hp>p_nf[j+1].max_hp){
                    strcpy(tmp.name,p_nf[j].name);
                    tmp.max_hp=p_nf[j].max_hp;
                    tmp.c_hp=p_nf[j].c_hp;
                    strcpy(p_nf[j].name,p_nf[j+1].name);
                    p_nf[j].max_hp=p_nf[j+1].max_hp;
                    p_nf[j].c_hp=p_nf[j+1].c_hp;
                    strcpy(p_nf[j+1].name,tmp.name);
                    p_nf[j+1].max_hp=tmp.max_hp;
                    p_nf[j+1].c_hp=tmp.c_hp;
                }
            }
        }
    }
}
int main(){
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        char c[21];
        int hp,max;
        scanf("%s %d %d",c,&hp,&max);
        if(max==hp){
            strcpy(p_f[indexf].name,c);
            p_f[indexf].c_hp=hp;
            p_f[indexf++].max_hp=max;
        }
        else{
            strcpy(p_nf[indexn].name,c);
            p_nf[indexn].c_hp=hp;
            p_nf[indexn++].max_hp=max;
        }
    }
    sort();
    for(int i=0;i<indexn;i++){
        printf("%s %d %d\n",p_nf[i].name,p_nf[i].c_hp,p_nf[i].max_hp);
    }
    for(int i=0;i<indexf;i++){
        printf("%s %d %d\n",p_f[i].name,p_f[i].c_hp,p_f[i].max_hp);
    }
}