#include "tools.h"

FILE * getFile(void)
{
    FILE * file;
    char filename[50];

    printf("Enter filename: ");
    if (scanf("%s", filename) == 1)
    {
        file = fopen(filename, "r");
        if (file == NULL) {
            printf("Error file!\n");
            return NULL;
        } else {
            return file;
        }
    } else
    {
        printf("Empty name!\n");
        return NULL;
    }
}
