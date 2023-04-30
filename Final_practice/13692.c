//13692
#include<stdio.h>
#include<string.h>
char c[1000001],alph[26];
char alphsaver[100001][26];
int alterat[1000001];
char res[1000001];
int op[100001][3];
int main(){
    for(int i=0;i<26;i++) alph[i]='a'+i; //initialize
    scanf("%s",c);
    int len=strlen(c);
    int num;
    scanf("%d",&num);
    int typ;
    int index=0;
    for(int i=0;i<num;i++){
        scanf("%d",&typ);
        int t;
        char a,b,temp;
        switch(typ){
            case 1:
                scanf(" %c %c",&a,&b);
                op[i][0]=1;
                op[i][1]=(int)a;
                op[i][2]=(int)b;
                break;
            case 2:
                op[i][0]=2;
                scanf(" %d %c",&op[i][1],&b);
                op[i][2]=(int)b;
                break;
            case 3:
                op[i][0]=3;
                scanf(" %d %d",&op[i][1],&op[i][2]);
                temp = c[op[i][1]];//change immediately
                c[op[i][1]] = c[op[i][2]];
                c[op[i][2]] = temp;
            break;
        }
    }
    int m,k;
    for(int i=num-1;i>=0;i--){ //do it reversely
        if(op[i][0]==1) alph[op[i][1]-'a']=alph[op[i][2]-'a']; 
        for(int k=0;k<26;k++) alphsaver[i][k] = alph[k]; //save the alph alter result every time
    }
    for(int i=0;i<num;i++){ //do it reversely
        int temp;
        char t;
        switch(op[i][0]){
            case 2:
                alterat[op[i][1]]=i;
                res[op[i][1]] = (char)op[i][2];
                break;
            case 3:
                temp = alterat[op[i][1]];
                alterat[op[i][1]] = alterat[op[i][2]];
                alterat[op[i][2]] = temp;
                t = res[op[i][1]];
                res[op[i][1]] = res[op[i][2]];
                res[op[i][2]] = t;
                break;
        }
    }
    for(int i=0;i<len;i++){
        if(!res[i]) res[i]=alph[c[i]-'a'];
        else res[i]= alphsaver[alterat[i]][res[i]-'a'];
    }
    printf("%s\n",res);
    return 0;
}