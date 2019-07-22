#pragma once
#ifndef CALCULATOR_H
#endif // !CALCULATOR_H
#define CALCULATOR_H

enum MAXSIZE
{
	STARK_INIT_SIZE = 20,//�����ʼ�����
	STARKINCREMENT=10,//ջ����ʱ�򣬶�̬����������ÿ������10��Ԫ��
	MAXBUFFER=10,//��󻺳���
	MAX_EXP_LEN=100//���ʽ�Ϊ100
	
};

template <typename ElemType>
class Calculator
{
public:
	struct sqStack
	{
		ElemType *base;//ָ��ջ��
		ElemType *top;
		int stackSize;//��ǰջ���������
	};

	Calculator();
	virtual ~Calculator();

	void Push(ElemType e);
	bool Pop(ElemType &e);
	void clearStack();
	int StackLen();
	int Calculation(char Postfix[]);//��׺���ʽ�ļ���
	bool Infix2Postfix(char Infix[], char Postfix[]);

private:
	sqStack sq;


};

