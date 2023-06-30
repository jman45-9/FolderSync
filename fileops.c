#include "fileops.h"
#include <windows.h>

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
        if (fgetc(configFile) == EOF)
            foundValue = 1;
        fseek(configFile, -1, SEEK_CUR);
        char trash[600];
        fgets(trash, 600, configFile);
    }
    fclose(configFile);
}

// @param path: file path to check validity of
int checkValidPath(char path[])
{
    DWORD fileAttributes = GetFileAttributes(path);

    if (fileAttributes != INVALID_FILE_ATTRIBUTES &&
        (fileAttributes & FILE_ATTRIBUTE_DIRECTORY))
    {
        return 1;
    }
    return 0;
}