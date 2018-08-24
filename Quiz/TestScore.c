// 2��
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define STD_NUM 0				// �迭���� �й��� ����Ŵ
#define TEST1 1					// �迭���� ù ��° ������ ����Ŵ
#define TEST2 2					// �迭���� �� ��° ������ ����Ŵ
#define TEST_SUM 3				// �迭���� ������ ����Ŵ
int main()
{
	// (1) �迭 ����
	int sInfo[10][4] = { 0, };

	srand((int)time(NULL));
	for (int i = 0; i < 10; ++i)
	{
		sInfo[i][STD_NUM] = i;										// (2) �й��� ������ ����
		sInfo[i][TEST1] = rand() % 101;
		sInfo[i][TEST2] = rand() % 101;
		sInfo[i][TEST_SUM] = sInfo[i][TEST1] + sInfo[i][TEST2];		// (3) ������ ����Ͽ� ����
	}

	// �迭 ��ü ��� �ڵ�
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			printf("%d	", sInfo[i][j]);
		}
		printf("\n");
	}

	// (4) �ִ� ������ �л��� ������ ���
	int max = 0;													// �ִ� ������ �л��� ������ ����Ű�� �迭�� �ε��� ��ȣ
	for (int i = 0; i < 10; ++i)
	{
		if (sInfo[i][TEST_SUM] > sInfo[max][TEST_SUM])
			max = i;
	}
	printf("���� 1�� �й�: %d, ���� 1: %d, ���� 2: %d, ����: %d\n", 
		sInfo[max][STD_NUM], 
		sInfo[max][TEST1], 
		sInfo[max][TEST2], 
		sInfo[max][TEST_SUM]);

	// (5) ������ �������� ������������ �����Ͽ� ���
	for (int num = 0; num < 10; ++num)
	{		
		// �ִ� ������ ���� �л��� ã��
		max = num;
		for (int i = num; i < 10; ++i)
		{
			if (sInfo[i][TEST_SUM] > sInfo[max][TEST_SUM])
				max = i;
		}							 

		// �ִ� ������ ���� �л��� �� �� �л��� ��ȯ��
		for (int j = 0; j < 4; ++j)
		{
			int temp = 0;
			temp = sInfo[max][j];
			sInfo[max][j] = sInfo[num][j];
			sInfo[num][j] = temp;
		}
	}

	printf("\n��ü ����(���� ����, ��������)\n");
	// �迭 ��ü ��� �ڵ�
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			printf("%d	", sInfo[i][j]);
		}
		printf("\n");
	}

	return 0;
}