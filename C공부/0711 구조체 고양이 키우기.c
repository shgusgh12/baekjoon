#include <stdio.h>
#include <time.h>

//5���� ����� Ű��� ����

//����� �̸� ���� ���� ���̵�
typedef struct {
	char* name;//�̸�
	int age;//���� 
	char* character; //����
	int level;
}cat;
//���� ���� �����
int collection[5] = { 0,0,0,0,0 };

//��ü ����� ����Ʈ
cat cats[5];
void initCats(); //����� ���� �ʱ�ȭ
void printCat();

int main(void) {
	srand(time(NULL));

	initCats();
	while (1) {
		printf("���������� ���簡 �ɱ��?\n �ƹ�Ű�� ������ Ȯ���ϼ���");
		getchar();

		int selected = rand() % 5; // 0-4������ ����
		printCat(selected); //���� ����� ���� ���
		collection[selected] = 1; //����� �̱� ó��

		int collectAll = checkcollection();
		if (collectAll == 1) {
			break;
		}
	}
	return 0;
}

void initCats() {
	cats[0].name = "������";
	cats[0].age = 5;
	cats[0].character = "�¼�";
	cats[0].level = 1;

	cats[1].name = "����";
	cats[1].age = 2;
	cats[1].character = "�¼�";
	cats[1].level = 1;

	cats[2].name = "�ų���";
	cats[2].age = 3;
	cats[2].character = "�¼�";
	cats[2].level = 5;

	cats[3].name = "������";
	cats[3].age = 7;
	cats[3].character = "�¼�";
	cats[3].level = 8;

	cats[4].name = "������";
	cats[4].age = 5;
	cats[4].character = "�¼�";
	cats[4].level = 1;

}

void printCat(int selected) {
	printf("\n\n ����� �� ������� ���簡 �Ǿ����ϴ�.\n");
	printf("�̸� : %s\n", cats[selected].name);
	printf("���� : %d\n", cats[selected].age);
	printf("���� : %s\n", cats[selected].character);
	printf("���� : ");

	for (int i = 0; i < cats[selected].level; i++) {
		printf("%s", "��");
	}
	printf("\n\n");
}

int checkcollection() {
	//���� ������ ����� ��� ��� �� ��Ҵ��� ��ȯ
	int collectAll = 1;

	printf("������ ����� ���\n\n");
	for (int i = 0; i < 5; i++) {
		if (collection[i] == 0) {
			printf("%10s", "(�� �ڽ�)");
			collectAll = 0;
		}
		else 
		{
			printf("%10s", cats[i].name);
		}
	}
	printf("=================================\n");

	if (collectAll)// �� ���� ���
	{
		printf("\n �����մϴ� �� ��ҽ��ϴ�.");
	}

	return collectAll;
}