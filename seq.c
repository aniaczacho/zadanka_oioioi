#include <stdio.h>

char find_max(char s[51], int i, int l) {
    char x = s[i];
    for (int j = i+1; j < l; j++) {
        if (s[j] > x) x = s[j];
    }
    return x;
}

int main() {

    char s[51];
    for (int i = 0; i < 51; i++) s[i] = '\0';
    scanf("%s", &s);

    int l = 0;
    while (s[l] != '\0') l++;

    char res[l+1];
    for (int i = 0; i <= l; i++) res[i] = '\0';

    int c = 0;
    int i = 0;
    while (i < l) {
        res[c] = find_max(s, i, l);
        for (int j = i; j < l; j++) {
            if (s[j] == res[c]) {
                i = j+1;
                break;
            }
        }
        c++;
    }

    printf("%s", res);

    return 0;
}