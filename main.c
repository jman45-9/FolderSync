#include "projectHeaders.h"

void newBin(char binName[50], char newBinContent[500]);
void removeBin(char binName[50]);
void listBins();
void getBinContent(char binName[50], char copyDest[500]);

int main(int argc, char *argv[])
{
    //* getting named params
    char operation[50];
    char binName[50];
    char newBinContent[500];
    char copyDest[500];
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
        else if (!strcmp(argv[i], "--copyDest"))
        {
            strcpy(copyDest, argv[i + 1]);
        }
        else
        {
            printf("%s is not a valid parameter.\n", argv[i]);
            printf("Use '--operation help' for a list of valid parameters\n");
            return 0;
        }
    }

    if (!strcmp("newBin", operation))
        newBin(binName, newBinContent);

    else if (!strcmp("rmBin", operation))
        removeBin(binName);

    else if (!strcmp("list", operation))
        listBins();

    else if (!strcmp("getBin", operation))
        getBinContent(binName, copyDest);

    else
        printf("Please use a valid operation. Use '--operation help' for a list of commands");

    return 0;
}

void newBin(char binName[50], char newBinContent[500])
{
    if (!checkValidPath(newBinContent))
    {
        printf("Please enter a valid path with '--newBinContent'");
        exit(1);
    }

    char *binsPath = malloc(sizeof(char) * 500);
    getConfigValue("binsPath", &binsPath);

    if (!checkValidPath(binsPath))
    {
        printf("Please reconfigure 'binsPath' with a valid path");
        free(binsPath);
        exit(1);
    }
    // Create new directory
    char command[500];
    strcpy(command, "mkdir ");
    strcat(command, binsPath);
    strcat(command, "\\");
    strcat(command, binName);
    system(command);

    // Add contents to new directory
    strcpy(command, "Xcopy ");
    strcat(command, newBinContent);
    strcat(command, " ");
    strcat(command, binsPath);
    strcat(command, "\\");
    strcat(command, binName);
    strcat(command, " /E /H /C /I");
    system(command);

    free(binsPath);
}

void removeBin(char binName[50])
{
    char *binPath = malloc(sizeof(char) * 500);
    getConfigValue("binsPath", &binPath);
    strcat(binPath, "\\");
    strcat(binPath, binName);
    if (!checkValidPath(binPath))
    {
        printf("Please enter a valid bin name. Use '--operation list' for a list of bins");
        free(binPath);
        exit(1);
    }

    char command[500];
    strcpy(command, "rmdir /s /q ");
    strcat(command, binPath);
    system(command);

    free(binPath);
}

void listBins()
{
    char *binsPath = malloc(sizeof(char) * 500);
    getConfigValue("binsPath", &binsPath);

    if (!checkValidPath(binsPath))
    {
        printf("Please reconfigure 'binsPath' with a valid path");
        free(binsPath);
        exit(1);
    }

    char driveLetter[3];
    *driveLetter = *binsPath;
    *(driveLetter + 1) = ':';
    *(driveLetter + 2) = '\0';
    system(driveLetter);

    char command[500];
    strcpy(command, "dir /ad /b ");
    strcat(command, binsPath);
    system(command);

    free(binsPath);
}

void getBinContent(char binName[50], char copyDest[500])
{
    if (!checkValidPath(copyDest))
    {
        printf("Please use a valid path for '--copyDest'");
        exit(1);
    }

    char *binPath = malloc(sizeof(char) * 500);
    getConfigValue("binsPath", &binPath);
    strcat(binPath, "\\");
    strcat(binPath, binName);
    if (!checkValidPath(binPath))
    {
        printf("Please enter a valid bin name. Use '--operation list' for a list of bins");
        free(binPath);
        exit(1);
    }

    char command[500];
    strcpy(command, "Xcopy ");
    strcat(command, binPath);
    strcat(command, " ");
    strcat(command, copyDest);
    strcat(command, " /E /H /C /I");
    printf("command: %s", command);
    system(command);

    free(binPath);
}