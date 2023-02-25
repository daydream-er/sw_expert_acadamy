#include<iostream>

using namespace std;

// Suppose elements of A are A[1], A[2], ... , A[N]. If i < j and A[i]> A[j], you say (A[i], A[j]) is inversed. 

int         permutation[200000];
int         tmp[200000];

int ft_min(int x, int y) 
{
    return (x < y) ? x : y;
}

unsigned long long  merge_sort(int from, int mid, int to)
{
    unsigned long long r_count;
    unsigned long long count;
    int s_idx1 = from;
    int s_idx2 = mid + 1;

    count = 0;
    r_count = 0;

    int i = from;
    while (s_idx1 <= mid && s_idx2 <= to)
    {
        if (permutation[s_idx1] < permutation[s_idx2])
        {
            tmp[i] = permutation[s_idx1++];
            count += r_count;
        }
        else
        {
            tmp[i] = permutation[s_idx2++];
            r_count++;
        }
        i++;
    }
    while (i <= to && s_idx1 <= mid)
    {
        tmp[i] = permutation[s_idx1++];
        count += r_count;
        i++;
    }
    while (i <= to && s_idx2 <= to)
    {
        tmp[i] = permutation[s_idx2++];
        i++;
    }
    for (int i = from; i <= to; i++)
    {
        permutation[i] = tmp[i];
        // cout << permutation[i] << " ";
    }
    // cout << endl;
    return (count);
}

unsigned long long merge_sort_alg(int N)
{
    int high = N - 1;
    int low = 0;
    unsigned long long count = 0;

    for (int m = 1; m <= high - low; m = 2 * m)
    {
        for (int i = low; i < high; i += 2 * m)
        {
            int from = i;
            int mid = i + m - 1;
            int to = ft_min(i + 2 * m - 1, high);

            count += merge_sort(from, mid, to);
        }
        // cout << "count : " << count << endl;
    }
    return (count);
}

int main(int argc, char** argv)
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

	int test_case;
	int T;
	// freopen("sample", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;
        unsigned long long  count;

        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> permutation[i];
            tmp[i] = 0;
        }
        count = merge_sort_alg(N);
        cout << "#" << test_case << " " << count << endl;       
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}