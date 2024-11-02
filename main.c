#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char* login = getenv("USER");
    if (login != NULL) {
        printf("%s\n", login);
    }
    printf("Hello, World!\n");
    return EXIT_SUCCESS;
}
