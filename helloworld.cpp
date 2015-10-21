#include <stdio.h>

int main(void)
{
        int a=1;

        while (a<5) {
                printf("%2d! ",a);
                a++;
                sleep(1);
        }

        return 0;
}
