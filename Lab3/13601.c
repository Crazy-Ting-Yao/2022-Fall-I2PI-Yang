//13601
#include<stdio.h>
int main(){
    unsigned char a[6],b[6],ae[6],be[6];
    int shift[5];
    scanf("%s",a);
    scanf("%s",ae);
    scanf("%s",b);
    for(int i=0;i<5;i++){
        if(ae[i]>='A'&&ae[i]<='Z'){
            ae[i]+=32;
        }
        else{
            ae[i]-=32;
        }
        shift[i] = ae[i]-a[i];
        if(shift[i]<0){shift[i]+=26;}
        be[i] = b[i]+shift[i];
        if(b[i]<='Z'&&b[i]>='A'&&be[i]>'Z'){
            be[i]-=26;
        }
        else if(b[i]<='z'&&b[i]>='a'&&be[i]>'z'){
            be[i]-=26;
        }
        if(be[i]<='Z'&&be[i]>='A'){
            be[i]+=32;
        }
        else if(be[i]<='z'&&be[i]>='a'){
            be[i]-=32;
        }
        
    }
    be[5] = '\0';
    printf("%s\n",be);
    return 0;
}