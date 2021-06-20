#include <stdio.h>
#include <math.h>

int main() {

    int n, m;
    scanf("%d%d", &n, &m);

    int res = 0;

    int max_ = pow(2, n);
    for (int i = 1; i < max_; i++) {
        if (i % m != 0) {
            int x = 1;
            for (int j = 0; j < n; j++) {
                if ((i ^ x) % m == 0 && (i ^ x) != 0) {
                    res++;
                    break;
                }
                x <<= 1;
            }
        }
    }

    printf("%d", res);

}
