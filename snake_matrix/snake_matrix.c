#include <stdio.h>

int main(void)
{
	int n, i, j;
	int startItem, startRowDelta, startColumnDelta;
	int item, columnDelta;

	while(scanf("%d", &n) == 1 && n > 0)
	{
		startItem = 1;
		startRowDelta = 1;
		startColumnDelta = 2;
		for(i = n; i > 0; --i)
		{
			item = startItem;
			columnDelta = startColumnDelta;
			for(j = 0; j < i; ++j)
			{
				printf("%d ", item);
				item += columnDelta;
				++columnDelta;
			}
			printf("\n");

			startItem += startRowDelta;
			++startRowDelta;
			++startColumnDelta;
		}
	}

	return 0;
}