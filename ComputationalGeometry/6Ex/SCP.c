#include "SCP.h"

circle MEC(point * I, int ilen, point * N, int nlen) {
	if (ilen != 0 && nlen < 3) {
		point rnd = I[ilen - 1];
		circle crcl = MEC(I, ilen - 1, N, nlen);

		if (belongs(crcl, rnd)) return crcl;
		else {
			N[nlen++] = rnd;
			return MEC(I, ilen - 1, N, nlen);
		}
	} else return primitive(N, nlen);
}

bool belongs(circle crcl, point p) {
	if (powd(p.x - crcl.center.x) + powd(p.y - crcl.center.y) <= exp + powd(crcl.radius)) return true;
	return false;
}

double powd(double number) {
	return number * number;
}

circle primitive(point * N, int nlen) {
	if (nlen == 3) {
		for (int i = 0; i < 3; ++i) {
            for (int j = i + 1; j < 3; ++j) {
                circle crcl = centermass(N[i], N[j]);
                bool all_inside = true;

                for (int k = 0; k < 3; ++k) {
                    if (!belongs(crcl, N[k])) {
                        all_inside = false;
                        break;
                    }
                }
                if (all_inside) {
                    return crcl;
                }
            }
        }
		
		return byThreePoints(N);
	} else if (nlen == 2) {
		return centermass(N[0], N[1]);
	} else if (nlen == 1) {
		return (circle){N[0], 0};
	} else {
        return (circle){(point){0, 0}, 0};
	}
}

circle centermass(point p1, point p2) {
	return (circle){(point){(p1.x + p2.x) / 2, (p1.y + p2.y) / 2}, distance(p1, p2) / 2};
}

circle byThreePoints(point * warp) {
	point center = getCenter(warp);
	double radius;

	center.x += warp[0].x, center.y += warp[0].y;
	radius = distance(center, warp[0]);
	
	return (circle){center, radius};
}

point getCenter(point * warp) {
	double sqrt1, sqrt2, scalar;
	point vec1 = (point){warp[1].x - warp[0].x, warp[1].y - warp[0].y};
	point vec2 = (point){warp[2].x - warp[0].x, warp[2].y - warp[0].y};
	
	sqrt1 = vec1.x * vec1.x + vec1.y * vec1.y;
	sqrt2 = vec2.x * vec2.x + vec2.y * vec2.y;
	scalar = (vec1.x * vec2.y - vec2.x * vec1.y) * 2;

	return (point){.x=((vec2.y * sqrt1 - vec1.y * sqrt2) / scalar), \
			.y=((vec1.x * sqrt2 - vec2.x * sqrt1) / scalar)};	
}

double straightAngle(point p1, point p2) {
	return (p1.y - p2.y) / (p1.x - p2.x);
}

double distance(point p1, point p2) {
	return sqrt(powd(p1.x - p2.x) + powd(p1.y - p2.y));
}

void printCircle(circle crcl) {
	printf("(x - %.4lf)^2 + (y - %.4lf)^2 = %.4lf^2\n\n", crcl.center.x, crcl.center.y, crcl.radius);
	printf("Center of circle at point (%.2lf, %.2lf)\nRadius is %.2lf\n", crcl.center.x, crcl.center.y, crcl.radius);
}

int isCover(circle crcl, points pts) {
	for (int i = 0; i < pts.length; ++i) {
		if (!belongs(crcl, pts.array[i])) return i;
	}
	
	return pts.length;
}