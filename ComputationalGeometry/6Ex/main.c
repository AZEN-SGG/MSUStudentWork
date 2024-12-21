#include "tools.h"
#include "SCP.h"
#include "hope.h"

int main(void) {
	points pts;
	point N[3];
	circle crcl;
	int numLose;
	
	pts = getPoints();
	if (pts.array == NULL) return -1;

	printPoints(pts);

	printf("\nFast algorithm:\n");
	crcl = MEC(pts.array, pts.length, N, 0);
	printCircle(crcl);
	
	if ((numLose = isCover(crcl, pts)) == pts.length) printf("\nThe circle covers all the points!\n");
	else printf("\nThe circle misses a maximum of %d points", pts.length - numLose);
	
	printf("\nReliable algorithm:\n");
	crcl = hope(pts.array, pts.length);
	printCircle(crcl);
	
	if (isCover(crcl, pts) == pts.length) printf("\nThe circle covers all the points!\n");
	else printf("\nThe circle misses a maximum of %d points", pts.length - numLose);

	free(pts.array);	

	return 0;
}
