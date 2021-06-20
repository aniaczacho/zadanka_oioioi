#include <stdio.h>

int is_prime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {

    char s[51];
    scanf("%s", &s);

    int l = 1;
    while (s[l] != '\0') l++;

    char res[l];
    res[l-1] = '\0';

    int o = 0;
    char x = s[0];
    for (int i = 1; i < l; i++) {
        if (s[i] < x) {
            o = i;
            x = s[i];
        }
    }

    res[0] = s[o];

    int c = 0;
    for (int i = 0; i < l; i++) {
        if (is_prime(i)) c++;
    }

    int primes[c];
    int k = 0;
    for (int i = 2; i < l; i++) {
        if (is_prime(i)) {
            primes[k] = i;
            k++;
        }
    }


    int pp = primes[0];
    char y = s[(o+primes[0])%l];
    //printf("%d", (o+primes[0])%l);

    for (int i = o; i < l+o; i++) {
        for (int j = 1; j < k; j++) {
            if (s[i%l] < y) y = s[i%l];
            pp = primes[k];
        }
    }

    for (int i = 1; i < l; i++) {
        res[i] = s[o+pp*i];
    }

    printf("%s", res);

    return 0;
}