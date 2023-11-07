// Orshak Ivan, 28.12.15

#ifndef COMPL_H
#define COMPL_H

typedef struct
{
	double Re, Im;
}COMPL;

COMPL CompSet(double A, double B);
COMPL CompAddCompl(COMPL A, COMPL B);
COMPL CompMuCompl(COMPL A, COMPL B);
double ComplNorm(COMPL Z);
int Iter(COMPL Z);

#endif /* COMPL_H */