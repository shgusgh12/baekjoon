#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

int level;
int arrayFish[6];
int * cursor; // ��� ���׿� ���� ����
void initData();
void printFishes();
void decreaseWater();

int main(void) 
{
	long startTime = 0;// �ð� �̿��� �� long �ڷ��� ���
	long totalElaspsedTime = 0; //�� ����ð�
	long prevElapsedTime = 0; // ���� ����ð�

	int num; // ��� ���׿� ���� �� ���ΰ�
	initData();

	cursor = arrayFish;

	startTime = clock(); //���� �ð��� milisecond ������ ��ȯ
	while (1) 
	{
		printFishes();
		printf("�� �� ���׿� ���� �ֽǰǰ���?? ");
		scanf("%d", &num);
		//getchar(); // ����� �Է´��
		//�Է°�üũ
		if (num < 1 || num >6) {
			printf("\n�Է°��� �߸��Ǿ����ϴ�\n");
			continue;
		}
		//�Ѱ���ð�
		totalElaspsedTime = (clock() - startTime) / CLOCKS_PER_SEC;//�� ������ ���� 
		printf("�� ��� �ð� : %ld ��\n", totalElaspsedTime);

		//���� �� �� �ð� (���������� �� �� �ð�) ���ķ� �帥 �ð�
		prevElapsedTime = totalElaspsedTime - prevElapsedTime;
		printf("�ֱ� ��� �ð� : %ld��\n", prevElapsedTime);
		
		//������ ���� ���� (����)
		decreaseWater(prevElapsedTime);

		//����ڰ� �Է��� ���׿� ���� �ش�
		//1. ������ ���� 0�̸�? ���� ���� �ʴ´�.
		if (cursor[num - 1] < 0) {
			printf("%d �� ������ �̹� �׾����ϴ�. \n", num);
		}
		//2. ������ ���� 0�� �ƴ� ��� > ���� �ش� 100���� �۾ƾߵ�
		else if (cursor[num - 1] + 1 <= 100) {
			//���� �ش�
			printf("%d �� ���׿� ���� �ش�\n\n", num);
			cursor[num - 1] += 1; //cursor[num-1] = cursor[num-1] + 1
		}

		//������ �� ���� Ȯ��(�������� 20�ʸ��� �ѹ� ����)
		if (totalElaspsedTime / 20 > level - 1) {
			level++; 
			printf(" +++ ���� %d���� %d������ ������ ! \n", level - 1, level);

			//���� ���� 5
			if (level == 5) {
				printf("\n\n ���� ���� �޼�!");
				exit(0);
			}
		}

		//��� ����Ⱑ �׾����� Ȯ��
		if (checkFishAlive() == 0) {
			//����� �� ����
			printf("��� ����Ⱑ �׾����ϴ�\n");
		}
		else {
			//�Ѹ��� �̻� ����
			printf("����Ⱑ ���� ��� �־��\n");
		}
		prevElapsedTime = totalElaspsedTime;

		//���� 10�� > 15�� (5�� : prev> 15�ʷ� ����) > 25�� (10�� ... ?)


	}

	return 0;
}

void initData() {
	level = 1; //  ���� ����
	for (int i = 0; i < 6; i++) {
		arrayFish[i] = 100; // ������ ������ 
	}
}

void printFishes() {
	printf("%3d�� %3d�� %3d�� %3d�� %3d�� %3d��\n", 1, 2, 3, 4, 5, 6);
	for (int i = 0; i < 6; i++) {
		printf(" %4d ", arrayFish[i]);
	}
	printf("\n\n");
}

void decreaseWater(long elapsedTime) {
	for (int i = 0; i < 6; i++) {
		arrayFish[i] -= (level * 3 * (int)elapsedTime); // 3 ���̵� ������ ���� ��
		if (arrayFish[i] < 0) {
			arrayFish[i] = 0;
		}
	}

}
int checkFishAlive()
{
	for (int i = 0; i < 6; i++) {
		if (arrayFish[i] > 0)
			return 1; // �� True
	}
	return 0;
}


