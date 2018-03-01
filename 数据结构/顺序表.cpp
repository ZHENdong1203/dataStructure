#include <stdio.h>  
#include <stdlib.h>  
#define LIST_INIT_SIZE 100  
#define LISTINCREMENT 10   
#define OK 1  
#define ERROR 0   
#define OVERFLOW -2  
typedef int status;
typedef int ElemType;
typedef struct {
	ElemType *elem;       //�洢�ռ�Ļ���ַ  
	int length;      //��ǰ����  
	int listsize;    //��ǰ����Ĵ洢����  
}SqList;
status InitList(SqList &l)
{
	l.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!l.elem)
	{
		exit(OVERFLOW);
	}
	l.length = 0;//�ձ���Ϊ��  
	l.listsize = LIST_INIT_SIZE;//��ʼ����������  
	return OK;
}//˳���Ľ���

status ListInsert(SqList &l, int i, ElemType e)
{
	if (i<1 || i>l.length + 1)
	{
		return ERROR;
	}
	if (l.length >= l.listsize)
	{
		ElemType *newbase;
		newbase = (ElemType *)realloc(l.elem, (l.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)
		{
			return ERROR;
		}
		l.elem = newbase;
		l.listsize += LISTINCREMENT;
	}
	ElemType *p, *q;
	q = &(l.elem[i - 1]);
	for (p = &(l.elem[l.length - 1]); p >= q; --p)
	{
		*(p + 1) = *p;
	}
	*q = e;
	++l.length;
	return OK;
}//˳���Ĳ���

status ListDelete(SqList &l, int i, ElemType &e)
{

	if (i>l.length || i<1)
	{
		return ERROR;
	}
	ElemType *p, *q;
	p = &(l.elem[i - 1]);
	e = *p;
	q = l.elem + l.length - 1;
	for (++p; p <= q; ++p)
	{
		*(p - 1) = *p;
	}
	--l.length;
	return OK;
}//˳����ɾ��
int main()
{
	SqList List;
	int e;
	int i, j;
	printf("��ʼ��˳���\n");
	InitList(List);
	printf("��ʼ���󣺱�=%d\n", List.length);
	for (i = 4; i >= 1; i--)
		ListInsert(List, 1, i);
	printf("�ڱ������β���1-4�󣬱��е�����Ԫ��ֵΪ��\n");
	for (i = 1; i <= List.length; i++)
		printf("%d  ", List.elem[i - 1]);
	printf("\n");
	printf("��=%d\n", List.length);
	ListInsert(List, List.length + 1, 21);
	printf("�ڱ�β����21�󣬱��е�����Ԫ��ֵΪ��\n");
	for (i = 1; i <= List.length; i++)
		printf("%d  ", List.elem[i - 1]);
	printf("\n");
	printf("��=%d\n", List.length);
	printf("ɾ�����е�3��Ԫ��\n");
	ListDelete(List, 3, e);
	printf("ɾ�������Ԫ��Ϊ;\n");
	for (i = 1; i <= List.length; i++)
		printf("%d  ", List.elem[i - 1]);
	printf("\n");
	printf("��ɾ������Ϊ%d\n", e);
	printf("��=%d\n", List.length);
	system("pause");
	return 0;
}