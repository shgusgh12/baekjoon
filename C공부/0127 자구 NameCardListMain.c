#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(void)
{
	List list;
	NameCard* pcard;
	ListInit(&list);

	pcard = MakeNameCard("檜惜熱", "010-1111-1111");
	LInsert(&list, pcard);

	pcard = MakeNameCard("夢營熱", "010-1111-1111");
	LInsert(&list, pcard);

	pcard = MakeNameCard("梯惜熱", "010-1111-1111");
	LInsert(&list, pcard);

	printf("籀擠 等檜攪曖 熱 %d\n", LCount(&list));

	if (LFirst(&list, &pcard))
	{
		ShowNameCardInfo(pcard);

		while (LNext(&list, &pcard))
		{
			ShowNameCardInfo(pcard);
		}
	}

	printf("\n\n");


	if (LFirst(&list, &pcard))
	{
		if (NameCompare(pcard, "梯惜熱")==0)
		{
			ShowNameCardInfo(pcard);
		}
		else
		{
			while (LNext(&list, &pcard))
			{
				if (NameCompare(pcard, "梯惜熱")==0)
				{
					ShowNameCardInfo(pcard);
					break;
				}
			}
		}
		
	}

	if (LFirst(&list, &pcard))
	{
		if (NameCompare(pcard, "檜惜熱") == 0)
		{
			ChangePhoneNum(pcard, "010-1234-5356");
		}
		else
		{
			while (LNext(&list, &pcard))
			{
				if (NameCompare(pcard, "檜惜熱") == 0)
				{
					ChangePhoneNum(pcard, "010-1234-5356");
					break;
				}
			}
		}

	}

	if (LFirst(&list, &pcard))
	{
		if (NameCompare(pcard, "夢營熱") == 0)
		{
			pcard = LRemove(&list);
			free(pcard);
		}
		else
		{
			while (LNext(&list, &pcard))
			{
				if (NameCompare(pcard, "夢營熱") == 0)
				{
					pcard = LRemove(&list);
					free(pcard);
					break;
				}
			}
		}

	}

	printf("⑷營 等檜攪曖 熱 %d\n", LCount(&list));

	if (LFirst(&list, &pcard))
	{
		ShowNameCardInfo(pcard);

		while (LNext(&list, &pcard))
		{
			ShowNameCardInfo(pcard);
		}
	}
	return 0;
}