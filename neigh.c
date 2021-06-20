#include <stdio.h>
#include <stdlib.h>

int max(int num1, int num2) {
    return (num1 > num2 ) ? num1 : num2;
}

int d(int i, int j, int i_, int j_) {
    return max(abs(i - i_), abs(j - j_));
}

int main() {

    int n, r;
    scanf("%d%d", &n, &r);

    int tab[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &tab[i][j]);
        }
    }

    int tab_r[n][n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            for (int i_ = 0; i_ < n; i_++) {
                for (int j_ = 0; j_ < n; j_++) {
                    if (d(i, j, i_, j_) <= r) sum += tab[i_][j_];
                }
            }
            tab_r[i][j] = sum;
            sum = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", tab_r[i][j]);
        }
        printf("\n");
    }


    return 0;
}