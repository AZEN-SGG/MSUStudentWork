#include "tools.h"

FILE * getFile(void) {
	char filename[50];

	printf("Enter file name: ");
	if (scanf("%s", filename) == 1) {
		FILE * file = fopen(filename, "r");
		if (file == NULL) {
			printf("Error file!\n)");
			return NULL;
		} else {
			return file;
		}
	} else {
		printf("Empty name!\n");
		return NULL;
	}
}

points getPoints(FILE * file) {
	int i, size = 2;
	point * array = NULL;
	point p;
	double current;

	if (fscanf(file, "%lf", &current) != 1) {
		printf("File is empty!\n");
		return (points){.arr=NULL, 0};
	}

	array = (point *)malloc(size * sizeof(point));

	i = 0, p.x = current;
	while (fscanf(file, "%lf", &current) == 1) {
		if (++i / 2 >= size) {
			size *= 2;
			array = (point *)realloc(array, size * sizeof(point));
		}

		if (i % 2 == 1) {
			p.y = current;
			array[i / 2] = p;
		} else p.x = current;
	}

	if (i == 0) {
		printf("Array is empty!\n");
		return (points){.arr=NULL, 0};
	}

	return (points){array, (i + 1) / 2};
}

double getShift(void) {
	double shift;

	printf("Enter the Shift: ");

	if (scanf("%lf", &shift) == 1) return shift;
	else {
		printf("\nThe Shift is zero!\n");
		return 0;
	}
}

void printPolygon(polygon plgn, const char * str) {
	printf("%s", str);

	for (int i  = 0; i < plgn.pts.len; ++i) {
		printf("%c = (%.2lf, %.2lf)\n", i + 65, plgn.pts.arr[i].x, plgn.pts.arr[i].y);
	}
}

