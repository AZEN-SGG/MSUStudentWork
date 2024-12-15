#ifndef TYPES
#define TYPES

#define eps 1.e-6

#define ARR(TYPE, NAME) \
	typedef struct {\
		TYPE * arr;\
		int len;\
	} NAME


	
typedef struct {
	double x;
	double y;
} point;

typedef struct {
	point start;
	point direction;
} line;

ARR(point, points);
ARR(line, lines);

typedef struct {
	points pts;
} polygon;

#endif
