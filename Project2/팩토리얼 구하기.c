#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int factorial(int a)
{
	if (a < 1) return 1;
	else return a * factorial(a - 1);
}
int main(void) {
	int b;
	int c;
	printf("��ȣ�� �����ÿ�\n 1: ���� \n 2: ����\n");
	scanf("%d", &c);
	switch (c) {
	case 1:
		printf("�Է��� ��:");
		scanf("%d", &b);
		int t = factorial(b);
		printf("%d! = %d", b, t);
	case 2: break;
	}
}