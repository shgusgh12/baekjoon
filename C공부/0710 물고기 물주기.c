#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

int level;
int arrayFish[6];
int * cursor; // 어디 어항에 물을 줄지
void initData();
void printFishes();
void decreaseWater();

int main(void) 
{
	long startTime = 0;// 시간 이용할 때 long 자료형 사용
	long totalElaspsedTime = 0; //총 경과시간
	long prevElapsedTime = 0; // 직전 경과시간

	int num; // 몇번 어항에 물을 줄 것인가
	initData();

	cursor = arrayFish;

	startTime = clock(); //현재 시간을 milisecond 단위로 반환
	while (1) 
	{
		printFishes();
		printf("몇 번 어항에 물을 주실건가요?? ");
		scanf("%d", &num);
		//getchar(); // 사용자 입력대기
		//입력값체크
		if (num < 1 || num >6) {
			printf("\n입력값이 잘못되었습니다\n");
			continue;
		}
		//총경과시간
		totalElaspsedTime = (clock() - startTime) / CLOCKS_PER_SEC;//초 단위로 변경 
		printf("총 경과 시간 : %ld 초\n", totalElaspsedTime);

		//직전 물 준 시간 (마지막으로 물 준 시간) 이후로 흐른 시간
		prevElapsedTime = totalElaspsedTime - prevElapsedTime;
		printf("최근 경과 시간 : %ld초\n", prevElapsedTime);
		
		//어항의 물을 감소 (증발)
		decreaseWater(prevElapsedTime);

		//사용자가 입력한 어항에 물을 준다
		//1. 어항의 물이 0이면? 물을 주지 않는다.
		if (cursor[num - 1] < 0) {
			printf("%d 번 물고기는 이미 죽었습니다. \n", num);
		}
		//2. 어항의 물이 0이 아닌 경우 > 물을 준다 100보다 작아야뎀
		else if (cursor[num - 1] + 1 <= 100) {
			//물을 준다
			printf("%d 번 어항에 물을 준다\n\n", num);
			cursor[num - 1] += 1; //cursor[num-1] = cursor[num-1] + 1
		}

		//레벨업 할 건지 확인(레벨업은 20초마다 한번 수행)
		if (totalElaspsedTime / 20 > level - 1) {
			level++; 
			printf(" +++ 레벨 %d에서 %d레벨로 레벨업 ! \n", level - 1, level);

			//최종 레벨 5
			if (level == 5) {
				printf("\n\n 최종 레벨 달성!");
				exit(0);
			}
		}

		//모든 물고기가 죽었는지 확인
		if (checkFishAlive() == 0) {
			//물고기 다 죽음
			printf("모든 물고기가 죽었습니다\n");
		}
		else {
			//한마리 이상 생존
			printf("물고기가 아직 살아 있어요\n");
		}
		prevElapsedTime = totalElaspsedTime;

		//최초 10초 > 15초 (5초 : prev> 15초로 저장) > 25초 (10초 ... ?)


	}

	return 0;
}

void initData() {
	level = 1; //  게임 레벨
	for (int i = 0; i < 6; i++) {
		arrayFish[i] = 100; // 어항의 물높이 
	}
}

void printFishes() {
	printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1, 2, 3, 4, 5, 6);
	for (int i = 0; i < 6; i++) {
		printf(" %4d ", arrayFish[i]);
	}
	printf("\n\n");
}

void decreaseWater(long elapsedTime) {
	for (int i = 0; i < 6; i++) {
		arrayFish[i] -= (level * 3 * (int)elapsedTime); // 3 난이도 조절을 위한 값
		if (arrayFish[i] < 0) {
			arrayFish[i] = 0;
		}
	}

}
int checkFishAlive()
{
	for (int i = 0; i < 6; i++) {
		if (arrayFish[i] > 0)
			return 1; // 참 True
	}
	return 0;
}


