#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int getemptyposition();
int convertx(int k);
int converty(int z);

int main() {
	srand(time(NULL));

	char ani[4][5];
	char* str[10] = { -1 };
	*str[0] = "ȣ����";
	*str[1] = "��Ÿ";
	*str[2] = "����";
	*str[3] = "�ξ���";
	*str[4] = "������";
	*str[5] = "����";
	*str[6] = "��";
	*str[8] = "��";
	*str[9] = "�޹���";

	int select = -1;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int pos = getemptyposition();
			int x = convertx(pos);
			int y = converty(pos);
			ani[x][y] = str[i];
		}
	}
}

int getemptyposition()
{
	for (int k = 0; k <= 20; k++)
	{
		int ran[] = { -1 };
		if (ran[k] != -1)
		{
			ran[k] = rand() % 20;
		}
	}
}
int convertx(int k) {
	return k / 5;
}
int converty(int z)
{
	return z % 5;
}