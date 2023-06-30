#include "fileops.h"

// @param configKey: the key of the key-value pair in the yaml file w/o colon
// @param configValue: pointer to the string where you want to store the value of the pair
void getConfigValue(char configKey[], char **configValue)
{
    FILE *configFile = fopen("config.yaml", "r");
    int foundValue = 0;
    char fullConfigKey[50];
    strcpy(fullConfigKey, configKey);
    strcat(fullConfigKey, ":");

    while (!foundValue)
    {
        char currentKey[50];
        fscanf(configFile, "%s", currentKey);
        if (!strcmp(fullConfigKey, currentKey))
        {
            fscanf(configFile, "%s", *configValue);
            foundValue = 1;
        }
        char trash[600];
        fgets(trash, 600, configFile);
    }
    fclose(configFile);
}
