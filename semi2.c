#include <stdio.h>

int is_multiple(int a, int m) {
    if (a % m == 0) return 1;
    if (a == 0) return 0;
    return 0;
}

int is_semi(int x, int m, int n, int powers[32]) {
    int a = x;
    for (int i = 0; i < n; i++) {
        if (((a % 2) == 1) && is_multiple(x - powers[i], m)) return 1;
        if (((a % 2) == 0) && is_multiple(x + powers[i], m)) return 1;
        a /= 2;
    }
    return 0;
}

int main() {

    int n, m;
    scanf("%d%d", &n, &m);

    int powers[32];
    powers[0] = 1;
    for (int i = 1; i <= n; i++) powers[i] = 2 * powers[i - 1];

    int res = 0;

    for (int i = 1; i < powers[n]; i++) {
        if (is_multiple(i, m) == 0 && is_semi(i, m, n, powers)) res++;
    }

    printf("%d", res);

    return 0;
}