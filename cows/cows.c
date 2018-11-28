#include <stdio.h>
#include <string.h>

#define MAX_COWS  (4)
#define MAX_COW_INDEX (3)

int main(int argc, char **argv)
{
	int n, i;
	int sum;
	int cows[MAX_COWS] = { 0 };

	while((scanf("%d", &n) == 1) && (n > 0))
	{
		memset(cows, 0x00, sizeof(cows));
		cows[0] = 1;

		sum = 0;
		while(n > 1)
		{
			for(i =  MAX_COW_INDEX - 1; i >= 0; --i)
			{
				cows[i + 1] = cows[i];
			}
			cows[0] += cows[MAX_COW_INDEX];
			cows[MAX_COW_INDEX] = 0;
			--n;
		}

		for(i = 0; i < MAX_COWS; ++i)
			sum += cows[i];
		printf("%d\n", sum);
	}

	return 0;
}