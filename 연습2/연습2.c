#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

main() {
	srand(time(NULL));

	int num = rand() % 3 + 1;
	//���� 1 ����2 ��3
	int a;
	printf("���� : 1\n���� : 2\n�� : 3\n");
	scanf("%d", &a);
	switch (a)
	{
	case 1:
		if (num == 1) printf("�����");
		else if (num == 2) printf("�̱�");
		else printf("��");
	case 2:
		if (num == 1) printf("��");
		else if (num == 2) printf("���");
		else printf("�̱�");

	case 3:
		if (num == 1) printf("�̱�");
		else if (num == 2) printf("��");
		else printf("���");

	default:

		break;
	}
	printf("\n");
	switch (num)
	{
	case 1: printf("����");
		break;
	case 2: printf("����");
		break;
	case 3: printf("��");
		break;
	default:
		break;
	}
}