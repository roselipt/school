/*  Let's learn about c strings!
*/

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>


int main () {

    char str[6];
    str[0] = 'h';
    str[1] = 'e';
    str[2] = 'l';
    str[3] = 'l';
    str[4] = '0';
    str[5] = '\0';
    printf("Hello world.\nO and" );
    printf("%s\n", str);
    printf("\n");
    return 0;
}