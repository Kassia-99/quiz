// 2번
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define STD_NUM 0				// 배열에서 학번을 가리킴
#define TEST1 1					// 배열에서 첫 번째 성적을 가리킴
#define TEST2 2					// 배열에서 두 번째 성적을 가리킴
#define TEST_SUM 3				// 배열에서 총점을 가리킴
int main()
{
	// (1) 배열 정의
	int sInfo[10][4] = { 0, };

	srand((int)time(NULL));
	for (int i = 0; i < 10; ++i)
	{
		sInfo[i][STD_NUM] = i;										// (2) 학번과 정보를 저장
		sInfo[i][TEST1] = rand() % 101;
		sInfo[i][TEST2] = rand() % 101;
		sInfo[i][TEST_SUM] = sInfo[i][TEST1] + sInfo[i][TEST2];		// (3) 총점을 계산하여 저장
	}

	// 배열 전체 출력 코드
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			printf("%d	", sInfo[i][j]);
		}
		printf("\n");
	}

	// (4) 최대 총점인 학생의 정보를 출력
	int max = 0;													// 최대 총점인 학생의 정보를 가리키는 배열의 인덱스 번호
	for (int i = 0; i < 10; ++i)
	{
		if (sInfo[i][TEST_SUM] > sInfo[max][TEST_SUM])
			max = i;
	}
	printf("종합 1등 학번: %d, 점수 1: %d, 점수 2: %d, 총점: %d\n", 
		sInfo[max][STD_NUM], 
		sInfo[max][TEST1], 
		sInfo[max][TEST2], 
		sInfo[max][TEST_SUM]);

	// (5) 총점을 기준으로 내림차순으로 정렬하여 출력
	for (int num = 0; num < 10; ++num)
	{		
		// 최대 총점을 가진 학생을 찾음
		max = num;
		for (int i = num; i < 10; ++i)
		{
			if (sInfo[i][TEST_SUM] > sInfo[max][TEST_SUM])
				max = i;
		}							 

		// 최대 총점을 가진 학생과 맨 앞 학생을 교환함
		for (int j = 0; j < 4; ++j)
		{
			int temp = 0;
			temp = sInfo[max][j];
			sInfo[max][j] = sInfo[num][j];
			sInfo[num][j] = temp;
		}
	}

	printf("\n전체 정렬(총점 기준, 내림차순)\n");
	// 배열 전체 출력 코드
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