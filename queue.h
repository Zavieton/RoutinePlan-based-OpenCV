#pragma once
#ifndef _QUEUE_H
#define _QUEUE_H

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node *pNext;
}NODE, *PNODE;

typedef struct Queue
{
	PNODE front;  //队头指针
	PNODE rear;   //队尾指针
}QUEUE, *PQUEUE;

PQUEUE create_queue();
bool empty(PQUEUE);
void en_queue(PQUEUE, int);
bool de_queue(PQUEUE, int *);
void destroy_queue(PQUEUE);
int traverse_queue_return(PQUEUE);
void traverse_queue(PQUEUE pS);



/*
创建一个空队列，队头指针和队尾指针都指向头结点，
头结点中不存放数据，只存放指针
*/
PQUEUE create_queue()
{
	PQUEUE pS = (PQUEUE)malloc(sizeof(Queue));
	pS->front = (PNODE)malloc(sizeof(NODE));
	if (!pS || !pS->front)
	{
		printf("pS or front malloc failed!!");
		exit(-1);
	}
	else
	{
		pS->rear = pS->front;
		pS->front->pNext = NULL;
	}
	return pS;
}

/*
判断队列是否为空
*/
bool empty(PQUEUE pS)
{
	if (pS->front == pS->rear)
		return true;
	else
		return false;
}

/*
进队函数，从队尾进队，队头指针保持不变
*/
void en_queue(PQUEUE pS, int e)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (!pNew)
	{
		printf("pNew malloc failed");
		exit(-1);
	}
	else
	{
		pNew->data = e;
		pNew->pNext = NULL;
		pS->rear->pNext = pNew;
		pS->rear = pNew;
	}
	return;
}

/*
出队函数，从队头出队，队尾指针保持不变，但当最后一个元素出队时，
需要对队尾指针重新赋值，使其指向头结点
*/
bool de_queue(PQUEUE pS, int *pData)
{
	if (empty(pS))
		return false;
	else
	{
		PNODE p = pS->front->pNext;
		*pData = p->data;
		pS->front->pNext = p->pNext;

		//这里是队列头元素出队的特殊情况，一般情况下，删除队头元素时
		//仅需修改头结点中的指针，但当队列中最后一个元素被删除时，
		//队列尾指针也丢失了，因此需对队尾指针重新赋值（指向头结点）。
		if (pS->rear == p)
			pS->rear = pS->front;
		free(p);
	}
	return true;
}

/*
遍历队列，从对头向队尾依次输出队中的元素
*/
void traverse_queue(PQUEUE pS)
{
	if (empty(pS))
		printf("there is no data in the queue!\n");
	else
	{
		PNODE pCurrent = pS->front->pNext;
		printf("Now datas int the queue are:\n");
		while (pCurrent)
		{
			printf("%d ", pCurrent->data);
			pCurrent = pCurrent->pNext;
		}
		printf("\n");
	}
	return;
}

/*
遍历队列，以数组的形式返回队列值
*/
int* traverse_queue_return(PQUEUE pS,int length)
{
	int* returnArr = new int[length];
	if (empty(pS))
		printf("there is no data in the queue!\n");
	else
	{
		PNODE pCurrent = pS->front->pNext;
		for(int i = 0;i < length ;i++)
		{
			returnArr[i] = int(pCurrent->data);
			pCurrent = pCurrent->pNext;
		}
		printf("\n");
	}
	return returnArr;
}

/*
销毁队列,头结点也被销毁,最后也将pS节点销毁，并将其指向为空，避免垂直指针的产生
*/
void destroy_queue(PQUEUE pS)
{
	if (empty(pS))
		return;
	else
	{
		while (pS->front)
		{
			pS->rear = pS->front->pNext;
			free(pS->front);
			pS->front = pS->rear;
		}
	}
	free(pS);
	pS = 0;
	return;
}


#endif
