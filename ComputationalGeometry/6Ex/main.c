#include "tools.h"
#include "SCP.h"
#include "hope.h"

int main(void) {
	points ps;
	point N[3];
	circle crcl;
	FILE * file = getFile();
	if (file == NULL) return -1;	
	
	ps = getPoints(file);
	if (ps.array == NULL) return -2;
	
	printf("\nPoints:\n");	
	for (int i = 0; i < ps.length; ++i) printf("(%.2lf, %.2lf) ", ps.array[i].x, ps.array[i].y);
	printf("\n\n");
	
	printf("Fast algorithm:\n");
	crcl = MEC(ps.array, ps.length, N, 0);
	printCircle(crcl);
	
	printf("\n");
	
	printf("Reliable algorithm:\n");
	crcl = hope(ps.array, ps.length);
	printCircle(crcl);

	free(ps.array);	

	return 0;
}
