#include <stdio.h>
#pragma warning(disable : 4996)
#define SIZE 100

//// Ÿ������ -> int���� element�� ���� ////
//// Ÿ�� ������ �� ���ϰ� �ϱ����� ////
typedef int element;

typedef struct {
    element list[SIZE];            //�迭
    int length;                    //���� �迭�� ����� ������ ����
}ArrayListType;

//// �迭 �ʱ�ȭ
void init(ArrayListType* L)
{
    L->length = 0;
}
////�迭�� ����ִ��� Ȯ���� �Լ�
////��������� 1, �׷��� ������ 0 ��ȯ
int is_empty(ArrayListType* L)
{
    return L->length == 0;
}
//����Ʈ�� ���� �������� 1, �׷��� ������ 0 ��ȯ
int is_full(ArrayListType* L)
{
    return L->length == SIZE;
}
//����Ʈ ������ ���
void display(ArrayListType* L)
{
    for (int i = 0; i < L->length; i++)
        printf("%d ", L->list[i]);
    printf("\n");
}


