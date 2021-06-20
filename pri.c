#include <stdio.h>

int found(int a) {
    int sum = 0;
    while (sum != 1 && sum != 4) {
        sum = 0;
       while (a >= 1) {
           sum += (a % 10) * (a % 10);
           a /= 10;
       }
       a = sum;
    }
    if (sum == 1) return 1;
    else return 0;
}

int main() {

    int l, u, k;
    scanf("%d%d%d", &l, &u, &k);

    int prime[u + 1];
    prime[0] = 0;
    prime[1] = 0;

    for (int i = 2; i < u + 1; i++) prime[i] = 1;

    for (int p = 2; p * p <= u; p++) {
        if (prime[p] == 1) {
            for (int i = p * p; i <= u; i += p)
                prime[i] = 0;
        }
    }

    int n = 0;
    for (int i = l; i <= u; i++) {
        if (prime[i]) n++;
    }

    int tab[n];

    int j = 0;
    for (int i = l; i <= u; i++) {
        if (prime[i]) {
            tab[j] = i;
            j++;
        }
    }

    int result = 0;

    for (int i = 0; i < n; i++) {
        if (found(tab[i])) k--;
        if (k == 0) {
            result = tab[i];
            break;
        }
    }

    if (k != 0) printf("%d", -1);
    else printf("%d", result);


    return 0;
}
