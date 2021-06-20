#include<stdio.h>

int power(int a, int b) {
    int p = 1;
    for (int i = 0; i < b; i++) {
        p *= a;
    }
    return p;
}

int narc(int a, int m, int b) {
    int sum = 0;
    int copy_a = a;
    while (copy_a) {
        int d = copy_a % b;
        copy_a /= b;
        sum += power(d, m);
    }
    return (sum == a);
}

void print_d(int a) {
    if (a >= 0 && a <= 9) printf("%d", a);
    if (a == 10) printf("A");
    if (a == 11) printf("B");
    if (a == 12) printf("C");
    if (a == 13) printf("D");
    if (a == 14) printf("E");
    if (a == 15) printf("F");
}

void print_n(int a, int b) {
    int i = 1;
    while (a >= power(b, i)) i++;
    for (i; i >= 1; i--) {
        int k = a / power(b, i - 1);
        print_d(k);
        a -= k * power(b, i - 1);
    }
    printf(" ");
}

int main() {

    int m, b;
    scanf("%d%d", &m, &b);

    int r = 0;

    for (int i = power(b, m - 1); i < power(b, m); i++) {
        if (narc(i, m, b)) {
            print_n(i, b);
            r = 1;
        }
    }

    if (r == 0) printf("NO");

    return 0;
}
