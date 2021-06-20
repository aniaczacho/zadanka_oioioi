#include <stdio.h>


int main() {

    int n, m;
    scanf("%d%d", &n, &m);

    int tab[m][2];
    for (int i = 0; i < m; i++) {
        scanf("%d", &tab[i][0]);
        scanf("%d", &tab[i][1]);
    }

    int var[n];
    for (int i = 0; i < n; i++) var[i] = 0;

    for (int i = 0; i < m; i++) {
        var[tab[i][0]-1]++;
        var[tab[i][1]-1]++;
    }

    int sum_var = 0;
    for (int i = 0; i < n; i++) sum_var += var[i] * (n-1-var[i]);

    int sum = (n*n*n - 3*n*n + 2*n)/6 - sum_var/2;
    printf("%d", sum);
}