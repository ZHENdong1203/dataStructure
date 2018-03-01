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
	ElemType *elem;       //存储空间的基地址  
	int length;      //当前长度  
	int listsize;    //当前分配的存储容量  
}SqList;
status InitList(SqList &l)
{
	l.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!l.elem)
	{
		exit(OVERFLOW);
	}
	l.length = 0;//空表长度为零  
	l.listsize = LIST_INIT_SIZE;//初始化储存容量  
	return OK;
}//顺序表的建立

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
}//顺序表的插入

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
}//顺序表的删除
int main()
{
	SqList List;
	int e;
	int i, j;
	printf("初始化顺序表\n");
	InitList(List);
	printf("初始化后：表长=%d\n", List.length);
	for (i = 4; i >= 1; i--)
		ListInsert(List, 1, i);
	printf("在表中依次插入1-4后，表中的数据元素值为：\n");
	for (i = 1; i <= List.length; i++)
		printf("%d  ", List.elem[i - 1]);
	printf("\n");
	printf("表长=%d\n", List.length);
	ListInsert(List, List.length + 1, 21);
	printf("在表尾插入21后，表中的数据元素值为：\n");
	for (i = 1; i <= List.length; i++)
		printf("%d  ", List.elem[i - 1]);
	printf("\n");
	printf("表长=%d\n", List.length);
	printf("删除表中第3个元素\n");
	ListDelete(List, 3, e);
	printf("删除后表中元素为;\n");
	for (i = 1; i <= List.length; i++)
		printf("%d  ", List.elem[i - 1]);
	printf("\n");
	printf("被删除的数为%d\n", e);
	printf("表长=%d\n", List.length);
	system("pause");
	return 0;
}