#include <stdio.h>

int sum(int tab[][100], int i, int j, int r, int n) {
    if ((i + r > n) || (j + r > n)) return 0;
    int sum = 0;
    for (int x = i; x < i+r; x++) sum += tab[x][j];
    for (int y = j+1; y < j+r-1; y++) sum += tab[i+r-1][y];
    for (int x = i; x < i+r; x++) sum += tab[x][j+r-1];
    for (int y = j+1; y < j+r-1; y++) sum += tab[i][y];
    return sum;
}

int main() {

    int n, k;
    scanf("%d%d", &n, &k);

    int tab[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) scanf("%d", &tab[i][j]);
    }

    int r;
    if (n%2 == 1) r = n;
    else r = n-1;

    int rs[r/2];
    for (int i = 0; i < r/2; i++) rs[i] = 3+i*2;

    int q = 0;
    for (int i = 0; i <= n-2; i++) {
        for (int j = 0; j <= n-2; j++) {
            for (int l = 0; l < r/2; l++) if (sum(tab, i, j, rs[l], n) == k) q++;
        }
    }

    int p = 0;
    int res[2][q];
    for (int i = 0; i <= n-2; i++) {
        for (int j = 0; j <= n-2; j++) {
            for (int l = 0; l < r/2; l++) if (sum(tab, i, j, rs[l], n) == k) {
                res[0][p] = i+rs[l]/2;
                res[1][p] = j+rs[l]/2;
                p++;
            }
        }
    }

    printf("%d\n", q);
    for (int i = 0; i < q; i++) printf("%d %d\n", res[0][i], res[1][i]);

    return 0;
}