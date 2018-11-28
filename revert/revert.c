#include <stdio.h>
#include <string.h>

#define MAX_LENGTH (100)
int main(void)
{
	int length = 0;
	int i;
	char str[MAX_LENGTH + 1] = { 0 };
	char tmpChar;

	fgets(str, MAX_LENGTH, stdin);
	length = strlen(str);
	if(str[length - 1] == '\n')
	{
		str[length - 1] = '\0';
		--length;
	}


	for(i = 0; i < length / 2; ++i)
	{
		tmpChar = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = tmpChar;
	}

	printf("%s\n", str);
	return 0;
}