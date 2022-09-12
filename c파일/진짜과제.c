/* #include <stdio.h>
#include <stdlib.h>
#include<string.h>


typedef struct {
	int id;  //����ð�
	int service_time; //���� �ð�
	int arrival_time; //�����ð�
}element;

typedef struct NODE {   //���
	struct NODE* link;
	element data;
} Node;

typedef struct QUEUE {  //ť
	Node* front;
	Node* rear;
	int size;
} Queue;

Queue* InitQueue(void) {  //ť �ʱ�ȭ
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->front = queue->rear = NULL;
	queue->size = 0;
	return queue;
}

void enqueue(Queue* queue, element item) {  //ť�� data �ֱ�
	Node* tmp = (Node*)malloc(sizeof(Node));

	tmp->data = item;
	tmp->link = NULL;

	if (queue->size == 0) {
		queue->front = tmp;
	}

	else {
		queue->rear->link = tmp;
	}
	queue->rear = tmp;
	queue->size++;
}

element dequeue(Queue* queue) {  //ť���� ������ ����
	Node* cur;
	element tmp;
	cur = queue->front;
	int size = queue->size;
	puts("");

	if (cur == NULL) {
		//puts("ť�� ��.\n");
	}

	else {
		queue->size--;
		tmp = cur->data;
		queue->front = queue->front->link;
		//if (queue->front == NULL) queue->rear = NULL;

		free(cur);
		return tmp;
	}
	queue->front = cur;
}
 
void PrintQueue(Queue* queue) {  //ť�� ��� ������ ���
	Node* tmp = (Node*)malloc(sizeof(Node));

	tmp = queue->front;
	int size = queue->size - 1;

	puts("\nť ������ ����");
	
	if (tmp == NULL) puts("�������� �����Ͱ� �����ϴ�.");
	while (tmp != NULL) {
		printf("ť (%d) = %d\n", queue->size - (size--), tmp->data);

		tmp = tmp->link;
	}
	

	puts("ť ������ �Ϸ�");
}  
int IsPrimeNumber(int n) //�Ҽ� �Ǻ� �Լ�
{
	int i = 0;
	int last = n / 2;   //����� ���� ���� �Ҽ��̹Ƿ� 2���� n/2(�ڱ��ڽ�/2)������ Ȯ���ϸ� ��
	if (n <= 1)//�Ҽ��� 1���� ū �ڿ������� ��
	{
		return 0;
	}
	//(�ڱ��ڽ�/2)���� ū���� ����� �� �� ����
	for (i = 2; i <= last; i++) //i�� 2���� last���� 1�� ������Ű�� �ݺ� ����
	{
		if ((n % i) == 0) //n�� i�� ���������� �������� 0�̸�(��, i�� n�� ����� �ƴ�)
		{
			return 0; //�Ҽ��� �ƴϹǷ� 0��ȯ(i�� ����̹Ƿ� n�� �Ҽ��� �ƴ�)
		}
	}
	return 1; //1~last(�ڱ��ڽ�/2)���̿� ����� �����Ƿ� �Ҽ���
} 

void delete_pos(Queue* queue, int pos) //pos��°�� ��� ����
{

	if (queue->size < pos) {
		puts("�����Ϸ��� ��尡 list�� ���̺��� Ů�ϴ�.\n");
	}
	else {
		if (queue->size == 0) {
			puts("ť�� ��.\n");
		}

		else
		{
			
			Node* pre;  //������ ����� �����
			Node* removed;  // ������ ���
			pre = queue->front;
			if (pos == 1) {   //ù��° ��� ����
				//removed = pre;  //������ ��� ����
				if (queue->size == 1)
				{
					
					queue->front = NULL;
					queue->rear = NULL;
					queue->size--;
										
				}
				else
				{	
					queue->front = queue->front->link; //�� ���(���)�� ����� ���� 
					queue->size--;
				}
			}
			else {

				for (int i = 1; i <= (pos - 2); i++)  //�ι�° �̻� ��� ���� 2��° ��� ������ �Ѿ
				{
					pre = pre->link;
				}
				removed = pre->link;  //������ ��� ����
				pre->link = removed->link; ////�� ���� ����� ����
				queue->size--;
		
				
			}
		}
	}
}
	
void delete_prime(Queue* queue, int pos) {  // data�� pos�� ��� ����
	Node* p = queue->front;
	int n = 1;

	if (queue->size == 0)  //��尡 ������� ����
	{
		return;
	}
	while (1) {
		if (p != NULL)

		{
			if (p->data.id == pos) {   // p����� �����Ͱ� pos�̸�
				delete_pos(queue, n);  // n��° ��� ����
			}
			
			if (n > queue->size) { return; } //����Ʈ ���̺��� n��ũ�� �Լ� ����
			p = p->link; //   �˻��� ��� ����
			n++;   // �˻��� ��� ����			}

		}
		else return;
		//} while (p != NULL); // p��尡 NULL�̸� �ݺ��� ����	

	}
}


void enqueue_first(Queue* queue, element item) {   //���� �� ��忡 ��� ����, ������ ����
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = item;
	tmp->link = NULL;
	if (queue->size == 0)
	{
		queue->front = tmp;
		queue->rear = tmp;
	}
	else{
	
	tmp->link = queue->front;
	queue->front = tmp;
	}
	queue->size++;
}


void main(void) {
	//enqueue(queue, 11);
	//PrintQueue(queue);
	//dequeue(queue);
	srand(time(NULL)); //���� �ʱ�ȭ

	Queue* atm1 = InitQueue(); //ť �ʱ�ȭ
	Queue* atm2 = InitQueue();
	Queue* atm3 = InitQueue();

	int minutes = 120; // �ѽð�  ��ٸ��ð�= �ð�-�����Դ���
	int total_wait = 0;  //�ѱ�ٸ��ð�  clock= clock+
	int total_customer = 0; //���񽺸� ���� �� �մԼ�

	int service_time_1 = 0;  //ù ���񽺽ð��� 0���� �ʱ�ȭ
	int service_time_2 = 0;
	int service_time_3 = 0;

	int service_customer_1;  //���񽺸� ���� �մ�
	int service_customer_2;
	int service_customer_3;



	for (int clock = 0; clock < 120; clock++)
	{
		int minute10 = -1; // 10�и��� 1�� �ٲ�� ����
		int vip;	 //vip ����;
		vip = rand() % 10 + 1;   //10%�� Ȯ�� ����
		element customer;
		int hour = 9;  //9��
		if (clock >= 60)  //���� 60�� �Ǹ� 10�÷� �ٲ�
		{
			hour = 10; 
		}
		customer.arrival_time = clock;       //�����ð�- clock
		customer.id = clock % 60;   //��ȣ ����
		customer.service_time = rand() % 9 + 2;  //���񽺽ð� ����




		if (clock % 10 == 0 && clock >= 10) minute10 = 1;   //10�и��� minute10�� 1�� ��

		if (minute10 == 1) { //10�и���
			for (int i = 1; i < 60; i++)  //�Ҽ��̸� �� ��� ��
			{

				if (IsPrimeNumber(i) == 1)  //i�� �Ҽ��̸�
				{
					delete_prime(atm1, i);   // atm ��忡�� ������ ���� i�� ��� ��
					delete_prime(atm2, i);    
					delete_prime(atm3, i);    

				}
			}
		}



		if (atm1->size < atm2->size && atm1->size < atm3->size)   // atm1 ���̰� ���� ������
		{
			if (vip == 1)   //vip �̸�
				enqueue_first(atm1, customer); //���� ���� ��忡 �������
			else {
				enqueue(atm1, customer);  //vip�� �ƴϸ� enqueue

				if (service_time_1 <= 0) // atm1�� ��  
				{
					if (!atm1->size == 0)    //atm�� ���������
					{
						element customer = dequeue(atm1);  // �մ� atm�� ����
						total_customer++;  //�� ���� ���� ��� ����
						total_wait = total_wait + clock - customer.arrival_time;//�� ��ٸ��ð� ����
						printf("%d�� %d�� - %d�� ��(%d�� �ҿ�)�� 1�� ATM���� ���񽺸� ������\n",
							hour, clock % 60, customer.id, customer.service_time);

						service_time_1 = customer.service_time;  //���� �ð� ����
					}
				}
				else if (service_time_1 > 0) //���� �������� ��������
				{
					service_time_1--;  //���� �ð� 1����
					service_time_2--;
					service_time_3--;
				}
			}
		}
		else if (atm2->size < atm1->size && atm2->size < atm3->size)
		{
			if (vip == 1)
				enqueue_first(atm2, customer);
			else {
				enqueue(atm2, customer);

				if (service_time_2 <= 0) // atm2�� ��
				{
					if (!atm2->size == 0)
					{
						element customer = dequeue(atm2);
						total_customer++;
						total_wait = total_wait + clock - customer.arrival_time;//��ٸ��ð�
						printf("%d�� %d�� - %d�� ��(%d�� �ҿ�)�� 2�� ATM���� ���񽺸� ������\n",
							hour, clock % 60, customer.id, customer.service_time);  

						service_time_2 = customer.service_time;   
					}
				}
				else if (service_time_2 > 0) //���� �������� ��������
				{
					service_time_1--;
					service_time_2--;
					service_time_3--;
				}
			}
		}
		else if (atm3->size < atm1->size && atm3->size < atm2->size)
		{
			if (vip == 1)
				enqueue_first(atm3, customer);
			else {
				enqueue(atm3, customer);

				if (service_time_3 <= 0) // atm3�� ��
				{
					if (!atm3->size == 0)
					{
						element customer = dequeue(atm3);
						total_customer++;
						total_wait = total_wait + clock - customer.arrival_time;//��ٸ��ð�
						printf("%d�� %d�� - %d�� ��(%d�� �ҿ�)�� 3�� ATM���� ���񽺸� ������\n",
							hour, clock % 60, customer.id, customer.service_time);

						service_time_3 = customer.service_time;
					}
				}
				else if (service_time_3 > 0) //���� �������� ��������
				{
					service_time_1--;
					service_time_2--;
					service_time_3--;
				}
			}
		}

		else //ATM ���� ������ ���̰� ������
		{
			int a = rand() % 3 + 1;  //����
			if (a == 1) {
				if (vip == 1)
					enqueue_first(atm1, customer);
				else {
					enqueue(atm1, customer);

					if (service_time_1 <= 0) // atm1�� ��
					{
						if (!atm1->size == 0)
						{
							element customer = dequeue(atm1);
							total_customer++;
							total_wait = total_wait + clock - customer.arrival_time;//��ٸ��ð�
							printf("%d�� %d�� - %d�� ��(%d�� �ҿ�)�� 1�� ATM���� ���񽺸� ������\n",
								hour, clock % 60, customer.id, customer.service_time);

							service_time_1 = customer.service_time;
						}
					}
					else if (service_time_1 > 0) //���� �������� ��������
					{
						service_time_1--;
						service_time_2--;
						service_time_3--;
					}
				}
			}
			else if (a == 2) {
				if (vip == 1)
					enqueue_first(atm2, customer);
				else {
					enqueue(atm2, customer);

					if (service_time_2 <= 0) // atm2�� ��
					{
						if (!atm2->size == 0)
						{
							element customer = dequeue(atm2);
							total_customer++;
							total_wait = total_wait + clock - customer.arrival_time;//��ٸ��ð�
							printf("%d�� %d�� - %d�� ��(%d�� �ҿ�)�� 2�� ATM���� ���񽺸� ������\n",
								hour, clock % 60, customer.id, customer.service_time);

							service_time_2 = customer.service_time;
						}
					}
					else if (service_time_2 > 0) //���� �������� ��������
					{
						service_time_1--;
						service_time_2--;
						service_time_3--;
					}
				}
			}
			else if (a == 3) {

				if (vip == 1)
					enqueue_first(atm3, customer);
				else {
					enqueue(atm3, customer);

					if (service_time_3 <= 0) // atm3�� ��
					{
						if (!atm3->size == 0)
						{
							element customer = dequeue(atm3);
							total_customer++;
							total_wait = total_wait + clock - customer.arrival_time; //��ٸ��ð�
							printf("%d�� %d�� - %d�� ��(%d�� �ҿ�)�� 3�� ATM���� ���񽺸� ������\n",
								hour, clock % 60, customer.id, customer.service_time);

							service_time_3 = customer.service_time;
						}
					}
					else if (service_time_3 > 0) //���� �������� ��������
					{
						service_time_1--;
						service_time_2--;
						service_time_3--;
					}
				}
			}
		}
	} printf("\n\n");
	printf("���񽺸� ���� �� �մԼ� : %d��\n", total_customer);
	printf("��� 1���� ��ٸ� �ð� : %d��\n", total_wait / total_customer);
	printf("10�� 59�� ���� ����� �� : %d��\n", atm1->size + atm2->size + atm3->size);

}

*/