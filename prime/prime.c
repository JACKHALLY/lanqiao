#include <stdio.h>
#include <math.h>

#define TRUE  (1)
#define FALSE (0)

int isPrimeNumber(int paraNum);

int main(void)
{
	int n = 0;
	int i;
	scanf("%d", &n);
	if(n > 1)
	{
		for(i = 2; i <= n; ++i)
		{
			if(isPrimeNumber(i))
				printf("%d\n", i);
		}
	}
	return 0;
}

int isPrimeNumber(int paraNum)
{
	int i;

	if(paraNum < 1)
	{
		return FALSE;
	}

	for(i = 2; i <= sqrt(paraNum); ++i)
	{
		if(paraNum % i == 0)
			return FALSE;
	}

	return TRUE;
}