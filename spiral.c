#include <stdio.h>

    int main()
    {

        int n;
        scanf("%d", &n);

        int i, j, N;
        int tab[n][n];
        int left, top;

        left = 0;
        top  = n - 1;
        N    = 1;

        for(i = 1; i <= n/2; i++, left++, top--)
        {
            for(j = left; j <= top; j++, N++) tab[left][j] = N;
            for(j = left+1; j <= top; j++, N++) tab[j][top] = N;
            for(j = top-1; j >= left; j--, N++) tab[top][j] = N;
            for(j = top-1; j >= left+1; j--, N++) tab[j][left] = N;

        }

        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                printf("%d ", tab[i][j]);
            }
            printf("\n");
        }

        return 0;
    }

