/*
2018. 11. 27 컴퓨터프로그래밍2 (문제 해결 능력/프로그래밍 능력 배양)
2. 학생 N명의 퀴즈 점수가 배열 class로 주어진다. 점수는 0 ~ 10 사이의 정수값을 가진다. 
   각 점수의 빈도수를 구하여 r번째로 빈도수가 많은 점수를 출력하는 프로그램을 작성하시오.
   작성할 때 class배열과 r을 매개변수로 입력받아 각 점수의 빈도수를 구하여 r번째로 빈도수가 많은 점수를 
   반환하는 함수 rank_freq()을 정의하여 사용한다.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 10

typedef struct info {
	int score;						// 점수
	int freq;						// 점수의 빈도수
}info;

int rank_freq(info*[], int);
void change(int*, int*);

int main()
{
	int class[N] = { 0, };
	srand((int)(time(NULL)));
	for (int i = 0; i < N; i++)
		class[i] = rand() % 11;

	printf("점수: ");
	for (int i = 0; i < N; i++)
		printf("%d ", class[i]);
	printf("\n");

	int r = 0;						// 빈도수
	scanf("%d", &r);

	info* info_arr[N];				// 점수와 빈도수 배열	
	for (int i = 0; i < N; i++)
		info_arr[i] = malloc(sizeof(info));

	for (int i = 0; i < N; i++)
		info_arr[i]->score = class[i];

	// 반환된 freq에 해당하는 점수를 모두 출력
	int maxFreq = rank_freq(info_arr, r);				// 가장 많은 빈도수
	printf("%d번째로 많은 빈도수: %d\n", r, maxFreq);
	for (int i = 0; i < N; i++)
	{
		if (info_arr[i]->freq == maxFreq)
		{
			int same = 0;
			if (i == 0)
				printf("%d번째로 많은 점수: %d점\n", r, info_arr[i]->score);
			else
			{
				for (int j = 0; j < i; j++)
				{
					if (info_arr[j]->score == info_arr[i]->score)
					{
						same = 1;
						break;
					}
				}
				if (!same)
					printf("%d번째로 많은 점수: %d점\n", r, info_arr[i]->score);
			}
		}
	}

	for (int i = 0; i < N; i++)
		free(info_arr[i]);

	return 0;
}

int rank_freq(info* arr[], int r)
{
	for (int i = 0; i < N; i++)
	{
		int count = 0;
		for (int j = 0; j < N; j++)
		{
			if (arr[i]->score == arr[j]->score)
				count++;
		}
		arr[i]->freq = count;
	}

	printf("정렬 전 점수:   ");
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]->score);
	printf("\n");
	printf("정렬 전 빈도수: ");
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]->freq);
	printf("\n");

	for (int i = 0; i < N; i++)
	{
		int max = i;
		for (int j = i; j < N; j++)
		{
			if (arr[j]->freq > arr[max]->freq)
				max = j;
		}
		change(&(arr[max]->freq), &(arr[i]->freq));
		change(&(arr[max]->score), &(arr[i]->score));
	}

	printf("정렬 후 점수:   ");
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]->score);
	printf("\n");
	printf("정렬 후 빈도수: ");
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]->freq);
	printf("\n");


	return arr[r]->freq;
}

void change(int* num1, int* num2)
{
	int temp = 0;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
