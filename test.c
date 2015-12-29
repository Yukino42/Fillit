#include <stdlib.h>
 #include <unistd.h>

int main()
{
	char **tableau;
	int y;
	int x;
	
	y = -1;
	x = 0;
	tableau = (char **)malloc(sizeof(char*) * 2);
	while(++y != 2)
		tableau[y] = (char *)malloc(sizeof(char) * 5);
	y = 0;
	tableau[y][x] = 's';
	x++;
	tableau[y][x] = 'a';
	x = 0;
	write(1, &tableau[y][x], 1);
	x++;
	write(1, &tableau[y][x], 1);
	return (0);
}