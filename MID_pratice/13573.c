//13573
#include<stdio.h>
#include<string.h>
int main(){
    char c[1000001],alph[26];
    char res[1000001];
    for(int i=0;i<26;i++){
        alph[i]='a'+i;
    }
    scanf("%s",c);
    int len=strlen(c);
    for(int i=0;i<len;i++){
        res[i]=' ';
    }
    res[len]='\0';
    int num;
    scanf("%d",&num);
    char op[num][3];
    int special[num];
    int typ;
    int index=0;
    for(int i=0;i<num;i++){
        scanf("%d",&typ);
        if(typ==1){
            scanf(" %c %c",&op[i][0],&op[i][1]);
        }
        else if(typ==2){
            op[i][0]=' ';
            scanf("%d",&special[index++]);
            getchar();
            op[i][1]=getchar();
        }
        op[i][2]='\0';
    }
    for(int i=num-1;i>=0;i--){
        if(op[i][0]==' '){
            if(res[special[--index]]==' '){
                res[special[index]]=alph[op[i][1]-'a'];
            }
        }
        else{
            alph[op[i][0]-'a']=alph[op[i][1]-'a'];
        }
    }
    for(int i=0;i<len;i++){
        if(res[i]==' '){
            res[i]=alph[c[i]-'a'];
        }
    }
    printf("%s\n",res);
    return 0;
}