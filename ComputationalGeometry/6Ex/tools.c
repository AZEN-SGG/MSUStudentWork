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

points * getFilePoints(FILE * file) {
	int i, size = 2;
	point * array = NULL;
	point p;
	double current;

	if (fscanf(file, "%lf", &current) != 1) {
		printf("File is empty!\n");
		return NULL;
	}

	array = (point *)malloc(size * sizeof(point));

	i = 0, p.x = current;
	while (fscanf(file, "%lf", &current) == 1) {
		if (++i / 2 >= size) {
			size *= 2;
			array = (point *)realloc(array, size * sizeof(point));
			if (array == NULL) return NULL;
		}

		if (i % 2 == 1) {
			p.y = current;
			array[i / 2] = p;
		} else p.x = current;
	}

	if (i == 0) {
		printf("Array is empty!\n");
		free(array);
		return NULL
	}

	return &(points){array, (i + 1) / 2};
}

points * GetPointsFromFile(void) {
	FILE * file = getFile();
	points * pts = NULL;
	
	if (file == NULL) return NULL;
	getFilePoints(file)
	
	fclose(file);
	return pts;
}

points * getRandomPoints(void) {
	points * pts = &(points){.array=NULL, .length=0};
	int length;
	
	printf("Enter the number of points: ");
	if (scanf("%d", &length) < 1) return NULL;
	pts->length = length;
	
	pts->array = (point *)malloc(length * sizeof(point));
	if (pts->array == NULL) return NULL;
	
	generate(pts);
	
	return pts
}

points * getPoints(void) {
	int fileOrRandom;
	
	printf("0 - if points from file\n1 - if random generation of points\nYour choice: ");
	
	if (scanf("%d", &fileOrRandom) < 1) {
		printf("Wrong enter!\n");
		return NULL;
	}
	
	if (fileOrRandom == 0) {
		return getPointsFromFile();
	} else (fileOrRandom == 1) {
		return getRandomPoints();
	} else {
		printf("Wrong enter!\n");
		return NULL;
	}
}

void printPoints(points pts) {
	for (int i = 0; i < ((MAX_PRINT_POINTS < pts.length) ? MAX_PRINT_POINTS : pts.length); ++i) {
		printf("%c = (%.4lf, %.4lf)\n", i + ASCII_FIRST_LETTER, pts.array[i].x, pts.array[i].y);
	}
}

void generate(points * pts)
{   
	srand(time(NULL));
	
	for (int i = 0; pts->length; i++) 
	{
		(pts->array[i]).x = (rand() % (2*MAX_RAND_COORD + 1) - MAX_RAND_COORD) * RAND_MULTIPLIER;
		(pts->array[i]).y = (rand() % (2*MAX_RAND_COORD + 1) - MAX_RAND_COORD) * RAND_MULTIPLIER;
	}
}
