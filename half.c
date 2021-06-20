#include <stdio.h>

int sum(int t[], int a, int b) {
    int s = 0;
    int i = a;
    for ( i; i <= b; i++) {
        s += t[i];
    }
    return s;
}

int find_index(int n, int tab[]) {
    int i = n / 2;
    if (sum(tab, 0, i-1) == sum(tab, i+1, n - 1)) return i;
    else {
        while (sum(tab, 0, i-1) != sum(tab, i+1, n - 1)) {
            if (sum(tab, 0, i-1) < sum(tab, i + 1, n - 1)) i++;
            else i--;
        }
    }
    return i;
}


int main() {

    int n;
    scanf("%d\n", &n);

    int tab[n];

    for (int i = 0; i < n; i++) scanf("%d", &tab[i]);

    printf("%d\n", find_index(n, tab));




    return 0;
}
