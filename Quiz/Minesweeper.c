// C언어 코딩 도장 38.8 심사문제: 지뢰찾기
#include <stdio.h>	  
#include <stdlib.h>
#include <string.h>
int main()
{
	int m = 0;											// 행렬의 세로 크기
	int	n = 0;											// 행렬의 가로 크기
	scanf("%d %d", &m, &n);

	// 행렬 선언 및 메모리 할당
	char **matrix = malloc(sizeof(char *) * m);
	for (int i = 0; i < m; ++i)
	{
		matrix[i] = malloc(sizeof(char) * n + 1);
		memset(matrix[i], 0, sizeof(char) * n + 1);
	}


	// 행렬의 가로 공간에 문자열 입력
	for (int i = 0; i < m; ++i)
		scanf("%s", matrix[i]);

	// 지뢰 탐색 및 계산
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

	// 행렬 전체 출력
	for (int i = 0; i < m; ++i)
		printf("%s\n", matrix[i]);

	// 행렬의 메모리 해제
	for (int i = 0; i < m; ++i)
		free(matrix[i]);
	free(matrix);

	return 0;
}