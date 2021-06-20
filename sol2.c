#include <stdio.h>
#include <math.h>

int bits(int n) {
    return (int) (log(n) / log(2)) + 1;
}

int possible(int tab[20], int n, int g) {
    int x = 0;
    for (int i = 0; i < n; i++) {
        x = x | tab[i];
        if (x == g) return 1;
    }
    return 0;
}

int main() {

    int n, g;
    scanf("%d%d", &n, &g);

    int tab[20];
    for (int i = 0; i < n; i++) scanf("%d", &tab[i]);

    int b = bits(g);
    int m = (int) pow(2, b) - 1 - g;

    for (int i = 0; i < n; i++) {
        if (tab[i] & m || tab[i] > g) tab[i] = 0;
    }

    if (!possible(tab, n, g)) {
        printf("%d", 0);
        return 0;
    }
    else {

        int tab_b[b];
        for (int i = 0; i < b; i++) tab_b[i] = 0;

        for (int i = 0; i < n; i++) {
            int x = tab[i];
            for (int j = b - 1; j >= 0; j--) {
                if (x % 2) tab_b[j]++;
                x /= 2;
            }
        }

        int res = 100;
        for (int i = 0; i < b; i++) {
            if (tab_b[i] && tab_b[i] < res) res = tab_b[i];
        }

        printf("%d", res);
        return 0;
    }
}