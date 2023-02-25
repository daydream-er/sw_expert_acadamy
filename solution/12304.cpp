#define MAX_NODE 10000

struct Node {
	int data;
	Node* prev;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].prev = 0;
	node[nodeCnt].next = 0;
	return &node[nodeCnt++];
}

void init()
{
	nodeCnt = 0;
	head = 0;
}

void addNode2Head(int data) 
{
	Node    *node;
	Node    *tmp;

	node = getNode(data);
	if (head == 0)
		head = node;
	else
	{
		tmp = head;
		node->next = tmp;
		tmp->prev = node;
		head = node;
	}
}

void addNode2Tail(int data) 
{
	Node    *node;
	Node    *tmp;

	node = getNode(data);
	if (head == 0)
		head = node;
	else
	{
		tmp = head;
		while (tmp->next != 0)
			tmp = tmp->next;
		node->prev = tmp;
		tmp->next = node;
	}
}

void addNode2Num(int data, int num) 
{
	Node    *new_node;
    Node    *tmp;
    int     i;

    new_node = getNode(data);
	if (num == 1)
	{
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}
	else
	{
		i = 1;
		tmp = head;
		while (i != num - 1)
		{
			tmp = tmp->next;
			if (tmp == 0)
				break ;
			i++;
		}
		if (tmp->next == 0)
		{
			tmp->next = new_node;
			new_node->prev = tmp;
		}
		else if (tmp != 0)
		{
			new_node->next = tmp->next;
			tmp->next->prev = new_node;
			tmp->next = new_node;
			new_node->prev = tmp;
		}
	}
}

int findNode(int data) 
{
	int		i;
	Node	*tmp;

	i = 0;
	tmp = head;
	while (tmp != 0)
	{
		i++;
		if (tmp->data == data)
			return (i);
		tmp = tmp->next;
	}
	return (-1);
}

void removeNode(int data) 
{
	Node	*tmp;

	if (head->data == data)
	{
		head = head->next;
		head->prev = 0;
	}
	else
	{
		tmp = head;
		while (tmp->next->data != data)
		{
			tmp = tmp->next;
			if (tmp->next == 0)
				break ;
		}
		if (tmp->next && tmp->next->next == 0)
			tmp->next = 0;
		else if (tmp->next != 0)
		{
			tmp->next = tmp->next->next;
			tmp->next->prev = tmp;
		}
	}
}

int getList(int output[MAX_NODE]) 
{
	Node	*node;
	int		i;

	node = head;
	i = 0;
	while (node != 0)
	{
		output[i] = node->data;
		node = node->next;
		i++;
	}
	return (i);
}

int getReversedList(int output[MAX_NODE]) 
{
	Node	*node;
	Node	*tail;
	int		i;

	node = head;
	while (node->next != 0)
		node = node->next;
	tail = node;
	i = 0;
	while (tail != 0)
	{
		output[i] = tail->data;
		tail = tail->prev;
		i++;
	}
	return (i);
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_NODE 10000

enum { ADD_HEAD = 1, ADD_TAIL, ADD_NUM, FIND, REMOVE, PRINT, PRINT_REVERSE, END = 99 };

extern void init();
extern void addNode2Head(int data);
extern void addNode2Tail(int data);
extern void addNode2Num(int data, int num);
extern int findNode(int data);
extern void removeNode(int data);
extern int getList(int output[MAX_NODE]);
extern int getReversedList(int output[MAX_NODE]);

static void run() {
	while (1) {
		int cmd, data, num, cnt, i = 0;
		int output[MAX_NODE] = { 0 };

		scanf("%d", &cmd);
		switch (cmd) {
		case ADD_HEAD: // 1
			scanf("%d", &data);
			addNode2Head(data);
			break;
		case ADD_TAIL: // 2
			scanf("%d", &data);
			addNode2Tail(data);
			break;
		case ADD_NUM: // 3
			scanf("%d %d", &data, &num);
			addNode2Num(data, num);
			break;
		case FIND: // 4
			scanf("%d", &data);
			num = findNode(data);
			printf("%d\n", num);
			break;
		case REMOVE: // 5
			scanf("%d", &data);
			removeNode(data);
			break;
		case PRINT: // 6
			cnt = getList(output);
			while (cnt--)
				printf("%d ", output[i++]);
			printf("\n");
			break;
		case PRINT_REVERSE: // 7
			cnt = getReversedList(output);
			while (cnt--)
				printf("%d ", output[i++]);
			printf("\n");
			break;
		case END:
			return;
		}
	}
}

int main(void) {
	setbuf(stdout, NULL);
	freopen("dll_input.txt", "r", stdin);

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("#%d\n", t);
		init();
		run();
		printf("\n");
	}

	return 0;
}