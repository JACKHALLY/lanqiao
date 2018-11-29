#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WINE_FLAG ('*')

void checkMatrix(char *paraMatrix,
				 int paraM, int paraN,
				 int paraRow, int paraColumn);
void printMatrix(char *paraMatrix, int paraM,
				 int paraN);
int main(void)
{
	int m, n;
	int rowNo = 0;
	int columnNo = 0;
	char *curMatrix = NULL;
	char *curLine = NULL;
	int bufChar;
	while((scanf("%d %d", &m, &n) == 2)&& 
		(m > 0) && (n > 0))
	{
		while((bufChar = getchar()) != '\n' && bufChar != EOF);

		if(curMatrix != NULL)
		{
			free(curMatrix);
		}
		if(curLine != NULL)
		{
			free(curLine);
		}

		curMatrix = malloc(m * n * sizeof(char));
		curLine = malloc((n + 1) * sizeof(char));
		if(curMatrix == NULL || curLine == NULL)
		{
			fprintf(stderr, "fail to allocate the memory!\n");
			break;
		}

		memset(curMatrix, 0, m * n * sizeof(char));
		memset(curLine, 0, (n + 1) * sizeof(char));
		rowNo = 0;
		while(rowNo < m)
		{
			fgets(curLine, n, stdin);
			while((bufChar = getchar()) != '\n' && bufChar != EOF);
			if(curLine[strlen(curLine) - 1] == '\n')
				curLine[strlen(curLine) - 1] = '\0';

			for(columnNo = 0; curLine[columnNo] != '\0'; ++columnNo)
			{
				if(curLine[columnNo] == WINE_FLAG)
				{
					*(curMatrix + rowNo * n + columnNo) = WINE_FLAG;
					checkMatrix(curMatrix, m, n,
								rowNo, columnNo);
				}
			}
			++rowNo;
		}

		printMatrix(curMatrix, m, n);
	}

	if(curMatrix != NULL)
	{
		free(curMatrix);
	}
	if(curLine != NULL)
	{
		free(curLine);
	}
	return 0;
}

void checkMatrix(char *paraMatrix,
				 int paraM, int paraN,
				 int paraRow, int paraColumn)
{
	int startColumn, endColumn;
	int startRow, endRow;


	startColumn = paraColumn - 1;
	endColumn = paraColumn + 1;
	while(startColumn <= endColumn)
	{
		if(startColumn < 0 || startColumn >= paraN)
		{
			++startColumn;
			continue;
		}

		startRow = paraRow - 1;
		endRow = paraRow + 1;
		while(startRow <= endRow)
		{
			if(startRow < 0 || startRow >= paraM)
			{
				++startRow;
				continue;
			}

			if(*(paraMatrix + startRow * paraN + startColumn) != WINE_FLAG)
				(*(paraMatrix + startRow * paraN + startColumn))++;

			++startRow;
		}

		++startColumn;
	}

}
void printMatrix(char *paraMatrix, int paraM,
				 int paraN)
{
	static int staticCount = 1;
	int i, j;

	printf("Field #%d:\n", staticCount);
	for(i = 0; i < paraM; ++i)
	{
		for(j = 0; j < paraN; ++j)
		{
			if(*(paraMatrix + i * paraN + j) == WINE_FLAG)
			{
				printf("%c", *(paraMatrix + i * paraN + j));
			}
			else
			{
				printf("%d", *(paraMatrix + i * paraN + j));
			}
		}
		printf("\n");
	}
	printf("\n");
	++staticCount;
}