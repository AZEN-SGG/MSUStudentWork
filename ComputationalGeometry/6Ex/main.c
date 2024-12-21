#include "tools.h"
#include "SCP.h"
#include "hope.h"
#include <time.h>

int main(void) {
	points pts;
	point N[3];
	circle crcl;
	int numLose, timer;
	
	pts = getPoints();
	if (pts.array == NULL) return -1;

	printPoints(pts);

	printf("\nFast algorithm:\n");
	timer = -clock();
	crcl = MEC(pts.array, pts.length, N, 0);
	timer += clock();
	printCircle(crcl);
	
	if ((numLose = isCover(crcl, pts)) == pts.length) printf("\nThe circle covers all the points!\n");
	else printf("\nThe circle misses a maximum of %d points\n", pts.length - numLose);
	
	printf("Quick search took about %3.0lf seconds %3.0lf milliseconds\n", (double)timer / CLOCKS_PER_SEC, (double)(timer % CLOCKS_PER_SEC) / (CLOCKS_PER_SEC / 1000));

	printf("\nReliable algorithm:\n");
	timer = -clock();
	crcl = hope(pts.array, pts.length);
	timer += clock();
	printCircle(crcl);
	
	if (isCover(crcl, pts) == pts.length) printf("\nThe circle covers all the points!\n");
	else printf("\nThe circle misses a maximum of %d points\n", pts.length - numLose);

	printf("Slow search took about %3.0lf seconds %3.0lf milliseconds\n", (double)timer / CLOCKS_PER_SEC, (double)(timer % CLOCKS_PER_SEC) / (CLOCKS_PER_SEC / 1000));

	free(pts.array);	

	return 0;
}
