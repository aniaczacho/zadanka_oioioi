#include<stdio.h>

int max_i(int tab[], int n) {

    int max_ = 0;

    for (int i = 1; i < n; i++) {
        if (tab[i] > tab[max_]) max_ = i;
    }
    return max_;
}



int min_sum(int tab[], int n, int k) {

    for (int i = 0; i < k; i++) {
        int m = max_i(tab, n);
        tab[m] = (tab[m]/2);
    }

    int sum = 0;
    for (int i = 0; i < n; i++) sum += tab[i];
    return sum;
}


int main() {

    int n, k;

    scanf("%d%d", &n, &k);

    int tab[n];

    for (int i = 0; i < n; i++) scanf("%d", &tab[i]);

    printf("%d", min_sum(tab, n, k));

    return 0;
}