// �ع�: �ﰢ���� ���� �������� ������ �ݾ� ����Ѵ�
#include <stdio.h>
int main()
{
	int num = 0;
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		for (int j = num - 1; j >= 0; j--)			// ���� ���
		{
			if (j > i)
				printf(" ");
			else
				printf("*");
		}

		for (int j = 0; j < num - 1; j++)			// ���� ���
		{
			if (j < i)
				printf("*");
		}

		printf("\n");
	}

	return 0;
}