#include <stdio.h>

#define MAXLINE 1000


int	getline_(char line[], int maxline);
void copy(char to[], char from[]);

int main(int argc, char const *argv[])
{
	int len, max;
	char line[MAXLINE], longest[MAXLINE];

	max = 0;
	while ((len = getline_(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	
	if (max > 0)
		printf("%s", longest);
	return 0;
}

int getline_(char s[], int lim)
{
	int c;
	int i = 0;

	--lim;
	while (i < lim && (c = getchar()) != EOF && c != '\n') {
		s[i] = c;
		if (!(c == '\t' || c == '\r'))
			++i;
	}

	if (c == '\n') {
		s[i] = c;
		++i;
	}

	s[i] = '\0';

	return i;
}

void copy(char to[], char from[])
{
	 int i;
	 i = 0;
	 while ((to[i] = from[i]) != '\0')
		 ++i;
}
