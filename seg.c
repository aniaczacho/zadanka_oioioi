#include <stdio.h>

/*
5 2
8 1 0 1 0
2 3 4 7 1
2 7 4 0 1
1 8 5 1 4
0 1 6 3 9
*/

int row_sum(int tab[][100], int n, int k, int i, int j) {
    int sum = 0;
    int a = j;
    for (int l = 0; l < k; l++) {
        if (a > n-1) a %= n-1;
        sum += tab[i][a];
        a++;
    }
    return sum;
}

int col_sum(int tab[][100], int n, int k, int i, int j) {
    int sum = 0;
    int a = i;
    for (int l = 0; l < k; l++) {
        if (a > n-1) a %= n-1;
        sum += tab[a][j];
        a++;
    }
    return sum;
}

int right_sum(int tab[][100], int n, int k, int i, int j) {
    int sum = 0;
    int x = i;
    int y = j;
    for (int l = 0; l < k; l++) {
        if (x > n-1) x %= n-1;
        if (y > n-1) y %= n-1;
        sum += tab[x][y];
        x++;
        y++;
    }
    return sum;
}

int left_sum(int tab[][100], int n, int k, int i, int j) {
    int sum = 0;
    int x = i;
    int y = j;
    for (int l = 0; l < k; l++) {
        if (y == -1) y = n-1;
        if (x > n-1) x %= n-1;
        sum += tab[y][x];
        x++;
        y--;
    }
    return sum;
}

int main() {

    int n, k;
    scanf("%d%d", &n, &k);

    int tab[n][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) scanf("%d", &tab[i][j]);
    }

    int max_sum = 0;

    int x, y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
             x = row_sum(tab, n, k, i, j);
             y = col_sum(tab, n, k, i, j);
             if (x > max_sum) max_sum = x;
             if (y > max_sum) max_sum = y;
        }
    }

    int r, l;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            r = right_sum(tab, n, k, i, j);
            l = left_sum(tab, n, k, i, j);
            if (r > max_sum) max_sum = r;
            if (l > max_sum) max_sum = l;
        }
    }

    printf("%d", max_sum);

    return 0;
}
