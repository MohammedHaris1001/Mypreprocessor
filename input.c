#include <stdio.h>
#include "myheader.h"
#define square(x) ((x)*(x))
// Simple macro
#define NUM 10

/* Main function to test
   the preprocessor */

int main()
{
    int a = NUM;
    int result=square(5);

    // Display the result
    printf("Value = %d\n", a);

    printf("Addition = %d\n", add(10, 20));

    return 0;
}
