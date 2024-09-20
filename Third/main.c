#include <stdio.h>
#include "get_file.h"
#include "count_max_local.h"

int main(void)
{
    FILE * file = getFile();
    if (file == NULL) {
        return -1;
    }
    printf("Max length of local maximum is %d", getCountMaxLocal(file));
    return 0;
}
