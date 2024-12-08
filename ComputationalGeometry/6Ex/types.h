#ifndef TYPES
#define TYPES

typedef struct {
	double x;
	double y;
} point;

typedef struct {
	point * array;
	int length;
} points;

typedef struct {
	point center;
	double radius;
} circle;

#endif
