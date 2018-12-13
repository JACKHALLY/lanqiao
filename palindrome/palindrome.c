/*
�۲����֣�12321��123321  ����һ����ͬ�����������۴����Ҷ����Ǵ����������������ͬ�ġ����������ֽ������������֡� 

����Ҫ�����ҵ�һЩ5λ��6λ��ʮ�������֡���������Ҫ�� 
�����ֵĸ�����λ֮�͵��������������

����:
һ��������  n  (10< n< 100),  ��ʾҪ���������λ�͡�

���:
�����У�ÿ�а���һ������Ҫ���5λ��6λ������ 
���ְ���С�����˳�����С� 
���û�����������ģ������-1

��������:
44

�������:
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