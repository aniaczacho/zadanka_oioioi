#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int has_pair(int tab[], int n, int k, int i) {
    if ((i > 0) && (tab[i] - tab[i - 1]) > 0 && (tab[i] - tab[i - 1]) <= k) return 1;
    if ((i < n - 1) && (tab[i + 1] - tab[i]) > 0 && (tab[i + 1] - tab[i]) <= k) return 1;
    int j = i;
    int c = 0;
    if (tab[i - 1] == tab[i]) {
        while ((j > 0) && (tab[j - 1] == tab[j])) j--;
        if ((tab[j + 1] - tab[j]) > 0 && (tab[j + 1] - tab[j]) <= k) return 1;
    }
    if (tab[i + 1] == tab[i]) {
        while ((j < n - 1) && (tab[j + 1] == tab[j])) j++;
        if ((tab[j] - tab[j - 1]) > 0 && (tab[j] - tab[j - 1]) <= k) return 1;
    }
    return 0;
}

int main() {

    int n, k;
    scanf("%d%d", &n, &k);

    int tab[n];
    for (int i = 0; i < n; i++) scanf("%d", &tab[i]);

    qsort(tab, n, sizeof(int), cmpfunc);

    int d = 0;
    for (int i = 1; i < n; i++) {
        if (tab[i] == tab[i - 1]) d++;
    }

    printf("%d\n", d);

    /*int nd_tab[d];
    for (int i = 1; i < d) {

    }


    for (int i = 0; i < d; i++) printf("%d\n", nd_tab[i]); */


    int c = 0;

    if (n == 1) printf("%d", 0);
    else {
        for (int i = 1; i < n - 1; i++) {
            if (has_pair(tab, n, k, i)) c++;
        }
        printf("%d", c);
    }

    return 0;
}