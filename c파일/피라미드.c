#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

main() {
	int i, j;
	printf("�Ƕ�̵带 �� �� ���� �����ðڽ��ϱ�?");
	int a;
	scanf("%d", &a);

	for (i = 1; i <= a; i++)  //�ٹٲ�
	{
		for (int k = 1; k <= (a - i); k++) // �� ����
			printf(" ");
		for (j = 1; j <= 2 * i - 1; j++) // �Ƕ�̵�
			printf("*");
		printf("\n");
	}
}