#include <stdio.h>
int recursive(int n)
{
	printf("%d\n", n);
	if (n < 1)
		return 2;
	else
		return (2 * recursive(n - 1) + 1);
}
void main()
{
	recursive(5);
}