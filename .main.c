#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
int main() {
    int *p;
    int value;

    value = 5;
    p = &value;

//    printf("%d\n",printf("Test char : %c\nTest string : %s\nTest pointeur : %p\nTest dec : %d\nTest int : %i\nTest unsigned : %u\n",'O',"Bonjour",p,10, 10, 10));
//     printf("%d\n",ft_printf("Test char : %c\nTest string : %s\nTest pointeur : %p\nTest dec : %d\nTest int : %i\nTest unsigned : %u\n",'O',"Bonjour",p,10, 10, 10));

   // printf("%d\n", ft_printf(" %p %p ", LONG_MIN, LONG_MAX));
    printf("%d\n", ft_printf(" %d ", -1));
    printf("%d\n", printf(" %d ", -1));


    // printf("%d",printf(" NULL %s NULL ", NULL));
    // printf("%d",printf(" %s ", "-"));

    // ft_printf("%X\n", 9247239);
    // printf("%X\n", value);

    // ft_printf("%p\n", p);
    // printf("%p\n", p);

    return 0;
}

