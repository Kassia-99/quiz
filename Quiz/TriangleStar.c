// 해법: 삼각형을 가로 방향으로 나눠서 반씩 출력한다
#include <stdio.h>
int main()
{
	int num = 0;
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		for (int j = num - 1; j >= 0; j--)			// 앞쪽 출력
		{
			if (j > i)
				printf(" ");
			else
				printf("*");
		}

		for (int j = 0; j < num - 1; j++)			// 뒤쪽 출력
		{
			if (j < i)
				printf("*");
		}

		printf("\n");
	}

	return 0;
}