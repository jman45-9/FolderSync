#include "projectHeaders.h"

int binSetup(FILE *configFile)
{
    printf("Where would you like your bins?: ");
    char binPath[500];
    scanf("%s", binPath);
    fprintf(configFile, "binPath: %s\n", binPath);
}

int main(int argc, char *argv[])
{
    FILE *configFile = fopen("config.yaml", "w");
    binSetup(configFile);
    fclose(configFile);
    return 0;
}