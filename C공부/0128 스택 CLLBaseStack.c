#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"
#include "CLLBaseStack.h"

void StackInit(Stack* pstack)
{
	pstack->plist = (List*)malloc(sizeof(List));
	ListInit(pstack->plist);
}
int SIsEmpty(Stack* pstack)
{
	if (pstack->plist->tail==NULL)
	{
		return TRUE;
	}
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data)
{
	LInsertFront(pstack->plist, data);
}
Data SPop(Stack* pstack)
{
	Data rdata;
	LFirst(pstack->plist, &rdata);
	LRemove(pstack->plist);
	return rdata;

}
Data SPeek(Stack* pstack)
{
	Data rdata;
	LFirst(pstack->plist, &rdata);
	return rdata;
}