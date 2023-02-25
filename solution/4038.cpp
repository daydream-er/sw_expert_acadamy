#include<iostream>
#include<string>
using namespace std;

string pattern;
string sentence;
int	table[100001];

unsigned long long	kmp_alg(void)
{
	unsigned long long	ans;
	int i;
	int	j;

	ans = 0;
	for (i = 0; i <= pattern.length(); i++)
		table[i] = 0;
	j = 0;
	for (i = 1; i < pattern.length(); i++)
	{
		while (j > 0 && pattern[i] != pattern[j])
			j = table[j - 1];
		if (pattern[i] == pattern[j])
			table[i] = ++j;
	}
	j = 0;
	for (i = 0; i < sentence.length(); i++)
	{
		while (j > 0 && sentence[i] != pattern[j])
			j = table[j - 1];
		if (sentence[i] == pattern[j])
		{
			if (j == pattern.length() - 1)
			{
				ans++;
				j = table[j];
			}
			else
				j++;
		}
	}
	return (ans);
}

int main(int argc, char** argv)
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
	int test_case; 
	int T;

	//freopen("input.txt", "r", stdin);
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		unsigned long long	ans;

		cin >> sentence;
		cin >> pattern;
		ans = kmp_alg();
		cout << "#" << test_case << " " << ans << endl;
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}