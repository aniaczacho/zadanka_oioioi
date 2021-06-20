#include <stdio.h>

int ok(int tab[], int n) {
    for (int i = 1; i < n; i++) {
        if ((tab[i] == 1) && (tab[i-1] == 1)) return 0;
    }
    return 1;
}

void generate(int n, int tab[], int i) {

    if ((i == n) && ok(tab, n)) {
        for (int j = 0; j < n; j++) printf("%d", tab[j]);
        printf("\n");
        return;
    }

    if (i == n) return;

    tab[i] = 0;
    generate(n, tab, i + 1);

    tab[i] = 1;
    generate(n, tab, i + 1);
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
        int tab[n];
        generate(n, tab, 0);
    }

    return 0;
}