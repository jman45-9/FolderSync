#include "fileops.h"

char *getConfigValue(char configKey[50])
{
    FILE *configFile = fopen("config.yaml", "r");
    char *configValue[500];
    int foundValue = 0;
    while (!foundValue)
    {
        char *currentKey[50];
        fscanf(configFile, "%s", currentKey);
        if (!strcmp(configKey, currentKey))
        {
            fscanf(configFile, "%s", configValue);
            foundValue = 1;
        }
    }
    fclose(configFile);
    return configValue;
}