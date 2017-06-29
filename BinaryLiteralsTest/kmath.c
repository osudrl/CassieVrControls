#include <stdio.h>
#include "kmath.h"

int kpow(int base, int power)
{
	int ret = 1;
	for (int i = 0; i < power; i++)
	{
		ret = base * ret;
	}
	return ret;
}