#include <stdio.h>

int divide(int n[], int l) {
    int r = 0;
    int new_r;
    for (int i = 0; i < l; i++) {
        new_r = (n[i] + r * 10) % 2;
        n[i] = (n[i] + r * 10) / 2;
        r = new_r;
    }
    return r;
}

int inc(int n[], int l) {
    int r = 1;
    int i = l - 1;
    while (i >= 0 && r == 1)
    {
        n[i] += 1;
        n[i] %= 10;
        if (n[i] != 0) r = 0;
        if (i == 0 && r != 0) {
            l += 1;
            for (int j = l - 1; j > 0; --j) {
                n[j] = n[j-1];
            }
            n[0] = 1;
        }
        i--;
    }
    return l;
}

int mod(int n[], int l) {
    if (n[l - 1] % 2 == 1) return 1;
    else return 0;
}

int is_zero(int n[], int l) {
    for (int i = 0; i < l; i++)
        if (n[i] != 0) return 0;
    return 1;
}

int atm(int res[], int n[], int l, int m) {
    int i = 0;
    while (i < 100 && is_zero(n, l) == 0) {
        res[i] = mod(n, l);
        if (i % 2 == m && res[i] == 1) {
            l = inc(n, l);
        }
        divide(n, l);
        i++;
    }
    if (is_zero(n, l) == 0) return 0;
    else return 1;
}

int main()
{
    char tab[35];
    scanf("%s", tab);
    int l = 0;
    while (tab[l] != '\0') l++;
    int n1[35];
    int n2[35];
    for (int i = 0; i < l; i++) {
        n1[i] = tab[i] - '0';
        n2[i] = tab[i] - '0';
    }

    int r1[100] = {0};
    int r2[100] = {0};

    int b1 = atm(r1, n1, l, 1);
    int b2 = atm(r2, n2, l, 0);

    if (b1 == 1) {
        for (int j = 0; j < 100 ; j++)
            if (r1[j] == 1) printf("%d ", j);
    } else printf("NO");
    printf("\n");

    if (b2 == 1) {
        for (int j = 0; j < 100 ; j++)
            if (r2[j] == 1) printf("%d ", j);
    } else printf("NO");
}