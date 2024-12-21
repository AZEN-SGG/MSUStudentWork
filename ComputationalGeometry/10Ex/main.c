#include "tools.h"
#include "polygon.h"
#include <time.h>

int main(void) {
	points ps;
	int timer;
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
	
	timer = -clock();
	new_polygon = getPolygon(&plgn, shift);
	timer += clock();

	printPolygon(new_polygon, "\n\nNew polygon:\n");
	printf("\nThe process took about %3.0lf seconds %3.0lf milliseconds", (double)timer / CLOCKS_PER_SEC, (double)(timer % CLOCKS_PER_SEC) / (CLOCKS_PER_SEC / 1000));

	free(ps.arr);
	free(new_polygon.pts.arr);

	return 0;
}
