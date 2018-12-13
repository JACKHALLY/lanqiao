#include <stdio.h>

int main(void)
{
	unsigned num;
	int tom = 0;

	while(scanf("%u", &num) == 1)
	{
		tom = 0;
		while(num > 0)
		{
			tom += num % 10;
			num /= 10;
		}
		printf("%d\n", tom);
	}
	return 0;
}