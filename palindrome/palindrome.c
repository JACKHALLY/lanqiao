/*
观察数字：12321，123321  都有一个共同的特征，无论从左到右读还是从右向左读，都是相同的。这样的数字叫做：回文数字。 

本题要求你找到一些5位或6位的十进制数字。满足如下要求： 
该数字的各个数位之和等于输入的整数。

输入:
一个正整数  n  (10< n< 100),  表示要求满足的数位和。

输出:
若干行，每行包含一个满足要求的5位或6位整数。 
数字按从小到大的顺序排列。 
如果没有满足条件的，输出：-1

样例输入:
44

样例输出:
99899
499994
589985
598895
679976
688886
697796
769967
778877
787787
796697
859958
868868
877778
886688
895598
949949
958859
967769
976679
985589
994499
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGIT (9)

int count_palindrome(int ndigits, int sumlimit);

int main(void)
{
	int num1, num2;
	int sumlimit;

	while(scanf("%d", &sumlimit) == 1)
	{
		num1 = count_palindrome(5, sumlimit);
		num2 = count_palindrome(6, sumlimit);

		if(num1 == 0 && num2 == 0)
		{
			printf("-1\n");
		}
	}
	return 0;
}

int count_palindrome(int ndigits, int sumlimit)
{
	/* the continous odd and even number should have the same room */
	int nhalf = (ndigits + 1) / 2;

	/*
	** allocate one more room as a buffer
	** which makes it easy to program
	*/
	char *digits = malloc((nhalf + 1) * sizeof(char));
	int i, j;
	int count = 0;
	int sum = 0;

	if(digits == NULL)
	{
		/* fail to allocate the room for the digits */
		return count;
	}

	memset(digits, 0, (nhalf + 1) * sizeof(char));
	i = nhalf;
	digits[1] = 1;
	while(digits[1] <= MAX_DIGIT && i >= 1)
	{
		sum = 0;
		/* statistics the sum */
		for(j = 1; j <= nhalf; ++j)
		{
			sum += digits[j];
		}
		sum += sum;
		if(ndigits % 2 == 1)
		{
			/* odd ndigits, minus the middle digit */
			sum -= digits[nhalf];
		}

		/* check whether the sum satisfy the sumlimit */
		if(sum == sumlimit)
		{
			for(j = 1; j <= nhalf; ++j)
			{
				printf("%d", digits[j]);
			}
			/* even ndigits, the middle digit emerge twice */
			j = ndigits % 2 == 0 ? nhalf : nhalf - 1;
			for(j; j >= 1; --j)
			{
				printf("%d", digits[j]);
			}
			printf("\n");
			++count;
		}

		digits[i]++;
		while(digits[i] > MAX_DIGIT)
		{
			/*
			** the low-order digit reach the maximum
			** the left digit carries a number
			*/
			digits[--i]++;
		}

		while(i >= 1 && i < nhalf)
		{
			/*
			** after carrying a number, the
			** right digits reset to zero
			*/
			digits[++i] = 0;
		}
	}

	free(digits);
	return count;
}