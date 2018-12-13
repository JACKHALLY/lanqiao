#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MIN(x, y) ((x) > (y) ? (y) : (x))

typedef struct _BaseInfo
{
	int bi_msd; /* maximum value of most significant digit */
	int bi_osd; /* maximum value of other significant digit */ 
	int bi_ndigits; /* number of digits */
} BaseInfo, *PBaseInfo;

void calculateBaseInfo(int v_order,
					   int v_width,
					   PBaseInfo v_bi);
void printBaseInfo(PBaseInfo v_bi);

int main(void)
{
	int order = 0, width = 0;
	int sum_number = 0;
	int cur_digits, cur_max_msd;
	int i, j;
	short *digits;
	BaseInfo bi;

	scanf("%d %d", &order, &width);
	if(order <= 0 || width <= 0)
	{
		fprintf(stderr, "the arguments are illegal!\n");
		return 1;
	}
	calculateBaseInfo(order, width, &bi);

	digits = malloc(bi.bi_ndigits * sizeof(short));
	if(digits == NULL)
	{
		fprintf(stderr, "fail to malloc the memory!\n");
		return 1;
	}

	memset(digits, 0, bi.bi_ndigits * sizeof(short));
	cur_digits = 2;
	sum_number = 0;
	while(cur_digits <= bi.bi_ndigits)
	{
		/*
		** initialize the current maximum value of
		** the most significant digit
		*/
		if(cur_digits == bi.bi_ndigits)
		{
			cur_max_msd = bi.bi_msd;
		}
		else
		{
			cur_max_msd = bi.bi_osd - cur_digits + 1;
		}

		/* initialize the current minimum number e.g 123 */
		for(j = 1, i = cur_digits - 1; i >= 0; --i, ++j)
		{
			digits[i] = j;
		}

		/*
		** accumulate the different numbers belong to
		** the current digits
		*/
		while(digits[cur_digits - 1] <= cur_max_msd)
		{
			/*
			** the digits[1] stand for the left
			** digit of the5 least significant digit(digits[0])
			*/
			sum_number += bi.bi_osd - digits[1];

			/*
			** update the digits
			** determine the influenced digit
			*/
			for(i = 1; i < cur_digits; ++i)
			{
				digits[i]++;
				if(digits[i] <= bi.bi_osd - i)
				{
					/* get a new different digit at i */
					break;
				}
			}

			/*
			** from the influnced digit to
			** the lease significant digit
			*/
			for(j = i - 2; j >= 0; --j)
			{
				digits[j] = digits[j + 1] + 1;
			}
		}

		++cur_digits;
	}

	printf("%d\n", sum_number);

	free(digits);
	return 0;
}

void calculateBaseInfo(int v_order,
					   int v_width,
					   PBaseInfo v_bi)
{
	int l_ndigits_width = 1;
	int l_nbits_remain = v_width % v_order;
	int l_ndigits_order = (int)pow(2, v_order) - 1;

	while(v_width > 0)
	{
		++l_ndigits_width;
		v_width /= v_order;
	}

	v_bi->bi_ndigits = MIN(l_ndigits_width, l_ndigits_order);
	if(v_bi->bi_ndigits == l_ndigits_width)
	{
		v_bi->bi_msd = (int)pow(2, l_nbits_remain);
		if(l_nbits_remain == v_order)
		{
			v_bi->bi_msd -= v_bi->bi_ndigits;
		}
		else
		{
			v_bi->bi_msd--;
		}
	}
	else
	{
		v_bi->bi_msd = 1;
	}
	v_bi->bi_osd = (int)pow(2, v_order) - 1;
}

void printBaseInfo(PBaseInfo v_bi)
{
	printf("base info: \n");
	printf("maximum value of the most significant digit: ");
	printf("%d\n", v_bi->bi_msd);
	printf("maximum value of other significant digit: ");
	printf("%d\n", v_bi->bi_osd);
	printf("number of the digits: ");
	printf("%d\n", v_bi->bi_ndigits);
}