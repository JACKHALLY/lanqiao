#include <stdio.h>
#include <limits.h>

int calculateCycleLength(int paraNumber);

int main(void)
{
	int num1, num2, i;
	int lowNumber, highNumber;
	int maxCycleLength = INT_MIN;
	int tmpCycleLength;

	while(scanf("%d %d", &num1, &num2) == 2)
	{
		maxCycleLength = INT_MIN;
		if(num1 > num2)
		{
			lowNumber = num2;
			highNumber = num1;
		}
		else
		{
			lowNumber = num1;
			highNumber = num2;
		}

		for(i = lowNumber; i <= highNumber; ++i)
		{
			tmpCycleLength = calculateCycleLength(i);
			if(tmpCycleLength > maxCycleLength)
			{
				maxCycleLength = tmpCycleLength;
			}

		}

		printf("%d %d %d\n", num1, num2, maxCycleLength);
	}

	return 0;
}

int calculateCycleLength(int paraNumber)
{
	int resultCycleLength = 1;

	while(paraNumber != 1)
	{
		if(paraNumber % 2 == 0)
		{
			paraNumber /= 2;
		}
		else
		{
			paraNumber = paraNumber * 3 + 1;
		}

		++resultCycleLength;
	}

	return resultCycleLength;
}