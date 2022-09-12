/*#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 5

//typedef int element;
typedef struct {
	int id;  //����ð�
	int service_time; //���� �ð�
	int arrival_time; //�����ð�
}element;

typedef struct {
	element data;
	struct QueueNode* link;
}QueueNode;

typedef struct {
	QueueNode* front;
	QueueNode* rear;
	int count;
}LinkedQueueType;

int ListLength(LinkedQueueType* q) {
	int len = 0;
	LinkedQueueType* current;
		current= q;
	while (current->front != NULL)
	{
		len++;
		current->front = current->front->link;
	}
	return len;
}
void init_queue(LinkedQueueType* q) {
	q->rear = NULL;
	q->front = NULL;
	q->count = 0;
}
int is_empty(LinkedQueueType* q) {
	return q->count == 0;
}

void enqueue(LinkedQueueType* q, element data)
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = data;
	temp->link = NULL;
	if (is_empty(q)) {
		q->front = temp;
		q->rear = temp;
	}
	else {
		q->rear->link = temp;
		q->rear = temp;
	}
	q->count++;
}

element dequeue(LinkedQueueType* q) {
	QueueNode* temp = q->front;
	element data;
	if (is_empty(q)) {
		fprintf(stderr, "������ �������\n");
		exit(1);
	}
	else {
		data = temp->data;
		q->front = q->front->link;
		if (q->front == NULL)
			q->rear = NULL;
		free(temp);
		return data;
	}q->count--;
}
void delete(QueueNode *q, QueueNode* pre) {
	QueueNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
}

void print_list(LinkedQueueType*q) {
	for (LinkedQueueType* p = q; p->front!= NULL; p->front = p->front->link)
	{
		printf("%d->", p->front->data);
	}printf("NULL\n");
}

int shortprint(int a, int b, int c) {
	int number=  a;
	if (number > b) number = b;
	if (number > c) number = c;
	return number;
}

void main() {
	LinkedQueueType atm1; //1��° atm
	LinkedQueueType atm2; //2��° atm
	LinkedQueueType atm3;//3��° atm

	init_queue(&atm1); // atm ����Ʈ �ʱ�ȭ
	init_queue(&atm2);
	init_queue(&atm3);

	int minutes = 119; // �ѽð�
	int total_wait = 0;  //�ѱ�ٸ��ð�
	int total_customer = 0; //�� �մԼ�
	int service_time = 0;  //���񽺽ð�
	int service_customer; //���� �޴� �մ�

	srand(time(NULL));

	for (int clock = 0; clock < minutes; clock++)
	{
		element customer;
		customer.id = ++total_customer;
		customer.arrival_time = clock;// �����ð� ����
		customer.service_time = (rand() % 3) + 1; //���� �ð�

		//service_customer = customer.id;

		int list;
		 //���� ���� �� ���ϱ�
		if (atm1.count == atm2.count && atm2.count == atm3.count)
		{
			int random = (rand() % 3) + 1; //���̰� ���� ��� �������� ����
			switch (random)
			{
			case 1:
				enqueue(&atm1, customer); list = 1;
			case 2:
				enqueue(&atm2, customer); list = 2;
			case 3:
				enqueue(&atm3, customer); list = 3;

			default:
				break;
			}
		}
		else //���̰� ���� ���� ATM�� ���� ��
		{
			int Shortlist = shortprint(atm1.count, atm2.count, atm3.count);

			if (Shortlist == atm1.count) {
				enqueue(&atm1, customer);
				list = 1;
			}
			else if (Shortlist == atm2.count)
			{
				enqueue(&atm2, customer);
				list = 2;
			}
			else if (Shortlist == atm3.count)
			{
				enqueue(&atm3, customer);
				list = 3;
			}
		}
		if (service_time > 0)
		{
			printf("��%d�� �������Դϴ�.\n", service_customer);
			service_time= service_customer-1;
		}
		else
		{
			if (list == 1)//atm1 �� ����� �ٷ� ��������
			{
				if (!is_empty(&atm1))
				{
					element customer = dequeue(&atm1);
					service_customer = customer.id;
					service_time = customer.service_time;
					total_wait = total_wait + clock - customer.arrival_time;
					printf("�� %d�� %d�п� �����������մϴ�.", service_customer, clock);
				}
			}
			else if (list == 2)
				if (!is_empty(&atm2))
				{
					element customer = dequeue(&atm2);
					service_customer = customer.id;
					service_time = customer.service_time;
					total_wait = total_wait + clock - customer.arrival_time;
					printf("�� %d�� %d�п� �����������մϴ�.", service_customer, clock);
				}

				else if (list == 3)
					if (!is_empty(&atm3))
					{
						element customer = dequeue(&atm3);
						service_customer = customer.id;
						service_time = customer.service_time;
						total_wait = total_wait + clock - customer.arrival_time;
						printf("�� %d�� %d�п� �����������մϴ�.", service_customer, clock);
					}
		}

			{
			}
		}
	}

	LinkedQueueType atm1; //1��° atm
	LinkedQueueType atm2; //1��° atm

	element customer;
	init_queue(&atm1);
	init_queue(&atm2);
	customer.id = 4;
	enqueue(&atm1, customer);

	printf("%d",dequeue(&atm1));
	customer.id = 5;
	enqueue(&atm2, customer);
	printf("%d", dequeue(&atm2));
}

*/