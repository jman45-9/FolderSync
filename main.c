#include "projectHeaders.h"

int newBin(char binName[50], char newBinContent[500]);
int removeBin(char binName[50]);

int main(int argc, char *argv[])
{
    //* getting named params
    char operation[50];
    char binName[50];
    char newBinContent[500];
    for (int i = 1; i < argc; i += 2)
    {
        if (i + 1 >= argc)
        {
            printf("Please Enter a value for: %s\n", argv[i]);
            continue;
        }

        if (!strcmp(argv[i], "--operation"))
        {
            strcpy(operation, argv[i + 1]);
        }
        else if (!strcmp(argv[i], "--binName"))
        {
            strcpy(binName, argv[i + 1]);
        }
        else if (!strcmp(argv[i], "--newBinContent"))
        {
            strcpy(newBinContent, argv[i + 1]);
        }
        else
        {
            printf("%s is not a valid parameter.\n", argv[i]);
            printf("Use '--operation help' for a list of valid parameters\n");
            return 0;
        }
    }

    // if (newBin(binName, newBinContent))
    // return 1;

    if (removeBin(binName))
        return 1;

    return 0;
}

int newBin(char binName[50], char newBinContent[500])
{
    if (!checkValidPath(newBinContent))
    {
        printf("Please enter a valid path with '--newBinContent'");
        return 1;
    }

    char *binsPath = malloc(sizeof(char) * 500);
    getConfigValue("binsPath", &binsPath);

    if (!checkValidPath(binsPath))
    {
        printf("Please reconfigure 'binsPath' with a valid path");
        free(binsPath);
        return 1;
    }
    // Create new directory
    char command[500];
    strcpy(command, "mkdir ");
    strcat(command, binsPath);
    strcat(command, "\\");
    strcat(command, binName);
    system(command);

    // Add contents to new directory
    strcpy(command, "copy ");
    strcat(command, newBinContent);
    strcat(command, " ");
    strcat(command, binsPath);
    strcat(command, "\\");
    strcat(command, binName);
    system(command);

    free(binsPath);
    return 0;
}

int removeBin(char binName[50])
{
    char *binPath = malloc(sizeof(char) * 500);
    getConfigValue("binsPath", &binPath);
    strcat(binPath, "\\");
    strcat(binPath, binName);
    if (!checkValidPath(binPath))
    {
        printf("Please enter a valid bin name. Use '--operation list' for a list of bins");
        free(binPath);
        return 1;
    }

    char command[500];
    strcpy(command, "rmdir /s /q ");
    strcat(command, binPath);
    system(command);

    free(binPath);
    return 0;
}