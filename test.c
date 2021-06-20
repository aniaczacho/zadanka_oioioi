#include <stdio.h>

void zmien(int t[5]) {
    t[3] = 0;
}

int main() {

    int t[5] = {0, 1, 2, 3, 4, 5};
    zmien(t);
    for (int i = 0; i < 5; i++) printf("%d ", t[i]);

    return 0;
}

