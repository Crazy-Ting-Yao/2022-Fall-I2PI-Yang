int solver(int **ptr, int *sum, char *s) {
    int index = 0;
    int minus = 0;
    int value = 0;
    int n = 0;
    int searchingnum = 0;
    while (s[index] != '\0') {
        if (s[index] == '-') {
            if (searchingnum) {
                (*(ptr[n])) = value;
                searchingnum = 0;
                if (minus) {
                    (*(ptr[n])) *= (-1);
                    (*sum) -= value;
                } else {
                    (*sum) += value;
                }
                n++;
            }
            value = 0;
            minus = 1;
        } 
        else if (s[index] >= '0' && s[index] <= '9') {
            searchingnum = 1;
            value*=10;
            value+=(s[index]-'0');
        }
        else{
            if (searchingnum) {
                *(ptr[n]) = value;
                searchingnum = 0;
                if (minus) {
                    *(ptr[n]) *= (-1);
                    (*sum) -= value;
                } else {
                    (*sum) += value;
                }
                n++;
            }
            value = 0;
            minus = 0;
        }
        index++;
    }
    if (searchingnum) {
        *(ptr[n]) = value;
        if (minus) {
            *(ptr[n]) *= (-1);
            (*sum) -= value;
        } else {
            (*sum) += value;
        }
        n++;
    }
    return n;
}