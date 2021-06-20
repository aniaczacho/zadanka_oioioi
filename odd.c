#include <stdio.h>

long long square(long long n) { return n * n; }

long long sum(long long n) {
    if (n == 0)
        return 0;
    if (n % 2 == 1) {
        return square((n + 1) / 2) + sum(n / 2);
    }
    else {
        return square(n / 2) + sum(n / 2);
    }
}

int main() {

    long long n;
    scanf("%lli", &n);

    printf("%lli", sum(n));

    return 0;
}