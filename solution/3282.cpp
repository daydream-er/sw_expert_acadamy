
#include<iostream>

using namespace std;

int work[101];
int cost[101];
int dp[101][1001];

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;
        int K;

        cin >> N >> K;
        for (int i = 1; i <= N; i++)
            cin >> work[i] >> cost[i];
        for (int w = 0; w <= N; w++)
            dp[w][0] = 0;
        for (int v = 0; v <= K; v++)
            dp[0][v] = 0;
        
        int volumn;
        for (int w = 1; w <= N; w++)
        {
            volumn = work[w];
            for (int v = 1; v <= K; v++)
            {
                int pre_volumn;

                pre_volumn = v - volumn;
                if (pre_volumn < 0)
                    dp[w][v] = dp[w - 1][v];
                else if (dp[w - 1][pre_volumn] + cost[w] < dp[w - 1][v])
                    dp[w][v] = dp[w - 1][v];
                else
                    dp[w][v] = dp[w - 1][pre_volumn] + cost[w];
            }
            // cout << endl;
            // for (int w = 1; w <= N; w++)
            // {
            //     for (int v = 1; v <= K; v++)
            //     {
            //         cout << dp[w][v] << " ";
            //     }
            //     cout << endl;
            // }
        }
        cout << "#" << test_case << " " << dp[N][K] << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}