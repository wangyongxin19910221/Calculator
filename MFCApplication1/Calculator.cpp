#include "stdafx.h"
#include "Calculator.h"

template <typename ElemType>
Calculator<ElemType>::Calculator()
{
	sq.base = new ElemType[STARK_INIT_SIZE];//栈底指向申请空间的首址
	if (sq.base == NULL)//申请失败
		exit(0);
	sq.top = sq.base;//top总是指向一有效元素的下一个空间（栈顶），top中没有数据
	sq.stackSize = STARK_INIT_SIZE;

}

//销毁栈，将内存空间释放
template <typename ElemType>
Calculator::~Calculator()
{
	delete[]sq.base;
}

template<typename ElemType>
void Calculator<ElemType>::Push(ElemType e)
{
	if (sq.top - sq.base >= sq.stackSize) {
		sq.base = (ElemType *)realloc(sq.base, (sq.stackSize + STARKINCREMENT) * sizeof(ElemType));
		//realloc是新申请一个新的空间，并将旧的内容拷贝到新的空间，还会释放以前的空间
		if (sq.base = NULL)
			exit(0);
		sq.top = sq.base + sq.stackSize;//因为重新分配了空间所以，重新设置栈顶
			sq.stackSize = sq.stackSize + STARKINCREMENT;
	}
	*(sq.top) = e;
	sq.top++;
}

template<typename ElemType>
bool Calculator<ElemType>::Pop(ElemType & e)
{
	if (sq.top == sq.base)
		return false;//空栈
	e = *(--(sq.top));
	return true;

}

template<typename ElemType>
void Calculator<ElemType>::clearStack()
{
	sq.top = sq.base;
}

template<typename ElemType>
int Calculator<ElemType>::StackLen()
{
	return sq.top-sq.base;
}

template<typename ElemType>
int Calculator<ElemType>::Calculation(char Postfix[])
{
	int i = 0, j;
	char c;
	char str[MAXBUFFER];
	double a = 0, b = 0;

	for (j = 0; Postfix[j] != '\0'; j++)
	{
		//        c=Postfix[j];
		while ((Postfix[j] >= 48) && (Postfix[j] <= 57) || Postfix[j] == '.') //输入的是数字
		{
			str[i] = Postfix[j];
			//            printf("str[%d]=%c\n",i,c);
			i++;
			str[i] = '\0';
			if (i >= 10)
			{
				printf("出错，输入的数据长度过大!\n");
				return -1;
			}

			//            scanf("%c",&c);
			j++;
			if ((Postfix[j] == ' '))
			{
				//                str[i]='\0';
				//                printf("str[%d]=%c\n",i,Postfix[j]);
				a = atof(str);
				//                printf("%f \n",a);
				Push(a);
				i = 0;
			}

		}

		switch (Postfix[j])
		{
		case '+':
			Pop(a);
			if (!Pop(b))//防止这是符号位（单目运算符）
			{
				Push(a);
				break;
			}
			Pop(b);
			//            printf("%f+%f=%f\n",b,a,b+a);
			Push(b + a);
			break;
		case '-':
			Pop(a);
			if (!Pop(b))//
			{
				Push(-a);
				break;
			}
			//            printf("%f-%f=%f\n",b,a,b-a);
			Push(b - a);
			break;
		case '*':
			Pop(a);
			Pop(b);
			//            printf("%f*%f=%f\n",b,a,b*a);
			Push(b*a);
			break;
		case '/':
			Pop(a);
			if (a == 0)
			{
				printf("除数不能为零 ！\n");
				return -1;
			}
			Pop(b);
			Push(b / a);

			break;
		default:
			break;
		}
	}
	Pop(a);
	return a;

}

template<typename ElemType>
bool Calculator<ElemType>::Infix2Postfix(char Infix[], char Postfix[])
{
	Calculator<char> s;
	int i = 0, j = 0;
	char e;

	printf("中缀表达式为：");
	while (Infix[j] != '\0')
	{
		while (Infix[j] >= '0' && Infix[j] <= '9')
		{
			printf("%c", Infix[j]);
			Postfix[i++] = Infix[j];
			j++;
			if (Infix[j]<'0' || Infix[j]>'9')
			{
				Postfix[i++] = ' ';
				printf(" ");
			}
		}

		switch (Infix[j])
		{

		case ')':
			s.Pop(e);
			while ('(' != e)
			{
				printf("%c ", e);
				Postfix[i++] = e;
				Postfix[i++] = ' ';
				s.Pop(e);
			}
			break;

		case '+':
		case '-':
			if (0 == s.StackLen())
				s.Push(Infix[j]);
			else
			{
				do
				{
					s.Pop(e);
					if ('(' == e)
					{
						s.Push(e);
					}
					else
					{
						printf("%c ", e);
						Postfix[i++] = e;
						Postfix[i++] = ' ';
					}
				} while (s.StackLen() && '(' != e);
				s.Push(Infix[j]);
			}
			break;

		case '*':
		case '/':
		case '(':
			s.Push(Infix[j]);
			break;

		case '\0':
			break;

		default:
			printf("\n输入格式错误！\n");
			return -1;
		}

		if ('\0' == Infix[j])
			break;
		j++;
	}

	while (s.StackLen())
	{
		s.Pop(e);
		printf("%c ", e);
		Postfix[i++] = e;
		Postfix[i++] = ' ';
	}
	Postfix[i] = '\0';
	printf("\n");
	return true;
}
