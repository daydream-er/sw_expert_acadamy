	#include<iostream>
	#include<vector>
	#include <queue>
	#include<math.h>
	#include<stdio.h>
	using namespace std;

	typedef struct vertex
	{
		long long   x;
		long long   y;
		bool		visited;
	}   vertex;

	struct edge {
		long long	weight;
		int cVertice;
		edge(long long w, int cVer) : weight(w), cVertice(cVer) {}
		bool operator<(const edge e) const 
		{
			return this->weight > e.weight;
		}
	};

	vertex node_pool[1001];

	long long   ft_distance(vertex ver1, vertex ver2, double tax)
	{
		long long x;
		long long y;

		x = ((ver1.x) - (ver2.x)) * ((ver1.x) - (ver2.x));
		y = ((ver1.y) - (ver2.y)) * ((ver1.y) - (ver2.y));
		// return (floor((x + y) * tax + 0.5));
		return (x + y);
	}

	int main(int argc, char** argv)
	{
		std::cin.tie(nullptr);
		std::cout.tie(nullptr);
		std::ios_base::sync_with_stdio(false);

		int test_case;
		int T;

		// freopen("input.txt", "r", stdin);
		cin>>T;
		
		for(test_case = 1; test_case <= T; ++test_case)
		{
			long long   N;
			long long   x;
			long long   y;
			long long 	dist;
			double      tax;

			cin >> N;
			for (int i = 1; i <= N; i++)
			{
				cin >> x;
				node_pool[i].x = x;
			}
			for (int i = 1; i <= N; i++)
			{
				cin >> y;
				node_pool[i].y = y;
				node_pool[i].visited = false;
			}
			cin >> tax;

			long long	result;

			result = 0;
			priority_queue<edge> pq;
			node_pool[1].visited = true;
			for (int i = 1; i <= N; i++)
			{
				if (i == 1)
					continue;
				dist = ft_distance(node_pool[1], node_pool[i], tax);
				pq.push(edge(dist, i));
			}
			while (pq.empty() == false)
			{
				edge e = pq.top();

				pq.pop();
				if (node_pool[e.cVertice].visited == true)
					continue;
				result += e.weight;
				node_pool[e.cVertice].visited = true;
				for (int i = 1; i<= N; i++)
				{
					if (e.cVertice == i || node_pool[i].visited == true)
						continue;
					dist = ft_distance(node_pool[e.cVertice], node_pool[i], tax);
					pq.push(edge(dist, i));
				}
			}
			result = floor(result * tax + 0.5);
			cout << "#" << test_case << " " << result << endl;
		}
		return 0;//정상종료시 반드시 0을 리턴해야합니다.
	}