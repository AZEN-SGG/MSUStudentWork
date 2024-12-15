#ifndef TYPES
#define TYPES

#define eps 1.e-6

#define ARR(TYPE, NAME) \
	typedef struct {\
		TYPE * arr;\
		int len;\
	} NAME

#define DELFUNC(NAME, TYPE) \
	void del##NAME(TYPE * array, int index) { \
		DEL(array->arr, index, array->len) \
		array -> len--; \
	}

#define DEL(DATA, INDEX, LEN) \
	for (int i = INDEX; i < (LEN) - 1; ++i) { \
		(DATA)[i] = (DATA)[i + 1]; \
	}
	
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
