#include <stdio.h>

int value(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;

    return 0;
}

 int main() {

    char roman1[15];
    char roman2[15];
    scanf("%s%s", &roman1, &roman2);

     int num1 = 0;
     for (int i = 0; i < 15; i++) {
         int s1 = value(roman1[i]);
         if (i + 1 < 15) {
             int s2 = value(roman1[i + 1]);
             if (s1 >= s2) {
                 num1 += s1;
             } else {
                 num1 = num1 + s2 - s1;
                 i++;
             }
         } else {
             num1 = num1 + s1;
         }
     }

     int num2 = 0;
     for (int i = 0; i < 15; i++) {
         int s1 = value(roman2[i]);
         if (i + 1 < 15) {
             int s2 = value(roman2[i + 1]);
             if (s1 >= s2) {
                 num2 += s1;
             } else {
                 num2 = num2 + s2 - s1;
                 i++;
             }
         } else {
             num2 = num2 + s1;
         }
     }

     int num = num1 + num2;

     while(num != 0) {
         if (num >= 1000) {
             printf("M");
             num -= 1000;
         }
         else if (num >= 900) {
             printf("CM");
             num -= 900;
         }
         else if (num >= 500) {
             printf("D");
             num -= 500;
         }
         else if (num >= 400) {
             printf("CD");
             num -= 400;
         }
         else if (num >= 100) {
             printf("C");
             num -= 100;
         }
         else if (num >= 90) {
             printf("XC");
             num -= 90;
         }
         else if (num >= 50) {
             printf("L");
             num -= 50;
         }
         else if (num >= 40) {
             printf("XL");
             num -= 40;
         }
         else if (num >= 10) {
             printf("X");
             num -= 10;
         }
         else if (num >= 9) {
             printf("IX");
             num -= 9;
         }
         else if (num >= 5) {
             printf("V");
             num -= 5;
         }
         else if (num >= 4) {
             printf("IV");
             num -= 4;
         }
         else if (num >= 1) {
             printf("I");
             num -= 1;
         }

     }

     return 0;
 }