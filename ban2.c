#include <stdio.h>
#include <stdlib.h>

int main() {

    long long int n;
    scanf("%lld", &n);

    long long int m = -n;
    int atm[100];


    for (int i = 0; i < 100; i++) {
        atm[i] = (int) (n % 2);
        if (atm[i]) printf("%d ", i);
        n = (n - abs(atm[i])) / (-2);
    }
    if (n != 0) printf("NO");

    printf("\n");

    for (int i = 0; i < 100; i++) {
        atm[i] = (int) (m % 2);
        if (atm[i]) printf("%d ", i);
        m = (m - abs(atm[i])) / (-2);
    }
    if (m != 0) printf("NO");

    return 0;
}


