#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int bits(int n) {
    return (int) (log(n) / log(2)) + 1;
}

int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int possible(int tab[20], int n, int g) {
    int x = 0;
    for (int i = 0; i < n; i++) {
        x = x | tab[i];
        if (x == g) return 1;
    }
    return 0;
}

int main() {

    int n, g;
    scanf("%d%d", &n, &g);

    int tab[20];
    for (int i = 0; i < n; i++) scanf("%d", &tab[i]);

    int res = 0;

    int m = (int) pow(2, bits(g)) - 1 - g;

    for (int i = 0; i < n; i++) {
        if (tab[i] & m || tab[i] > g) tab[i] = 0;
    }

    qsort(tab, n, sizeof(int), cmpfunc);

    while (possible(tab, n, g)) {
        for (int i = n-1; i >= 0; i--) {
            if (tab[i] != 0) {
                tab[i] = 0;
                res++;
                break;
            }
        }
    }

    printf("%d", res);

    return 0;
}