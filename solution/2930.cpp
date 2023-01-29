
    #include<iostream>

    using namespace std;

    long long heap[100001];
    int heap_idx;

    int main(int argc, char** argv)
    {
        int test_case;
        int T;
        int ret;

        scanf("%d", &T);
        for(test_case = 1; test_case <= T; ++test_case)
        {
            int operation_count;
            int x;
            int cmd;

            heap_idx = 0;
            // cout << "#" << test_case << " ";
            printf("#%d ", test_case);
            // cin >> operation_count;
            scanf("%d", &operation_count);
            for (int i = 0; i <= operation_count; i++) 
                heap[i] = 0;
            for (int i = 0; i < operation_count; i++)
            {
                scanf("%d", &cmd);
                if (cmd == 1)
                {
                    scanf("%d", &x);
                    int cur;
                    int tmp;

                    heap[++heap_idx] = x;
                    cur = heap_idx;
                    while (cur > 1 && heap[cur >> 1] < heap[cur])
                    {
                        // cout << "parent_idx : " << parent_idx << endl;
                        tmp = heap[cur];
                        heap[cur] = heap[cur >> 1];
                        heap[cur >> 1] = tmp;
                        cur = cur >> 1;
                    }
                }
                else if (cmd == 2)
                {
                    int   root;
                    int   cur;
                    int   child;
                    int   tmp;

                    if (heap_idx == 0)
                        ret = -1;
                    else
                    {
                        root = heap[1];
                        heap[1] = heap[heap_idx];
                        heap[heap_idx--] = 0;
                        cur = 1;
                        while (1) 
                        {
                            child = cur << 1;
                            if (child + 1 <= heap_idx && heap[child] < heap[child+1]) child++;
                            if (child > heap_idx || heap[child] < heap[cur]) break;
                            tmp = heap[cur];
                            heap[cur] = heap[child];
                            heap[child] = tmp;
                            cur = child;
                        }
                        ret = root;
                    }
                    printf("%d ", ret);
                }
            }
            printf("\n");
        }
        return 0;//정상종료시 반드시 0을 리턴해야합니다.
    }