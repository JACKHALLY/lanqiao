/*
考虑包含N位数字的K-进制数. 定义一个数有效, 如果其K-进制表示不包含两连续的0.

考虑包含N位数字的K-进制数. 定义一个数有效, 如果其K-进制表示不包含两连续的0. 

例: 
1010230 是有效的7位数 
1000198 无效 
0001235 不是7位数, 而是4位数. 

给定两个数N和K, 要求计算包含N位数字的有效K-进制数的总数. 

假设2 <= K <= 10; 2 <= N; 4 <= N+K <= 18.

输入:
两个十进制整数N和K
输出:
十进制表示的结果

样例输入:
2 10
样例输出:
90
*/
#include <stdio.h>
#include <math.h>

#define TRUE  (1)
#define FALSE (0)

int caculate_pos_power(int b, int p);
int caculate_pick(int n, int c);
int caculate_combination(int n, int c);
int caculate_nk_iteration(int n, int k);

int caculate_nk_recursion(int n, int k, int is_prezero, int depth);

int main(void)
{
	int n, k;
	int total;

	while(scanf("%d %d", &n, &k) == 2)
	{
		total = caculate_nk_iteration(n, k);
		printf("%d\n", total);
		/*
		total = caculate_nk_recursion(n, k, FALSE, 1);
		printf("%d\n", total);
		*/
	}
	return 0;
}

int caculate_nk_iteration(int n, int k)
{
	int max_zeros = n / 2;
	int total = 0;
	int tmp_total = 0;
	int zeros = 0;
	int zeros_choice = 0;
	int tmp_zeros;
	int tmp_zeros_choice;
	int notzeros = 0;
	int notzeros_choice = 0;
	int tmp_positions = 0;

	for(zeros = 0; zeros <= max_zeros; ++zeros)
	{
		/* the first digit has k - 1 choices */
		tmp_total = k - 1;

		/* from n - 1, pick the digits which are not zero */
		notzeros = n - 1 - zeros;

		notzeros_choice = 1;
		tmp_positions = notzeros + 1;
		for(tmp_zeros = 1; tmp_zeros <= zeros; ++tmp_zeros)
		{
			/* choose a position for the zero in the non-zero digits */
			tmp_zeros_choice = caculate_pick(tmp_positions, 1);
			--tmp_positions;

			notzeros_choice *= tmp_zeros_choice;
		}

		/* eliminate the duplicate choice */
		for(tmp_zeros = 2; tmp_zeros <= zeros; ++tmp_zeros)
		{
			notzeros_choice /= tmp_zeros;
		}


		/* other non-zero digits, combination */
		tmp_total *= notzeros_choice * caculate_pos_power(k - 1, notzeros);

		total += tmp_total;
	}

	return total;
}

int caculate_combination(int n, int c)
{
	int result = 1;
	int i;
	for(i = n; i >= n - c + 1; --i)
	{
		result *= i;
	}

	return result;
}

int caculate_pick(int n, int c)
{
	int numerator = caculate_combination(n, c);
	int denominator = caculate_combination(c, c);

	return numerator / denominator;
}

int caculate_pos_power(int b, int p)
{
	int i;
	int result = 1;
	for(i = 0; i < p; ++i)
	{
		result *= b;
	}

	return result;
}

int caculate_nk_recursion(int n, int k, int is_prezero, int depth)
{
	int total = 0;
	int start = 0;
	if(depth <= n)
	{
		for(start = depth == 1 ? 1 : 0; start < k; ++start)
		{
			if(start == 0 && is_prezero)
			{
				/* can not be continuous zeros */
				continue;
			}
			else if(start == 0)
			{
				total += caculate_nk_recursion(n, k, TRUE, depth + 1);
			}
			else
			{
				total += caculate_nk_recursion(n, k, FALSE, depth + 1);
			}
		}
	}
	else
	{
		total = 1;
	}

	return total;
}