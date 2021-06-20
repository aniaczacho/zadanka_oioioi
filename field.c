#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    int tab[101][101];
    for (int i = 0; i <= n; i++) {
        tab[i][0] = 0;
        tab[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) scanf("%d", &tab[i][j]);
    }

    int pref[101][101];
    pref[1][1] = tab[1][1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) pref[i][j] = tab[i][j] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
    }

    int _max = 0;

    int sum = 0;
    int field;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) sum += tab[i][j];
    }

    if (sum == n*n) printf("%d", 0);
    else {
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                for (int c = a;  c <= n; c++) {
                    for (int d = b; d <= n; d++) {
                        sum = pref[c][d] - pref[a-1][d] - pref[c][b-1] + pref[a-1][b-1];
                        if (sum == 0) field = (c-a+1) * (d-b+1);
                        if (field > _max) _max = field;
                    }
                }
            }
        }


        printf("%d", _max);
    }

    return 0;
}
