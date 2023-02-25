#define MAX_NODE 10000

struct Node {
	int data;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].next = 0;
	return &node[nodeCnt++];
}

void init()
{
    head = 0;
    nodeCnt = 0;
}

void addNode2Head(int data) 
{
    Node    *node;

    node = getNode(data);
    if (head == 0)
		head = node;
	else
	{
		node->next = head;
		head = node;
	}
}

void addNode2Tail(int data) 
{
    Node    *tmp;
    Node    *new_node;

	tmp = head;
    new_node = getNode(data);
	if (tmp == 0) 
		head = new_node;
	else
	{
		while (tmp->next != 0)
			tmp = tmp->next;
		tmp->next = new_node;
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
		if (tmp != 0)
		{
			new_node->next = tmp->next;
			tmp->next = new_node;
		}
	}
}

void removeNode(int data) 
{
	Node	*tmp;

	if (head->data == data)
		head = head->next;
	else
	{
		tmp = head;
		while (tmp->next->data != data)
		{
			tmp = tmp->next;
			if (tmp->next == 0)
				break ;
		}
		if (tmp->next != 0)
			tmp->next = tmp->next->next;
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


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_NODE 10000

enum { ADD_HEAD = 1, ADD_TAIL, ADD_NUM, REMOVE, PRINT, END = 99 };

extern void init();
extern void addNode2Head(int data);
extern void addNode2Tail(int data);
extern void addNode2Num(int data, int num);
extern void removeNode(int data);
extern int getList(int output[MAX_NODE]);

static void run() {
	while (1) {
		int cmd, data, num, cnt, i;
		int output[MAX_NODE] = { 0 };

		scanf("%d", &cmd);
		switch (cmd) {
		case ADD_HEAD:
			scanf("%d", &data);
			addNode2Head(data);
			break;
		case ADD_TAIL:
			scanf("%d", &data);
			addNode2Tail(data);
			break;
		case ADD_NUM:
			scanf("%d %d", &data, &num);
			addNode2Num(data, num);
			break;
		case REMOVE:
			scanf("%d", &data);
			removeNode(data);
			break;
		case PRINT:
			cnt = getList(output);
			i = 0;
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
	freopen("sll_input.txt", "r", stdin);

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