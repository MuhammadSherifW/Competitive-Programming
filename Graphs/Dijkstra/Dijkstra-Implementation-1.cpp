#include <iostream>
#include <fstream>
#include <cassert>  
#include <vector>
#include <string>
#include <queue>
#include <ctime>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <bitset>  
#include <cstdint> 
#include <climits>
using namespace std;

class Edge
{
public:
	int to;
	long long w;

	Edge(int to, long long w) : to(to) , w(w) {}


	bool operator < (const  Edge& e) const
	{
		return w > e.w;
	}
};

const int nodesSize = 100000 + 9;
vector<vector<Edge>> adjList(nodesSize);
priority_queue<Edge> q;
vector<long long > dis(nodesSize, LLONG_MAX);

void Dijkstra(int start)
{
	q.push(Edge(start, 0));
	while (!q.empty())
	{
		Edge minEdge = q.top();
		q.pop();

		if (dis[minEdge.to] < minEdge.w)
			continue;

		dis[minEdge.to] = minEdge.w;

		for (int i = 0; i < adjList[minEdge.to].size(); i++)
		{
			Edge edgeToRelx = adjList[minEdge.to][i];
			q.push(Edge(edgeToRelx.to, edgeToRelx.w + dis[minEdge.to]));
		}

	}
}

// Problems to Solve
// UVA 10986 - UVA 10801
// SPOJ SHOP





int main()
{
}

