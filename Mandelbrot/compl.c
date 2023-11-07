// Orshak Ivan, 28.12.15

#include "compl.h"
#include <math.h>

COMPL CompSet(double A, double B)
{
	COMPL R;

	R.Re = A;
	R.Im = B;

	return R;
}

COMPL CompAddCompl(COMPL A, COMPL B)
{
	COMPL R;

	R.Re = A.Re + B.Re;
	R.Im = A.Im + B.Im;

	return R;
}

COMPL CompMuCompl(COMPL A, COMPL B)
{
	COMPL R;

	R.Re = A.Re * B.Re - A.Im * B.Im;
	R.Im = A.Re * B.Im + B.Re * A.Im;

	return R;
}

double ComplNorm(COMPL Z)
{
	return sqrt(Z.Re * Z.Re + Z.Im * Z.Im);
}

int Iter(COMPL Z)
{
	COMPL constant;
	int n = 0;

	constant = Z;

	while (n < 255 && ComplNorm(Z) < 2)
	{
		Z = CompAddCompl(CompMuCompl(Z, Z), constant);
		n++;
	}

	return n;
}