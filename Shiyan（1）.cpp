#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 100
/*此处是顺序线性表数据结构定义*/
typedef int DataType;   //设置顺序表元素为int型 
typedef struct 
{
    DataType data[MAXLEN]; //存放顺序表元素 
       int Length;             //存放顺序表的实际长度 
}SeqList;

void  InitList( SeqList *L )/*初始化顺序表L函数*/
{                                                  
   L->Length=0;   /*初始化顺序表为空*/
}

int GetLength(SeqList *L)    //求顺序表的长度
{
        return L->Length;
}

void DispList(SeqList *L) /*显示输出顺序表L的每个元素函数*/
{               
    int i;
    for(i=0;i< L->Length;i++)
        printf("%2d", L->data[i]);   
} 

void CreateList(SeqList *L,int n)/*建立顺序表并输入多个元素函数*/
{                                    
    for (int i = 0; i < n; i++) {
        scanf("%d", &L->data[i]);
    }
    L->Length = n;
} 

int InsElem(SeqList *L, int i, DataType x)/*在顺序表L中在第i位中插入新元素x函数*/
{                                 
    if (i < 1 || i > L->Length + 1) {
        return -1; // 插入位置不合法
    }
    for (int j = L->Length; j >= i; j--) {
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = x;
    L->Length++;
    return 0;
}

int DelElem (SeqList *L, int i, DataType *x) /*在顺序表L中删除第i位元素函数*/ 
{                                       
    if (i < 1 || i > L->Length) {
        return -1; // 删除位置不合法
    }
    *x = L->data[i - 1];
    for (int j = i; j < L->Length; j++) {
        L->data[j - 1] = L->data[j];
    }
    L->Length--;
    return 0;
}

int GetElem(SeqList *L, int i, DataType *x)/*获取顺序表中第i位中元素函数*/
{                                         
    if (i < 1 || i > L->Length) {
        return -1; // 获取位置不合法
    }
    *x = L->data[i - 1];
    return 0;
}

int Locate(SeqList *L, DataType x)/*在顺序表L中定位元素x函数*/
{                                    
    for (int i = 0; i < L->Length; i++) {
        if (L->data[i] == x) {
            return i + 1; // 返回元素的位置，从1开始计数
        }
    }
    return -1; // 未找到元素
} 

void unionList(SeqList *LA,SeqList *LB) //此函数的作用是合并顺序表LA和LB
{
    int lena = LA->Length, lenb = LB->Length;
    DataType e;
    for (int i = 1; i <= lenb; i++) {
        GetElem(LB, i, &e); //取LB中第i个数据元素赋给e
        if (Locate(LA, e) == -1) { //判断LA中是否有LB中的元素
            InsElem(LA, LA->Length + 1, e); //LA中不存在和e相同者，则插入到LC中
        }
    }
}
int main(  )
{
    int n = 6;
    SeqList L;
    InitList(&L);
    CreateList(&L, n);
    DispList(&L);
}
