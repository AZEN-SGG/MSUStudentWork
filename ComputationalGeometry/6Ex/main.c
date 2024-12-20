#include "tools.h"
#include "SCP.h"
#include "hope.h"

int main(void) {
	points pts;
	point N[3];
	circle crcl;
	
	pts = getPoints();
	if (pts.array == NULL) return -1;

	printPoints(pts);

	printf("\nFast algorithm:\n");
	crcl = MEC(pts.array, pts.length, N, 0);
	printCircle(crcl);
	
	printf("\nReliable algorithm:\n");
	crcl = hope(pts.array, pts.length);
	printCircle(crcl);

	free(pts.array);	

	return 0;
}
