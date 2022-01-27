#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(void)
{
	List list;
	NameCard* pcard;
	ListInit(&list);

	pcard = MakeNameCard("�̱���", "010-1111-1111");
	LInsert(&list, pcard);

	pcard = MakeNameCard("�����", "010-1111-1111");
	LInsert(&list, pcard);

	pcard = MakeNameCard("�豤��", "010-1111-1111");
	LInsert(&list, pcard);

	printf("ó�� �������� �� %d\n", LCount(&list));

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
		if (NameCompare(pcard, "�豤��")==0)
		{
			ShowNameCardInfo(pcard);
		}
		else
		{
			while (LNext(&list, &pcard))
			{
				if (NameCompare(pcard, "�豤��")==0)
				{
					ShowNameCardInfo(pcard);
					break;
				}
			}
		}
		
	}

	if (LFirst(&list, &pcard))
	{
		if (NameCompare(pcard, "�̱���") == 0)
		{
			ChangePhoneNum(pcard, "010-1234-5356");
		}
		else
		{
			while (LNext(&list, &pcard))
			{
				if (NameCompare(pcard, "�̱���") == 0)
				{
					ChangePhoneNum(pcard, "010-1234-5356");
					break;
				}
			}
		}

	}

	if (LFirst(&list, &pcard))
	{
		if (NameCompare(pcard, "�����") == 0)
		{
			pcard = LRemove(&list);
			free(pcard);
		}
		else
		{
			while (LNext(&list, &pcard))
			{
				if (NameCompare(pcard, "�����") == 0)
				{
					pcard = LRemove(&list);
					free(pcard);
					break;
				}
			}
		}

	}

	printf("���� �������� �� %d\n", LCount(&list));

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