#include <stdio.h>

typedef struct Game {
	char* name;
	int year;
	int price;
	struct Game* friendGame;
}��������;


int main(void) {
	struct Game gameInfo;
	struct Game gameInfo2 = {"����2", 2018, 100};
	
	gameInfo.name = "����";
	gameInfo.year = 2017;
	gameInfo.price = 50;
	
	
	struct Game* gamePtr;
	gamePtr = &gameInfo;

	gameInfo.friendGame = &gameInfo2;
	printf("%s\n", gameInfo.friendGame->name);
	
	��������* gamePtr2;
	gamePtr2 = &gameInfo;
	
	printf("%s\n", (*gamePtr2).friendGame->name);

}