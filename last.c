#include <stdio.h>

int sum(long long n) {
    long long sum = 0;
    while (n > 0) {
        sum += n;
        n -= n%10;
        n /= 10;
    }
    return sum;
}

int main() {

    long long s;
    scanf("%lli", &s);

    int dn = 0;
    long long st = s;
    while (st > 0) {
        st /= 10;
        dn++;
    }

    long long a = (9*(s+dn))/10+5;
    long long b = (9*s)/10-1;
    for (long long i = a; i >= b; i--) {
        if (sum(i) == s) {
            printf("%lli", i);
            return 0;
        }
    }

    printf("%d", -1);
    return 0;
}
