#include "hope.h"

circle hope(point * ps, int length) {
	circle crcl;
	
	for (int i = 0; i < length; ++i) {
		point temp = ps[i];
		ps[i] = ps[length - 1];
		ps[length - 1] = temp;
		
		for (int j = 0; j < length - 1; ++j) {
			crcl = centermass(temp, ps[i]);
			if (isSuit(crcl, ps, length - 1)) return crcl;
		}

		ps[length - 1] = ps[i];
		ps[i] = temp;
	}

	for (int i = 0; i < length; ++i) {
		point temp = ps[i];
		ps[i] = ps[length - 1];
		ps[length - 1] = temp;

		for (int j = 0; j < length - 1; ++j) {	
			temp = ps[j];
			ps[j] = ps[length - 2];
			ps[length - 2] = temp;

			for (int k = 0; k < length - 2; ++k) {
				point warp[] = {ps[length - 1], ps[length - 2], ps[k]};
				crcl = byThreePoints(warp);

				if (fabs(crcl.radius + 1) > exp && isSuit(crcl, ps, length - 2)) return crcl;
			}

			temp = ps[j];
			ps[j] = ps[length - 2];
			ps[length - 2] = temp;
		}
	
		temp = ps[i];
		ps[i] = ps[length - 1];
		ps[length - 1] = temp;
	}

	return (circle){.center=(point){0, 0}, .radius=0};
}

bool isSuit(circle crcl, point * ps, int length) {
	for (int i = 0; i < length; ++i) if (!belongs(crcl, ps[i])) return false;
	return true;
}
