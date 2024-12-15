#include "polygon.h"

line getLine(point pt1, point pt2) {
	return (line){.start=pt1, .direction=(point){pt2.x - pt1.x, pt2.y - pt1.y}}; 
}	

lines getLines(points pts) {
	line * lns = (line *)malloc(pts.len * sizeof(line));
	int len = pts.len;

	for (int i = 0; i < len; ++i) {
		lns[i] = getLine(pts.arr[i], pts.arr[(i + 1) % len]);
	}

	return (lines){lns, len};
}

points getVectors(points pts) {
	point * vectors = (point *)malloc(pts.len * sizeof(point));
	int len = pts.len;
	point vector;
	double vlen;

	for (int i = 0; i < len; ++i) {
		vector = normal(getLine(pts.arr[i], pts.arr[(i + 1) % len]));
		vlen = vector_len(vector);

		vector.x /= vlen, vector.y /= vlen;
		
		vectors[i] = vector;
	}

	return (points){vectors, len};
}

point normal(line ln) {
	return (point){ln.direction.y, -ln.direction.x};
}

double vector_len(point vector) {
	return sqrt(qpow(vector.x) + qpow(vector.y));
}

double qpow(double number) {
	return number * number;
}

void repairPolygon(polygon * plgn) {
	lines lns = getLines(plgn -> pts);
	int len = lns.len;

	for (int i = 0; i < len; ++i) { 
		point fdirect = lns.arr[i].direction;
		point sdirect = lns.arr[(i + 1) % len].direction;
		
		if (isNull(fdirect)) {
			polygonDelPoint(plgn, i), --len;
			delLine(&lns, i--);
			fdirect = sdirect, sdirect = lns.arr[(i + 1) % len].direction;
		}
		
		if (isCollinear(fdirect, sdirect)) {
			polygonDelPoint(plgn, i), --len;
			delLine(&lns, i--);
		}
	}

	free(lns.arr);
}       

bool isNull(point vector) {
	return (fabs(vector.x) < eps && fabs(vector.y) < eps);
}

void polygonDelPoint(polygon * plgn, int index) {
	delVector(&(plgn -> pts), index);
}

bool isCollinear(point fvec, point svec) {
	return fabs(fabs(fvec.x * svec.x + fvec.y * svec.y) - (vector_len(fvec) * vector_len(svec))) < eps;
}

DELFUNC(Vector, points)

DELFUNC(Line, lines)

polygon getPolygon(polygon * plgn, double shift) {
	points vectors = getVectors(plgn -> pts);
	int secind, len = plgn -> pts.len;
	point * pts = (point *)malloc(len * sizeof(point));

	memcpy(pts, plgn -> pts.arr, len * sizeof(point));

	for (int i = 0; i < len; ++i) {
		vectors.arr[i].x *= shift;
		vectors.arr[i].y *= shift;

		secind = ((i + 1) % len);
			
		pts[i].x += vectors.arr[i].x;
		pts[secind].x += vectors.arr[i].x;
		
		pts[i].y += vectors.arr[i].y;
		pts[secind].y += vectors.arr[i].y;
	}

	free(vectors.arr);

	return (polygon){(points){pts, len}};
}

