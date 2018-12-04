/*
2018. 11. 27 ��ǻ�����α׷���2 (���� �ذ� �ɷ�/���α׷��� �ɷ� ���)
2. �л� N���� ���� ������ �迭 class�� �־�����. ������ 0 ~ 10 ������ �������� ������. 
   �� ������ �󵵼��� ���Ͽ� r��°�� �󵵼��� ���� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
   �ۼ��� �� class�迭�� r�� �Ű������� �Է¹޾� �� ������ �󵵼��� ���Ͽ� r��°�� �󵵼��� ���� ������ 
   ��ȯ�ϴ� �Լ� rank_freq()�� �����Ͽ� ����Ѵ�.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 10

typedef struct info {
	int score;						// ����
	int freq;						// ������ �󵵼�
}info;

int rank_freq(info*[], int);
void change(int*, int*);

int main()
{
	int class[N] = { 0, };
	srand((int)(time(NULL)));
	for (int i = 0; i < N; i++)
		class[i] = rand() % 11;

	printf("����: ");
	for (int i = 0; i < N; i++)
		printf("%d ", class[i]);
	printf("\n");

	int r = 0;						// �󵵼�
	scanf("%d", &r);

	info* info_arr[N];				// ������ �󵵼� �迭	
	for (int i = 0; i < N; i++)
		info_arr[i] = malloc(sizeof(info));

	for (int i = 0; i < N; i++)
		info_arr[i]->score = class[i];

	// ��ȯ�� freq�� �ش��ϴ� ������ ��� ���
	int maxFreq = rank_freq(info_arr, r);				// ���� ���� �󵵼�
	printf("%d��°�� ���� �󵵼�: %d\n", r, maxFreq);
	for (int i = 0; i < N; i++)
	{
		if (info_arr[i]->freq == maxFreq)
		{
			int same = 0;
			if (i == 0)
				printf("%d��°�� ���� ����: %d��\n", r, info_arr[i]->score);
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
					printf("%d��°�� ���� ����: %d��\n", r, info_arr[i]->score);
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

	printf("���� �� ����:   ");
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]->score);
	printf("\n");
	printf("���� �� �󵵼�: ");
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

	printf("���� �� ����:   ");
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]->score);
	printf("\n");
	printf("���� �� �󵵼�: ");
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
