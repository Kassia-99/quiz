// C��� �ڵ� ���� 38.8 �ɻ繮��: ����ã��
#include <stdio.h>	  
#include <stdlib.h>
#include <string.h>
int main()
{
	int m = 0;											// ����� ���� ũ��
	int	n = 0;											// ����� ���� ũ��
	scanf("%d %d", &m, &n);

	// ��� ���� �� �޸� �Ҵ�
	char **matrix = malloc(sizeof(char *) * m);
	for (int i = 0; i < m; ++i)
	{
		matrix[i] = malloc(sizeof(char) * n + 1);
		memset(matrix[i], 0, sizeof(char) * n + 1);
	}


	// ����� ���� ������ ���ڿ� �Է�
	for (int i = 0; i < m; ++i)
		scanf("%s", matrix[i]);

	// ���� Ž�� �� ���
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (matrix[i][j] == '*')
				continue;
			else
			{
				matrix[i][j] = '0';
				for (int y = i - 1; y <= i + 1; ++y)
				{
					for (int x = j - 1; x <= j + 1; ++x)
					{
						if (y < 0 || x < 0 || y >= m || x >= n)
							continue;
						else if (matrix[y][x] == '*')
							matrix[i][j]++;
					}
				}
			}
		}
	}

	// ��� ��ü ���
	for (int i = 0; i < m; ++i)
		printf("%s\n", matrix[i]);

	// ����� �޸� ����
	for (int i = 0; i < m; ++i)
		free(matrix[i]);
	free(matrix);

	return 0;
}