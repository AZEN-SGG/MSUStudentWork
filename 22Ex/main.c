#include <stdio.h>
#include "tools.h"
#include "make_increasing.h"

/*
23 Task
Example:
1 2 3 4 5 - possible
2 1 3 5 4 - impossible
*/

int main(void) {
    FILE * file = getFile();
    if (file == NULL) return 1;
    if (makeIncreasing(file) != TRUE) {
        printf("No, it is impossible");
        return 1;
    } else printf("Yes, it is possible");

    return 0;
}
