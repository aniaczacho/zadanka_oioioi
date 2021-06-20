#include <stdio.h>

int sum(int tab[][100], int i, int j, int rec[], int k, int l) {
    int s = 0;
    int c = 0;
    for (int a = i; a < i+k; a++) {
        for (int b = j; b < j+l; b++) {
            if (rec[c] == 1) s += tab[a][b];
            c++;
        }
    }
    return s;
}

int main() {

    int n, k, l;
    scanf("%d%d%d", &n, &k, &l);

    int tab[n][100];
    for (int i = 0; i < n; i++) {
        for  (int j = 0; j < n; j++) scanf("%d", &tab[i][j]);
    }

    int rec_d[k][l];
    for (int i = 0; i < k; i++) {
        for  (int j = 0; j < l; j++) scanf("%d", &rec_d[i][j]);
    }

    int rec[k+l];
    int c = 0;
    for (int i = 0; i < k; i++) {
        for  (int j = 0; j < l; j++) {
            rec[c] = rec_d[i][j];
            c++;
        }
    }


    int max_sum = 0;
    for (int i = 0; i <= n-k; i++) {
        for (int j = 0; j <= n-l; j++) {
            if (sum(tab, i, j, rec, k, l) > max_sum) max_sum = sum(tab, i, j, rec, k, l);
        }
    }

    printf("%d", max_sum);

    return 0;
}

