#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//��й�ȣ �Է¹޾Ƽ�
//������ ��� �ϱ� �о����
//Ʋ���� ��� �޼���

#define MAX 10000

int main(void) {
	char line[MAX]; //���Ͽ��� �ҷ��� ���� ������ ����
	char contents[MAX]; //�ϱ��忡 �Է��� ����
	char password[20]; //��й�ȣ �Է�
	char c; // ��й�ȣ �Է� �Ҷ� Ű�� Ȯ�ο� ����ŷ

	printf("��� ��ȣ�� �Է��ϼ��� \n");
	//getchar() �� getch() �� ����
	//getchar ���� �Է��ؾ� ����
	//getch Ű �Է½� �ٷ� ����
	int i = 0;
	while (1) {
		c = getch();
		if (c == 13)// enter �ƽ�Ű�ڵ�  ��й�ȣ �Է� ����
		{
			password[i] = '\0';
			break;
		}
		else //��й�ȣ �Է� ��
		{
			printf("*");
			password[i] = c;
		}
		i++;
	}
	printf("��й�ȣ Ȯ����\n");
	if (strcmp(password, "abcd") == 0) // ��Ʈ�� �� ��
	{
		printf("��й�ȣ Ȯ�� �Ϸ�\n\n");
		char* fileName = "secret.txt";
		FILE* file = fopen(fileName, "a+b"); //������ ������ ���� ������ append (�̾��) �Ѵ�
		if (file == NULL) {
			printf("���� ���� ����");
			return 1;
		}
		while (fgets(line, MAX, file) != NULL) {
			printf("%s", line);
		}
		printf("������ ��� �ۼ��ϼ��� �����Ϸ��� EXIT �Է��ϼ���\n\n");

		while (1) {
			scanf("%[^\n]", contents); //�� �� (�ٹٲ�) �� ������ ������ �о� ����
			getchar(); //enter �Է� flush ó��

			if (strcmp(contents, "EXIT") == 0) {
				printf("����ϱ� �Է��� �����մϴ�\n\n");
				break;
			}
			fputs(contents, file);
			fputs("\n", file); //enter�� ������ ���������Ƿ� ���Ƿ� �߰�
		}
		fclose(file);
	}
	else //��й�ȣ Ʋ�����
	{
		printf("��й�ȣ�� Ʋ�Ƚ��ϴ�\n\n");
	}
	return 0;
}


