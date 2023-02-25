#include<string>
#include<iostream>
#include<unordered_set>

using namespace std;

int main(int argc, char** argv)
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
	int test_case;
	int T;
	int	ans;
	//freopen("input.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int	N;
		int	M;
		int	count;
		string str;
		unordered_set<string> uset;
		cin >> N >> M;
		for (int i = 1; i <= N; i++)
		{
			cin >> str;
			uset.insert(str);
		}
		ans = 0;
		for (int i = 1; i <= M; i++)
		{
			cin >> str;
			count = uset.size();
			uset.insert(str);
			if (count == uset.size())
				ans++;
		}
		cout << "#" << test_case << " " << ans << endl;
	}
	return 0;
}