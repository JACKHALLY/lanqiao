#include <stdio.h>
#include <string.h>

#define MAX_LENGTH (1000)

void splitString(char *paraStr);

int main(void)
{
	int n = 0;
	int lineNo = 0;
	int charBuf;
	char strLine[MAX_LENGTH] = { 0 };


	scanf("%d", &n);
	
	/* clear the input buffer */
	while((charBuf = getchar()) != '\n' && charBuf != EOF);

	if(n > 0)
	{
		while(fgets(strLine, MAX_LENGTH, stdin) != NULL)
		{
			if(strLine[strlen(strLine) - 1] == '\n')
				strLine[strlen(strLine) - 1] = '\0';
			if(lineNo++ < n)
			{
				printf("%s\n\n", strLine);
			}
			else
			{
				splitString(strLine);
			}
		}
	}

	return 0;
}

void splitString(char *paraStr)
{
	char *startPos = paraStr;
	int index = 0;

	/*
	** skip the leading whitespace and the return
	*/
	while(paraStr[index] != '\0' &&
		(paraStr[index] == ' ' || paraStr[index] == '\r'))
	{
		++index;
	}
	startPos = &paraStr[index];

	while(paraStr[index] != '\0')
	{
		if(paraStr[index] == ' ' ||
			paraStr[index] == '\r')
		{
			paraStr[index] = '\0';
			printf("%s\n\n", startPos);

			++index;
			while(paraStr[index] != '\0' &&
				(paraStr[index] == ' ' || paraStr[index] == '\r'))
			{
				++index;
			}
			startPos = &paraStr[index];
		}
		else
		{
			++index;
		}
	}

	/*
	** the remain substring
	*/
	if(startPos != &paraStr[index])
		printf("%s\n\n", startPos);
}