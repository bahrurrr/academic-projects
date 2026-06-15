#include <stdio.h>

int main ()
{
    int valid_operator = 1;
    char operator;
    float nom1, nom2, hasil;

    printf ("masukkan 2 buah bilang & sebuah operator\ndengan format(number1 operator number2) : ");
    scanf ("%f %c %f", &nom1, &operator, &nom2);

    switch (operator)
    {
    case '*':
        hasil = nom1 * nom2;
        break;
    case '/':
        hasil = nom1 / nom2;
        break;
    case '+':
        hasil = nom1 + nom2;
        break;
    case '-':
        hasil = nom1 - nom2;
        break;
    default :
        valid_operator = 0;
        break;
    }

   if (valid_operator)
   {
        printf("\n%g %c %g = %g\n", nom1, operator, nom2, hasil);
   }
   else
        printf("\nInvalid operator!\n");

    return 0;
}