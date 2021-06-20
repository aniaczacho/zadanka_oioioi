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

    int l = 0;
    while (s[l] != '\0') l++;

    char res[l+1];
    res[l] = '\0';

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
    for (int i = 2; i < l; i++) {
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

    int oc = 1;
    for (int i = o+1; i < l; i++) if (s[i] == s[o]) oc++;

    int os[oc];
    os[0] = o;
    int j = 1;
    for (int i = o+1; i < l; i++) {
        if (s[i] == s[o]) {
            os[j] = i;
            j++;
        }
    }


    int ppt[oc];

    for (int m = 0; m < oc; m++) {

        int pp = primes[0];
        char y = s[(os[m] + 2) % l];

        for (int i = 1; i < c; i++) {
            if (s[(os[m] + primes[i]) % l] < y) {
                y = s[(os[m] + primes[i]) % l];
                pp = primes[i];
            }
        }
        ppt[m] = pp;
    }

    int ppr = ppt[0];
    int ores = os[0];
    if (oc > 1) {
        char z = s[(os[0] + ppt[0]) % l];
        for (int i = 1; i < oc; i++) {
            if (s[(os[i] + ppt[i]) % l] < z) {
                z = s[(os[i] + ppt[i])];
                ppr = ppt[i];
                ores = os[i];
            }
        }
    }
    for (int i = 1; i < l; i++) res[i] = s[(ores + ppr * i) % l];

    printf("%s", res);

    return 0;
}