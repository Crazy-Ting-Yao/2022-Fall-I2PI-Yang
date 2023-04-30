//13805
#include<stdio.h>
#include<string.h>
char c[1000001],alph[26];
char alphsaver[1000001][26];
int alterat[1000001];
char res[1000001],ans[1000001];
int op[1000001][3];
int shifting=0;
int main(){
    for(int i=0;i<26;i++) alph[i]='a'+i; //initialize
    scanf("%s",c);
    int len=strlen(c);
    int num;
    scanf("%d",&num);
    int index=0;
    for(int i=0;i<num;i++){
        scanf("%d",&op[i][0]);
        int t;
        char a,b,temp;
        switch(op[i][0]){
            case 1:
                scanf(" %c %c",&a,&b);
                op[i][1]=(int)a;
                op[i][2]=(int)b;
                break;
            case 2:
                scanf(" %d %c",&op[i][1],&b);
                op[i][1] = (op[i][1]<shifting)?(op[i][1]-shifting+len):(op[i][1]-shifting);
                op[i][2]=(int)b;
                break;
            case 3:
                scanf(" %d %d",&op[i][1],&op[i][2]);
                op[i][1] = (op[i][1]<shifting)?(op[i][1]-shifting+len):(op[i][1]-shifting);
                op[i][2] = (op[i][2]<shifting)?(op[i][2]-shifting+len):(op[i][2]-shifting);
                temp = c[op[i][1]];//change immediately
                c[op[i][1]] = c[op[i][2]];
                c[op[i][2]] = temp;
                break;
            case 4:
                scanf(" %d",&op[i][1]);
                shifting = (shifting+op[i][1])%len;
                //printf("%d ",shifting);
                break;
        }
    }
    //printf("\n");
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
    for(int i=shifting;i<len;i++){
        if(!res[i-shifting]) ans[i]=alph[c[i-shifting]-'a'];
        else ans[i]= alphsaver[alterat[i-shifting]][res[i-shifting]-'a'];
    }
    for(int i=0;i<shifting;i++){
        if(!res[i+len-shifting]) ans[i]=alph[c[i+len-shifting]-'a'];
        else ans[i]= alphsaver[alterat[i+len-shifting]][res[i+len-shifting]-'a'];
    }
    printf("%s\n",ans);
    return 0;
}