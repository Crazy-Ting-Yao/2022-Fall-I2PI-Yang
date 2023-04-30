#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    char s1[102][1002] = {'\0'}, s2[102][1002] = {'\0'};
    int t1[n], t2[m];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s1[i]);
        t1[i] = strlen(s1[i]);
        // printf("%s\n", s1[i]);
        // printf("%d\n", t1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%s", s2[i]);
        t2[i] = strlen(s2[i]);
        // printf("%s\n", s2[i]);
        // printf("%d\n", t2[i]);
    }
    int check, counter;
    for (int i = 0; i < m; i++)
    {
        check = 1;
        for (int j = 0; j < n; j++)
        {
            counter = 0;
            // printf("check one ok!\n");
            if (t2[i] == t1[j]){
                // printf("check two ok!\n");
                for (int k = 0; k < t2[i]; k++)
                {
                    if (s2[i][k] == s1[j][k])
                    {
                        counter++;
                        // printf("%d\n", counter);
                    }
                }
                if (counter == t2[i])
                {
                    printf("Yes\n");
                    check = 0;
                    break;
                }
            }
        }
        if (check)
            printf("No\n");
    }

    return 0;
}