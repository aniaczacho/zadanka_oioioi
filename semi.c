#include <stdio.h>

int power(int a, int b) {
    int p = 1;
    for (int i = 0; i < b; i++) {
        p *= a;
    }
    return p;
}

int is_not_a_multiple(int i, int m) {
    return (i % m);
}

int is_multiple(int tab[31], int n, int m) {
    int r = 0;
    int c = 0;
    for (int i = n-1; i >= 0; i--) {
        r += (power(2, c) * tab[i]);
        c++;
    }
    if (r == 0) return 0;
    if ((r % m) == 0) return 1;
    return 0;
}

int un(int n) {
    if (n == 0) return 1;
    return 0;
}

int is_semi(int i_bin[31], int m, int n) {
    for (int i = 0; i < n; i++) {
        int tab[31];
        for (int j = 0; j < n; j++) tab[j] = i_bin[j];
        tab[i] = un(i_bin[i]);
        if (is_multiple(tab, n, m)) return 1;
    }
    return 0;
}

int main() {

    int n, m;
    scanf("%d%d", &n, &m);

    int res = 0;

    for (int i = 0; i < power(2, n); i++) {

        int i_bin[31];
        int y = i;
        for (int j = n-1; j >= 0; j--) {
            i_bin[j] = y % 2;
            y /= 2;
        }
        if (is_not_a_multiple(i, m) && is_semi(i_bin, m, n)) res++;
    }

    printf("%d", res);

    return 0;
}