#include <stdio.h>
int main()
{
	int Temp1 = 0, Temp2 = 1, Sum = 0, n = 0;

	printf("input: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", Sum);
		Sum = Temp1 + Temp2;
		Temp1 = Temp2;
		Temp2 = Sum;
	}

	return 0;
}