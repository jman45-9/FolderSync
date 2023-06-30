#include "projectHeaders.h"

void binSetup(FILE *configFile);
void appDirectorySet(FILE *configFile);

int main(int argc, char *argv[])
{
    FILE *configFile = fopen("config.yaml", "w");
    fputs("# file contents are added when setup.exe is run\n", configFile);
    binSetup(configFile);
    appDirectorySet(configFile);
    fclose(configFile);
    return 0;
}

void binSetup(FILE *configFile)
{
    printf("Where would you like your bins?: ");
    char binPath[500];
    scanf("%s", binPath);
    fprintf(configFile, "binsPath: %s\n", binPath);
}

void appDirectorySet(FILE *configFile)
{
    printf("Where would you like this program?: ");
    char appPath[500];
    scanf("%s", appPath);
    fprintf(configFile, "appPath: %s\n", appPath);
}