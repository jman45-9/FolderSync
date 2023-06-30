#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    //* getting named params
    char operation[50];
    char binName[50];
    char newBinPath[200];
    for (int i = 1; i < argc; i += 2)
    {
        if (i + 1 >= argc)
        {
            printf("Please Enter a value for: %s\n", argv[i]);
            continue;
        }

        if (strcmp(argv[i], "--operation") == 0)
        {
            strcpy(operation, argv[i + 1]);
        }
        else if (strcmp(argv[i], "--binName") == 0)
        {
            strcpy(binName, argv[i + 1]);
        }
        else if (strcmp(argv[i], "--newBinPath") == 0)
        {
            strcpy(newBinPath, argv[i + 1]);
        }
        else
        {
            printf("%s is not a valid parameter.\n", argv[i]);
            printf("Use '--operation help' for a list of valid parameters\n");
            return 0;
        }
    }

        return 0;
}
