#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//비밀번호 입력받아서
//맞을때 비밀 일기 읽어오기
//틀릴때 경고 메세지

#define MAX 10000

int main(void) {
	char line[MAX]; //파일에서 불러온 내용 저장할 변수
	char contents[MAX]; //일기장에 입력할 내용
	char password[20]; //비밀번호 입력
	char c; // 비밀번호 입력 할때 키값 확인용 마스킹

	printf("비밀 번호를 입력하세요 \n");
	//getchar() 와 getch() 의 차이
	//getchar 엔터 입력해야 동작
	//getch 키 입력시 바로 동작
	int i = 0;
	while (1) {
		c = getch();
		if (c == 13)// enter 아스키코드  비밀번호 입력 종료
		{
			password[i] = '\0';
			break;
		}
		else //비밀번호 입력 중
		{
			printf("*");
			password[i] = c;
		}
		i++;
	}
	printf("비밀번호 확인중\n");
	if (strcmp(password, "abcd") == 0) // 스트링 값 비교
	{
		printf("비밀번호 확인 완료\n\n");
		char* fileName = "secret.txt";
		FILE* file = fopen(fileName, "a+b"); //파일이 없으면 생성 있으면 append (이어쓰기) 한다
		if (file == NULL) {
			printf("파일 열기 실패");
			return 1;
		}
		while (fgets(line, MAX, file) != NULL) {
			printf("%s", line);
		}
		printf("내용을 계속 작성하세요 종료하려면 EXIT 입력하세요\n\n");

		while (1) {
			scanf("%[^\n]", contents); //새 줄 (줄바꿈) 이 나오기 전까지 읽어 들임
			getchar(); //enter 입력 flush 처리

			if (strcmp(contents, "EXIT") == 0) {
				printf("비밀일기 입력을 종료합니다\n\n");
				break;
			}
			fputs(contents, file);
			fputs("\n", file); //enter를 위에서 무시했으므로 임의로 추가
		}
		fclose(file);
	}
	else //비밀번호 틀린경우
	{
		printf("비밀번호가 틀렸습니다\n\n");
	}
	return 0;
}


