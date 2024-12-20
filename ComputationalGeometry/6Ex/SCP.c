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
		point temp;
		circle crcl;

		for (int i = 0; i < nlen; ++i) {
			temp = N[2];
			N[2] = N[i];
			N[i] = temp;

			crcl = centermass(N[0], N[1]);
			if (belongs(crcl, N[2])) return crcl;

			N[i] = N[2];
			N[2] = temp;
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
	point center;
	double radius, x, y;
	double ang_a;
	double ang_b;
	
	if (fabs(warp[1].x - warp[0].x) < exp || fabs(warp[2].x - warp[1].x) < exp) return (circle){.center=(point){0, 0}, .radius=-1};

	ang_a = straightAngle(warp[1], warp[0]);
	ang_b = straightAngle(warp[2], warp[1]);

	if (fabs(ang_b) < exp || fabs(ang_b - ang_a) < exp) {
		return (circle){.center=(point){0, 0}, .radius=-1};
	}

	x = (ang_a * ang_b * (warp[0].y - warp[2].y) + ang_b * (warp[0].x + warp[1].x) - ang_a * (warp[1].x + warp[2].x)) / (2 * (ang_b - ang_a));
	y = (-(1/ang_b) * (x - (warp[1].x + warp[2].x) / 2) + (warp[1].y + warp[2].y) / 2);
	center = (point){x, y};

	radius = distance(center, warp[0]);
	return (circle){center, radius};
}

double straightAngle(point p1, point p2) {
	return (p1.y - p2.y) / (p1.x - p2.x);
}

double distance(point p1, point p2) {
	return sqrt(powd(p1.x - p2.x) + powd(p1.y - p2.y));
}

void printCircle(circle crcl) {
	printf("(x - %.4lf)^2 + (y - %.4lf)^2 = %.4lf^2\n", crcl.center.x, crcl.center.y, crcl.radius);
	// printf("Center of circle at point (%.2lf, %.2lf)\nRadius is %.2lf\n", crcl.center.x, crcl.center.y, crcl.radius);
}

