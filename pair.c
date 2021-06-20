#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int paired(int a, int b, int k) {
    if (a == b) return 0;
    if ((b >= a - k) && (b <= a + k)) return 1;
    else return 0;
}

int pairs(int tab[], int n, int k) {
    int c = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i != j) && (paired(tab[i], tab[j], k))) {
                c++;
                break;
            }
        }
    }
    return c;
}

int main() {

    int n, k;
    scanf("%d%d", &n, &k);

    int tab[n];
    for (int i = 0; i < n; i++) scanf("%d", &tab[i]);

    qsort(tab, n, sizeof(int), cmpfunc);

    printf("%d", pairs(tab, n, k));

    return 0;

}
