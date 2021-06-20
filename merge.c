#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int main() {

    int n;
    scanf("%d", &n);

    int tab[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &tab[i][j]);
        }
    }

    int m = n*n;
    int tab_l[m];
    int k = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tab_l[k] = tab[i][j];
            k++;
        }
    }

    qsort(tab_l, m, sizeof(int), cmpfunc);

    int r = m;
    for (int i = 1; i < m; i++) {
        if (tab_l[i] == tab_l[i - 1]) r--;
    }

    int tab_r[r];
    tab_r[0] = tab_l[0];
    int c = 1;
    for (int i = 1; i < m; i++) {
        if (tab_l[i] != tab_l[i - 1]) {
            tab_r[c] = tab_l[i];
            c++;
        }
    }

    for (int i = 0; i < r; i++) printf("%d ", tab_r[i]);

    return 0;
}

