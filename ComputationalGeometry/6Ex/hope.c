#include "hope.h"

circle hope(point * ps, int length) {
	circle crcl;
	circle minimum = (circle){(point){0, 0}, 0};
	
	if (length == 1) {
		return (circle){ps[0], 0};
	} else if (length < 1) {
		return minimum;
	}
	
	for (int i = 0; i < length; ++i) {
		point temp = ps[0];
		
		for (int i = 1; i < length; ++i) ps[i - 1] = ps[i];
		ps[length - 1] = temp;
		
		for (int j = 0; j < length - 1; ++j) {
			crcl = centermass(temp, ps[j]);
			if (isCover(crcl, (points){ps, length}) == length) {
				if (minimum.radius < exp || (minimum.radius - crcl.radius > exp)) {
					minimum = crcl;
				}
			}
		}
	}

	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length - 1; ++j) {	
			for (int k = 0; k < length - 2; ++k) {
				point warp[] = {ps[i], ps[j], ps[k]};
				crcl = byThreePoints(warp);

				if ((fabs(crcl.radius + 1) > exp) && (isCover(crcl, (points){ps, length}) == length)) {
					if (minimum.radius < exp || (minimum.radius - crcl.radius > exp)) {
						minimum = crcl;
					}
				}
			}
		}
	}

	return minimum;
}

bool isSuit(circle crcl, point * ps, int length) {
	for (int i = 0; i < length; ++i) if (!belongs(crcl, ps[i])) return false;
	return true;
}
