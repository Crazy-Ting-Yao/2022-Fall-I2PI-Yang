#include<stdio.h>
int main(){
    short a;
    scanf("%hd",&a);
    short hour,min;
    hour = a / 100;
    min = a % 100;
    if(hour<12){
        printf("%02hd:%02hd a.m.",hour,min);
    }
    else{
        hour-=12;
        printf("%02hd:%02hd p.m.",hour,min);
    }
    return 0;
}