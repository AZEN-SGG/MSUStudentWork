#include "tools.h"
#include "SCP.h"

int main(void) {
	points ps;
	point N[3];
	circle crcl;
	FILE * file = getFile();
	if (file == NULL) return -1;	
	
	ps = getPoints(file);
	if (ps.array == NULL) return -2;
	
	for (int i = 0; i < ps.length; ++i) printf("(%.2lf, %.2lf) ", ps.array[i].x, ps.array[i].y);
	printf("\n");

	crcl = MEC(ps.array, ps.length, N, 0);
	printCircle(crcl);

	free(ps.array);	

	return 0;
}
