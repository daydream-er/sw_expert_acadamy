
#include<iostream>

using namespace std;

int max_heap[200001];
int min_heap[200001];
unsigned int heap_max_size;
unsigned int heap_min_size;

void    ft_swap(int i, int j, bool is_max_heap)
{
    int tmp;

    if (is_max_heap)
    {
        tmp = max_heap[i];
        max_heap[i] = max_heap[j];
        max_heap[j] = tmp;
    }
    else
    {
        tmp = min_heap[i];
        min_heap[i] = min_heap[j];
        min_heap[j] = tmp;
    }
}

void    ft_push_heap(bool is_max_heap, int nbr)
{
    unsigned int    cur;

    if (is_max_heap)
    {
        max_heap[++heap_max_size] = nbr;
        cur = heap_max_size;
        while (cur > 1 && max_heap[cur >> 1] < max_heap[cur])
        {
            ft_swap(cur >> 1, cur, true);
            cur = cur >> 1;
        }
    }
    else
    {
        min_heap[++heap_min_size] = nbr;
        cur = heap_min_size;
        while (cur > 1 && min_heap[cur >> 1] > min_heap[cur])
        {
            ft_swap(cur >> 1, cur, false);
            cur = cur >> 1;
        }
    }
}

int ft_pop_heap(bool is_max_heap)
{
    unsigned int    child;
    unsigned int    cur;
    int ret;

    if (is_max_heap)
    {
        if (heap_max_size == 0)
            return (-1);
        cur = 1;
        ret = max_heap[cur];
        max_heap[cur] = max_heap[heap_max_size];
        max_heap[heap_max_size--] = 0;
        while (1)
        {
            child = cur << 1;
            if (child + 1 <= heap_max_size && max_heap[child] < max_heap[child + 1]) child++;
            if (child > heap_max_size || max_heap[child] < max_heap[cur]) break ;
            ft_swap(cur, child, true);
            cur = child;
        }
    }
    else
    {
        if (heap_min_size == 0)
            return (-1);
        cur = 1;
        ret = min_heap[cur];
        min_heap[cur] = min_heap[heap_min_size];
        min_heap[heap_min_size--] = 0;
        while (1)
        {
            child = cur << 1;
            if (child + 1 <= heap_min_size && min_heap[child] > min_heap[child + 1]) child++;
            if (child > heap_min_size || min_heap[child] > min_heap[cur]) break ;
            ft_swap(cur, child, false);
            cur = child;
        }
    }
    return (ret);
}

int make_heap(int a, int b, int mid)
{
    int array[3] = {a, b, mid};
    int tmp;

    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            if (array[i] > array[j])
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
    // if (!(array[0] <= array[1] && array[1] <= array[2]))
    // {
    //     cout << "error\n";
    //     return (-1);
    // }
    ft_push_heap(true, array[0]);
    ft_push_heap(false, array[2]);
    return (array[1]);
}

int main(void)
{
	int test_case;
	int T;

    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;
        int mid;
        int a, b;
        int tmp;
        size_t  result = 0;

        heap_max_size = 0;
        heap_min_size = 0;
        cin >> N;
        cin >> mid;
        for (int size = 1; size <= N; size++)
        {
            cin >> a >> b;    
            if (size != 1)
            {
                if (a > b)
                {
                    tmp = a;
                    a = b;
                    b = tmp;
                }
                ft_push_heap(true, a);
                ft_push_heap(false, b);
                a = ft_pop_heap(true);
                b = ft_pop_heap(false);
            }
            mid = make_heap(a, b, mid);
            // cout << "mid : " << mid << endl;
            result += mid % 20171109;
            // cout << "mid : " << mid << " mid % 20171109 : " << mid % 20171109 << endl;
        }
        cout << "#" << test_case << " " << result % 20171109 << endl;
	}
	return 0;
}