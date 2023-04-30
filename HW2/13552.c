#include<stdio.h>
int main(){
    double a,b;
    char o;
    double c;
    scanf("%lf %c %lf",&a,&o,&b);
    if(o=='+'){
        c = a+b;
    }
    else if(o=='-'){
        c = a-b;
    }
    else if(o=='*'){
        c = a*b;
    }
    else if (o=='/'){
        c = a/b;
    }
    printf("%.3lf\n",c);
    return 0;
}