#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BASE_NUM (32)

int main(void)
{
	int index = 0;
	int inChar;
	int sizeString = BASE_NUM * 2;
	char *outString = malloc(BASE_NUM * 2);
	char *newString;


	if(outString == NULL)
	{
		printf("fail to malloc the string!\n");
		return 1;
	}

	memset(outString, 0, BASE_NUM * 2);
	while(scanf("%d", &inChar) == 1)
	{
		if(index >= sizeString)
		{
			newString = malloc(2 * sizeString);
			if(newString == NULL)
			{
				printf("fail to malloc the new string!\n");
				free(outString);
				return 1;
			}
			memset(newString, 0, 2 * sizeString);
			memcpy(newString, outString, sizeString);
			sizeString *= 2;
			free(outString);
			outString = newString;
			newString = NULL;
		}
		outString[index++] = inChar;
	}
	printf("%s\n", outString);
	free(outString);
	return 0;
}