#include "tools.h"
#include "SCP.h"
#include "hope.h"

int main(void) {
	points * pts;
	point N[3];
	circle crcl;
	
	pts = getPoints(file);
	if (pts == NULL) return -1;
	
	/*
	printf("\nPoints:\n");	
	for (int i = 0; i < ps.length; ++i) printf("(%.2lf, %.2lf) ", ps.array[i].x, ps.array[i].y);
	printf("\n\n");
	*/

	printPoints(*pts);

	printf("\nFast algorithm:\n");
	crcl = MEC(ps->array, ps->length, N, 0);
	printCircle(crcl);
	
	printf("\nReliable algorithm:\n");
	crcl = hope(ps->array, ps->length);
	printCircle(crcl);

	free(ps->array);	

	return 0;
}
