#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define TRUE   (1)
#define FALSE  (0)
#define LEN    (30)
#define SEGLEN (4)
#define SEGNUM (4)
int split_line(char *line, char (*segs)[SEGLEN]);
int check_range(char (*segs)[SEGLEN]);
int main(void)
{
	char line[30 + 1];
	char segments[SEGNUM][SEGLEN];
	while(fgets(line, LEN, stdin))
	{
		if(line[strlen(line) - 1] == '\n')
		{
			line[strlen(line) - 1] = '\0';
		}

		if(!split_line(line, segments))
		{
			/* fail to split the ip string */
			printf("N\n");
		}
		else if(!check_range(segments))
		{
			/* fail to fall into [0, 255] */
			printf("N\n");
		}
		else
		{
			printf("Y\n");
		}
	}
	return 0;
}

int split_line(char *line, char (*segs)[SEGLEN])
{
	char *cur = line;
	int segnum = 0;
	int seglen = 0;
	while(*cur != '\0')
	{
		if(isdigit(*cur))
		{
			if(segnum < SEGNUM && seglen < SEGLEN)
			{
				(*(segs + segnum))[seglen] = *cur;
				++seglen;
			}
			else if(seglen >= SEGLEN)
			{
				return FALSE;
			}
			else
			{
				/* segnum >= SEGNUM */
				return FALSE;
			}
		}
		else if(*cur == '.')
		{
			(*(segs + segnum))[seglen] = '\0';
			++segnum;
			seglen = 0;
		}
		else
		{
			/* other characters */
			return FALSE;
		}

		++cur;
	}
	(*(segs + segnum))[seglen] = '\0';
	return TRUE;
}

int check_range(char (*segs)[SEGLEN])
{
	int i, value;
	for(i = 0; i < SEGNUM; ++i)
	{
		value = atoi(*(segs + i));
		if(value > 255 || value < 0)
		{
			return FALSE;
		}
	}
	return TRUE;
}