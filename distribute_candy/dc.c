#include <stdio.h>

#define MAX_NUM (100)
#define TRUE (1)
#define FALSE (0)

int is_equal(short *candies, int num); 

int main(void)
{
	int n;
	int i;
	int supply = 0;
	short candy[MAX_NUM];
	short shift[MAX_NUM];

	/*
	** read the number of children
	*/
	while(scanf("%d", &n) == 1)
	{
		/*
		** and the initial candies
		*/
		for(i = 0; i < n; ++i)
		{
			scanf("%d", &candy[i]);
		}

		/*
		** distribute candies
		*/
		while(!is_equal(candy, n))
		{
			for(i = 0; i < n; ++i)
			{
				candy[i] /= 2;
				shift[i] = candy[i];
			}

			for(i = 0; i < n; ++i)
			{
				candy[(i + 1) % n] += shift[i];
			}

			/*
			** teacher supply candies to the
			** children who have odd number of candies
			*/
			for(i = 0; i < n; ++i)
			{
				if(candy[i] % 2)
				{
					++candy[i];
					++supply;
				}
			}
		}
		printf("%d\n", supply);
	}

	return 0;
}

int is_equal(short *candies, int num)
{
	int i;
	for(i = 1; i < num; ++i)
	{
		if(candies[i] != candies[i - 1])
		{
			return FALSE;
		}
	}

	return TRUE;
}