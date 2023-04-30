#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char** s;
int n, m;
void add() {
    int k;
    scanf("%d", &k);
    k--;
    int lenk = strlen(s[k]);
    char temp[101];
    scanf("%s", temp);
    int len = strlen(temp);
    char* origin = (char*)malloc(sizeof(char) * (lenk + 1));
    origin[0] = 0;
    strcpy(origin, s[k]);
    free(s[k]);
    s[k] = (char*)malloc(sizeof(char) * (lenk + len + 1));
    s[k][0] = 0;
    strcpy(s[k], origin);
    strcat(s[k], temp);
    free(origin);
}
void delete() {
    int k, a;
    scanf("%d %d", &k, &a);
    k--;
    int lenk = strlen(s[k]);
    if (a >= lenk) {
        free(s[k]);
        s[k] = (char*)calloc(sizeof(char), 1);
        return;
    }
    int originlen = strlen(s[k]);
    char* origin = (char*)malloc(sizeof(char) * (originlen + 1));
    strncpy(origin, s[k], (lenk - a));
    origin[lenk - a] = 0;
    free(s[k]);
    s[k] = (char*)malloc(sizeof(char) * (lenk - a + 1));
    s[k][0] = 0;
    strcpy(s[k], origin);
    lenk -= a;
    free(origin);
}
void swap() {
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    char* c = s[a];
    s[a] = s[b];
    s[b] = c;
}
void longest() {
    int max = -1;
    int id = 0;
    for (int i = 0; i < n; i++) {
        int l = strlen(s[i]);
        if (max < l) {
            max = l;
            id = i;
        }
    }
    printf("%d %s\n", max, s[id]);
}
void all() {
    for (int i = 0; i < n; i++) printf("%s\n", s[i]);
}
void end() {
    for (int i = 0; i < n; i++) free(s[i]);
    free(s);
}
int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    s = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++) s[i] = (char*)calloc(sizeof(char), 1);
    char ops[10];
    while (m--) {
        scanf("%s", ops);
        if (!strcmp("add", ops))
            add();
        else if (!strcmp("delete", ops))
            delete();
        else if (!strcmp("swap", ops))
            swap();
        else if (!strcmp("longest", ops))
            longest();
        else if (!strcmp("all", ops))
            all();
    }
    end();
    return 0;
}