#include <stdio.h>


int main(int argc, char **argv)
{
	int ch, next, csi;

	csi = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch == 27 /* ^[ */)
			if ((next = getchar()) == '[')
				csi = 1;
			else if (next != EOF)
				ungetc(next, stdin);
		if (!csi)
			putchar(ch);
		if (ch >= 0x40 && ch <= 0x7e)
			csi = 0;
	}
	return ferror(stdin);
}
