#include <math.h>
#include <stdlib.h>
#include "punto.h"

struct pto {
	float x;
	float y; };

punto CreaPunto(float x,float y)
{
	punto p=malloc(sizeof(*p));
	p->x=x;
	p->y=y;
	return p;
}

float Ascissa(punto p)
{
	return p->x;
}

float Ordinata(punto p)
{
	return p->y;
}

float Distanza(punto p1,punto p2)
{
	float dx=p1->x-p2->x;
	float dy=p1->y-p2->y;
	float d=sqrt(dx*dx+dy*dy);
	return d;
}
