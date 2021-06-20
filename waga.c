#include<stdio.h>
#include<stdlib.h>

int check(int tab[], int n, int w, int i, int p1, int p2, int t[]) {
    if (abs(p1 - p2) == w) return 1;
    if (i >= n) return 0;
    if (i < n - 1 && t[i + 1] < abs(p1 - p2) - w) return 0;
    if (i < n - 1 && t[i + 1] < w - abs(p1 - p2)) return 0;
    if (check(tab, n, w, i + 1, p1 + tab[i], p2, t)) return 1;
    if (check(tab, n, w, i + 1, p1, p2 + tab[i], t)) return 1;
    if (check(tab, n, w, i + 1, p1, p2, t)) return 1;
}

void sum(int tab[], int n, int t[]) {
    int sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        sum += tab[i];
        t[i] = sum;
    }
}

int main() {

    int n, w;
    scanf("%d%d", &n, &w);

    int tab[n];
    for (int i = 0; i < n; i++) scanf("%d", &tab[i]);

    int t[n];
    for (int i = 0; i < n; i++) {
        t[i] = 0;
    }

    sum(tab, n, t);

    if (check(tab, n, w, 0, 0, 0, t)) printf("YES");
    else printf("NO");

    return 0;
}
