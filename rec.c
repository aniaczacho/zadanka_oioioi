#include <stdio.h>
#include <stdlib.h>

int left(a, b) {
    if (a < b) return a;
    return b;
}

int upper(a, b) {
    if (a > b) return a;
    return b;
}


int main() {

    int n;
    scanf("%d", &n);

    int data[n][4];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) scanf("%d", &data[i][j]);
    }

    int x_max = -100;
    int y_max = -100;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j += 2) {
            if (data[i][j] > x_max) x_max = data[i][j];
            if (data[i][j+1] > y_max) y_max = data[i][j+1];
            }
        }

    int x_min = 100;
    int y_min = 100;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j += 2) {
            if (data[i][j] < x_min) x_min = data[i][j];
            if (data[i][j+1] < y_min) y_min = data[i][j+1];
            }
        }

    int x = x_max - x_min;
    int y = y_max - y_min;
    int tab[x][y];
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) tab[i][j] = 0;
    }

    for (int p = 0; p < n; p++) {
        int i_start = left(data[p][0], data[p][2]) - x_min;
        int j_start = abs(upper(data[p][1], data[p][3]) - y_max);
        int i_max = abs(data[p][0] - data[p][2]);
        int j_max = abs(data[p][1] - data[p][3]);
        for (int i = i_start; i < i_max + i_start; i++) {
            for (int j = j_start; j < j_max + j_start; j++) {
                if (tab[i][j]) tab[i][j] = 0;
                else tab[i][j] = 1;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) sum += tab[i][j];
    }

    printf("%d", sum);

    return 0;
}

