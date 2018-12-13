#include <stdio.h>

#define MIN(x, y) ((x) > (y) ? (y) : (x))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

int main(void)
{
	int times, rows, repeats;
	int times_count, repeat_count, row_count, col_count;
	int pivot1, pivot2, pivot_row, tmp_pivot;
	int pivot_count;
	scanf("%d", &times);
	for(times_count = 0; times_count < times; ++times_count)
	{
		scanf("%d %d", &rows, &repeats);
		pivot1 = 1;
		pivot2 = rows;
		pivot_row = 1;
		pivot_count = 0;
		for(repeat_count = 0; repeat_count < repeats; ++repeat_count)
		{
			for(row_count = pivot_row; row_count <= rows; ++row_count)
			{
				for(col_count = 1; col_count <= rows; ++col_count)
				{
					if(col_count == pivot1 || col_count == pivot2)
					{
						printf("X");
						++pivot_count;
					}
					else
					{
						printf(" ");
					}

					if(pivot1 != pivot2 && pivot_count == 2)
					{
						break;
					}
					else if(pivot1 == pivot2 && pivot_count == 1)
					{
						break;
					}

				}

				printf("\n");
				++pivot1;
				--pivot2;
				pivot_count = 0;

			}
			--pivot1;
			++pivot2;
			tmp_pivot = MIN(pivot1, pivot2);
			pivot2 = MAX(pivot1, pivot2);
			pivot1 = tmp_pivot;
			++pivot1;
			--pivot2;
			pivot_row = 2; /* only the first time, from row 1 */
		}

		if(times_count != times - 1)
			printf("\n");
	}

	return 0;
}