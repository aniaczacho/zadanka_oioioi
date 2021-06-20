#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int min_sum(int tab[], int n, int k) {
    for (int i = 0; i < k; i++) {
        tab[n - 1] = (tab[n - 1]/2);
        int j = n - 1;
        while ((j != 0) && (tab[j] < tab[j - 1])) {
            int b = tab[j];
            tab[j] = tab[j - 1];
            tab[j - 1] = b;
            j--;
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++) sum += tab[i];
    return sum;
}

int main() {

    int n, k;
    scanf("%d%d", &n, &k);

    int tab[n];
    for (int i = 0; i < n; i++) scanf("%d", &tab[i]);

    qsort(tab, n, sizeof(int), cmpfunc);

    printf("%d", min_sum(tab, n, k));

    return 0;
}
