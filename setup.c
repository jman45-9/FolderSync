#include <stdio.h>
#include <string.h>

int binSetup()
{
    printf("Where would you like your bins?: ");
    char binPath[500];
    scanf("%s", binPath);
}

int main(int argc, char *argv[])
{
    binSetup();
    return 0;
}