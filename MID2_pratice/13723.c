#include <stdio.h>
#include <string.h>
char yummy[1000][305];
int sevens[1000];
int indexs[1000];
int indexs2[1000];
int n, k;
int k2;
char res[1000][301];
int r;
void inverse() {
    for (int i = 0; i < n; i++) {
        int len = indexs2[i];
        for (int j = 0; j < len / 2; j++) {
            char c = yummy[i][j];
            yummy[i][j] = yummy[i][len - 1 - j];
            yummy[i][len - 1 - j] = c;
        }
        yummy[i][len] = '\0';
    }
}
void finding_sevens() {
    while (1) {
        int saver[1000];
        int nums = 0;
        int max = 0;
        for (int i = 0; i < n; i++) {
            if (sevens[i] > max) {
                nums = 0;
                max = sevens[i];
                saver[nums++] = i;
            } 
            else if (sevens[i] == max) saver[nums++] = i;
        }
        if (nums > k2) {
            for (int i = 0; i < nums; i++) {
                if (i == saver[i]) continue;
                else {
                    strcpy(yummy[i], yummy[saver[i]]);
                    indexs2[i] = indexs2[saver[i]];
                }
                n = nums;
            }
            return;
        }
        for (int i = 0; i < nums; i++) {
            strcpy(res[r], yummy[saver[i]]);
            yummy[saver[i]][0] = '\0';
            sevens[saver[i]] = 0;
            indexs[r++] = indexs2[saver[i]];
            indexs2[saver[i]] = 0;
        }
        k2 -= nums;
        if (!k2) return;
    }
}
void remains() {
    while (1) {
        int saver[1000];
        int nums = 0;
        int max = 0;
        for (int i = 0; i < n; i++) {
            if (indexs2[i] > max) {
                nums = 1;
                max = indexs2[i];
                saver[0] = i;
            } 
            else if (indexs2[i] == max) saver[nums++] = i;
        }
        if (nums > k2) {
            for (int i = 0; i < k2; i++) {
                max = 0;
                for (int j = 1; j < nums; j++) {
                    if (strcmp(yummy[saver[j]], yummy[saver[max]]) >= 1) max = j;
                }
                strcpy(res[r], yummy[saver[max]]);
                yummy[saver[max]][0] = '\0';
                indexs[r++] = indexs2[saver[max]];
            }
            break;
        }
        for (int i = 0; i < nums; i++) {
            strcpy(res[r], yummy[saver[i]]);
            yummy[saver[i]][0] = '\0';
            indexs[r++] = indexs2[saver[i]];
            indexs2[saver[i]] = 0;
        }
        k2 -= nums;
        if (!k2) return;
    }
}
int cmp(int x, int y) {
    if (indexs[x] > indexs[y]) return 1;
    else if (indexs[x] < indexs[y]) return 0;
    else if (strcmp(res[x], res[y]) >= 1) return 1;
    else return 0;
}
void sort() {
    for (int i = k - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (cmp(j, j + 1)) {
                char temp[300];
                strcpy(temp, res[j]);
                strcpy(res[j], res[j + 1]);
                strcpy(res[j + 1], temp);
                int t = indexs[j];
                indexs[j] = indexs[j + 1];
                indexs[j + 1] = t;
            }
        }
    }
}
void scanning(int i) {
    int index = 0;
    long long int x = 0;
    char c;
    char s[251];
    scanf("%s", s);
    int len = strlen(s);
    long long digit = 1;
    for (int j = len - 1; j >= 0; j--) {
        c = s[j];
        if (c == '|') {
            while (x) {
                yummy[i][index++] = (x % 10) + '0';
                if (x % 10 == 7) sevens[i]++;
                x /= 10;
            }
            digit = 1;
        } else {
            if (c >= '0' && c <= '9')
                x += ((c - '0') * digit);
            else
                x += ((c - 'A' + 10) * digit);
            digit *= 16;
        }
    }
    while (x) {
        yummy[i][index++] = (x % 10) + '0';
        if (x % 10 == 7) sevens[i]++;
        x /= 10;
    }
    indexs2[i] = index;
}
int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &k);
    k2 = k;
    getchar();
    for (int i = 0; i < n; i++) scanning(i);
    inverse();
    finding_sevens();
    if (k2) remains();
    sort();
    for (int i = 0; i < k; i++) printf("%s\n", res[i]);
    return 0;
}