#include <stdio.h>

#define MAX 158

int multiply(int x, int tab[], int tab_size)
{
    int c = 0;

    for (int i = 0; i < tab_size; i++)
    {
        int a = tab[i] * x + c;
        tab[i] = a % 10;
        c  = a / 10;
    }

    while (c)
    {
        tab[tab_size] = c % 10;
        c = c / 10;
        tab_size++;
    }
    return tab_size;
}

void factorial(int n)
{
    int tab[MAX];

    tab[0] = 1;
    int tab_size = 1;

    for (int x = 2; x <= n; x++)
        tab_size = multiply(x, tab, tab_size);

    for (int i = tab_size - 1; i >= 0; i--) printf("%d", tab[i]);
}


int main() {

    int n;
    scanf("%d", &n);

    factorial(n);

    return 0;
}

