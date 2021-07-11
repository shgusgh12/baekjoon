#include <stdio.h>
#include <time.h>

//5마리 고양이 키우기 게임

//고양이 이름 나이 성격 난이도
typedef struct {
	char* name;//이름
	int age;//나이 
	char* character; //성격
	int level;
}cat;
//현재 보유 고양이
int collection[5] = { 0,0,0,0,0 };

//전체 고양이 리스트
cat cats[5];
void initCats(); //고양이 정보 초기화
void printCat();

int main(void) {
	srand(time(NULL));

	initCats();
	while (1) {
		printf("어느고양이의 집사가 될까요?\n 아무키나 눌러서 확인하세요");
		getchar();

		int selected = rand() % 5; // 0-4사이의 숫자
		printCat(selected); //뽑은 고양이 정보 출력
		collection[selected] = 1; //고양이 뽑기 처리

		int collectAll = checkcollection();
		if (collectAll == 1) {
			break;
		}
	}
	return 0;
}

void initCats() {
	cats[0].name = "깜냥이";
	cats[0].age = 5;
	cats[0].character = "온순";
	cats[0].level = 1;

	cats[1].name = "깜이";
	cats[1].age = 2;
	cats[1].character = "온순";
	cats[1].level = 1;

	cats[2].name = "돼냥이";
	cats[2].age = 3;
	cats[2].character = "온순";
	cats[2].level = 5;

	cats[3].name = "수줍이";
	cats[3].age = 7;
	cats[3].character = "온순";
	cats[3].level = 8;

	cats[4].name = "깜냥이";
	cats[4].age = 5;
	cats[4].character = "온순";
	cats[4].level = 1;

}

void printCat(int selected) {
	printf("\n\n 당신은 이 고양이의 집사가 되었습니다.\n");
	printf("이름 : %s\n", cats[selected].name);
	printf("나이 : %d\n", cats[selected].age);
	printf("성격 : %s\n", cats[selected].character);
	printf("레벨 : ");

	for (int i = 0; i < cats[selected].level; i++) {
		printf("%s", "★");
	}
	printf("\n\n");
}

int checkcollection() {
	//현재 보유한 고양이 목록 출력 다 모았는지 반환
	int collectAll = 1;

	printf("보유한 고양이 목록\n\n");
	for (int i = 0; i < 5; i++) {
		if (collection[i] == 0) {
			printf("%10s", "(빈 박스)");
			collectAll = 0;
		}
		else 
		{
			printf("%10s", cats[i].name);
		}
	}
	printf("=================================\n");

	if (collectAll)// 다 모은 경우
	{
		printf("\n 축하합니다 다 모았습니다.");
	}

	return collectAll;
}