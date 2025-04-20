#include <stdio.h>
int main(int argc, char **argv)
{
	int ch, next, csi = 0;
	while ((ch = getchar()) != EOF)
		ch == 0x1b && ((next = getchar()) == '[' ? csi = 1 : ungetc(next, stdin)),
		!csi && putchar(ch),
		ch >= 0x40 && ch <= 0x7e && (csi = 0);
	return ferror(stdin);
}
