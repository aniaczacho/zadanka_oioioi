#include <stdio.h>

void dec_to_bin(int tab[], int n, int a) {
    for (int i = n-1; a > 0; i--) {
        tab[i] = a % 2;
        a /= 2;
    }
}

int ok(int tab[], int n) {
    for (int i = 1; i < n; i++) {
        if ((tab[i] == 1) && (tab[i-1] == 1)) return 0;
    }
    return 1;
}

int power(int a, int b) {
    int p = 1;
    for (int i = 0; i < b; i++) {
        p *= a;
    }
    return p;
}

int main() {

    int n, k;
    scanf("%d%d", &n, &k);

    int fib[64];
    fib[0] = 1;
    fib[1] = 2;
    for (int i = 2; i <= 64; i++) fib[i] = fib[i-1] + fib[i-2];

    int p = fib[n];
    if (p < k) printf("%d", -1);

    else {
        int q = 0;
        for (int i = 0; i < power(2, n); i++) {

            int res[n];
            for (int j = 0; j < n; j++) res[j] = 0;
            dec_to_bin(res, n, i);

            if (ok(res, n)) q++;

            if (ok(res, n) && q == k) {
                for (int j = 0; j < n; j++) printf("%d", res[j]);
                return 0;
            }
        }
    }
    return 0;
}