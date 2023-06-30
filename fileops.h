#ifndef FILEOPS
#define FILEOPS

#include <stdio.h>
#include <string.h>

void getConfigValue(char configKey[], char **configValue);
int checkValidPath(char path[]);
FILE *getConfigPath();

#endif