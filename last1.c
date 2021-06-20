#include <stdio.h>

long long sum(long long n) {
    long long sum = 0;
    while (n != 0) {
        sum += n;
        n /= 10;
    }
    return sum;
}

void bin_search(long long a, long long b, long long n) {
    if (b < a) {
        printf("%d", -1);
        return;
    }
    long long c = (a + b)/2;
    long long x = sum(c);
    if (x == n) {
        printf("%lli", c);
        return;
    }
    else if (x > n) {
        bin_search(a, c-1, n);
    }
    else {
        bin_search(c+1, b, n);
    }
}

int main() {

    long long n;
    scanf("%lli", &n);

    bin_search(0, n, n);

    return 0;

}
