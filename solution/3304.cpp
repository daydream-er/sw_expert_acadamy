
#include<iostream>
#include<string>

using namespace std;

int lcm[1000][1000];
int most_lcm[1000];

int main(int argc, char** argv)
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin>>T;
    string  str1;
    string  str2;
    string  tmp;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int ans;
        int local_lcm;
        cin >> str1 >> str2;

        for (int i = 0; i < str2.length(); i++)
            most_lcm[i] = 0;
        ans = 0;
        for (int i = 0; i < str1.length(); i++)
        {
            local_lcm = 0;
            // j - 1단계 중  가장 큰 lcm
            for (int j = 0; j < str2.length(); j++)
            {
                if (j > 0 && most_lcm[j - 1] > local_lcm)
                    local_lcm = most_lcm[j - 1];
                lcm[i][j] = 0;
                if (str1[i] == str2[j])
                {
                    lcm[i][j] = 1 + local_lcm;
                    if (ans < lcm[i][j])
                        ans = lcm[i][j];
                }
            }
            for (int j = 0; j < str2.length(); j++)
            {
                if (lcm[i][j] > most_lcm[j])
                    most_lcm[j] = lcm[i][j];
                //cout << most_lcm[j] << " (" << str1[i] << "," << str2[j] << ")"; 
            }
            // cout << endl;
        }
        cout << "#" << test_case << " " << ans << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}