#include <stdio.h>

#define MAXSIZE 10 //定义栈中元素的最大个数

typedef struct
{
    int data[MAXSIZE]; // 静态数组存放栈元素
    int top;           // 栈顶指针
} SqStack;

// 初始化栈
void initStack(SqStack &S)
{
    S.top = -1; //初始化栈顶指针
}

// 判断栈空
bool stackEmpty(SqStack S)
{
    if (S.top == -1)
        return true; //空
    else
        return false; //非空
}

// 新元素入栈
bool push(SqStack &s, int x)
{
    if (S.top == MAXSIZE - 1)
        return false;  //栈满，报错
    S.top = S.top + 1; //指针先加1
    S.data[S.top] = x; //新元素入栈
    return true;
}

// 出栈操作
bool pop(SqStack &S, int &x)
{
    if (S.top == -1)
        return false; //栈空，报错

    x = S.data[S.top]; //栈顶元素先出栈
    S.top = S.top - 1; //指针再减1

    //可以写成x=S.data[S.top--];
    return true;
}

// 读取栈顶元素
bool getTop(SqStack S, int &x)
{
    if (S.top == -1)
        return false;  //栈空，报错
    x = S.data[S.top]; //x记录栈顶元素
    return true;
}
