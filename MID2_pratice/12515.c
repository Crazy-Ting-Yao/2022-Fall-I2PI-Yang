#include <stdio.h>
int DP[10000000];
int larger[10000000];
int a[10000000];
int n, x;
int recursion(int i, int ref) {
    if (ref == -1) {
        larger[i] = -1;
        return 0;
    }
    if (a[ref] >= a[i]) {
        larger[i] = ref;
        return 0;
    }
    return DP[ref] + 1 + recursion(i, larger[ref]);
}
int main() {
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    larger[0] = -1;
    int res = 0;
    for (int i = 1; i < n; i++) {
        DP[i] = recursion(i, i - 1);
        if (DP[i] == x) {
            if(res) printf(" ");
            else res = 1;
            printf("%d",i+1);
            
        }  
    }
    if (!res)
        printf("ouo\n");
    else {
        printf("\n");
    }
    return 0;
}