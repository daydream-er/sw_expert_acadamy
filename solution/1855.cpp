#include<queue>
#include<iostream>

// lca, very good.
#define max_level 16
using namespace std;

typedef struct NODE
{
    int         idx;
	int			depth;
    NODE        *parent;
    NODE        *head_child;
    NODE        *tail_child;
    NODE        *next_sibling;
}	NODE;

NODE	node_pool[100001];
int     node_parent[100001][17];

void	ft_init(int N)
{
	for (int i = 0; i <= N; i++)
	{
		node_pool[i].parent = 0;
		node_pool[i].head_child = 0;
		node_pool[i].tail_child = 0;
		node_pool[i].next_sibling = 0;
		node_pool[i].depth = 0;
	}
    for (int d = 0; d <= max_level; d++)
        node_parent[1][d] = 0;
}   

int LCA(int idx1, int idx2)
{
    int high;
    int low;
    int mid;
    int d;
    int lca;

    if (node_pool[idx1].depth < node_pool[idx2].depth)
    {
        idx2 = node_parent[idx2][0];
    }
    else if (node_pool[idx1].depth > node_pool[idx2].depth)
    {
        idx1 = node_parent[idx1][0];
    }
    lca = idx1;
    if (idx1 != idx2)
    {
        for (int i = max_level; i >= 0; i--)
        {
            if (node_parent[idx1][i] != node_parent[idx2][i])
            {
                idx1 = node_parent[idx1][i];
                idx2 = node_parent[idx2][i];
            }
            lca = node_parent[idx1][i];
        }
    }
    return (lca);
}

int main(int argc, char** argv)
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

	int test_case;
	int T;
	int	N;
	int	parent;

	//freopen("input.txt", "r", stdin);
	cin>>T;

    unsigned long long  move;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
        ft_init(N);
        node_pool[1].parent = 0;
		node_pool[1].next_sibling = 0;
		node_pool[1].depth = 0;
        node_pool[1].idx = 1;
		for (int i = 2; i <= N; i++)
        {
            int parent;

            cin >> parent;
			node_pool[i].parent = &node_pool[parent];
			node_pool[i].depth = node_pool[parent].depth + 1;
			node_pool[i].idx = i;
			if (node_pool[parent].tail_child == 0 && node_pool[i].head_child == 0)
			{
				node_pool[parent].head_child = &node_pool[i];
				node_pool[parent].tail_child = &node_pool[i];
			}
			else
			{
				node_pool[parent].tail_child->next_sibling = &node_pool[i];
				node_pool[parent].tail_child = &node_pool[i];
			}
            node_parent[i][0] = node_pool[i].parent->idx;
            for (int d = 1; d <= max_level; d++)
                node_parent[i][d] = node_parent[node_parent[i][d - 1]][d - 1];
        }
        // cout << endl;
        // for (int i = 1; i <= N; i++)
        // {
        //     for (int j = 0; j <= max_level; j++)
        //         cout << node_parent[i][j] << " ";
        //     cout << endl;
        // }
        NODE		    *node;
        queue<NODE *>   qq;
        int             before_idx;
        int             lca;

        move = 0;
        qq.push(&node_pool[1]);
        while (qq.empty() == false)
        {
            node = qq.front();
            qq.pop();
            if (node->idx != 1)
            {
                lca = LCA(before_idx, node->idx);
                move = move + (node_pool[node->idx].depth - node_pool[lca].depth);
                move = move + (node_pool[before_idx].depth - node_pool[lca].depth);
            }
            before_idx = node->idx;
            node = node->head_child;
            while (node != 0)
            {
                qq.push(node);
                node = node->next_sibling;
            }
        }
        if (N == 2)
            move = 1;
		cout << "#" << test_case << " " << move << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}