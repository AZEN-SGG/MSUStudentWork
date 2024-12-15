#include "tools.h"
#include "polygon.h"

int main(void) {
	points ps;
	double shift;
	polygon plgn, new_polygon;
	FILE * file = getFile();
	if (file == NULL) return -1;	
	
	ps = getPoints(file);
	if (ps.arr == NULL) return -2;
	if (ps.len < 3) {
		printf("Incorrect polygon!\n");
		return -4;
	}
	
	shift = getShift();
	
	if (-eps < shift && shift < eps) return -3;
	
	plgn.pts = ps;
	repairPolygon(&plgn);

	if (plgn.pts.len <= 1) {
		printf("Incorrect polygon!\n");
		return -4;
	}

	printPolygon(plgn, "\nOriginal polygon:\n");

	new_polygon = getPolygon(&plgn, shift);
	
	printPolygon(new_polygon, "\n\nNew polygon:\n");

	free(ps.arr);
	free(new_polygon.pts.arr);

	return 0;
}
