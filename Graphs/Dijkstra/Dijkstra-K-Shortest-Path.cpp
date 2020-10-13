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
	Edge(int to, long long w)
	{
		this->to = to;
		this->w = w;
	}


	bool operator < (const  Edge& e) const
	{
		return w > e.w;
	}

};

const int nodesSize = 100000 + 9;
int n, m, k;
vector<vector<Edge>> adjList(nodesSize);
priority_queue<Edge> q;
vector<vector<long long>> dis(nodesSize, vector<long long >(10, LLONG_MAX));
vector<int> timesVisited(nodesSize);

void Dijkstra(int start)
{
	q.push(Edge(start, 0));
	while (!q.empty())
	{
		Edge minEdge = q.top();
		q.pop();

		if (timesVisited[minEdge.to] == k)
		{
			continue;
		}
		timesVisited[minEdge.to]++;
		dis[minEdge.to][timesVisited[minEdge.to]] = minEdge.w;
		for (int i = 0; i < (int)adjList[minEdge.to].size(); i++)
		{
			Edge edgeToRelx = adjList[minEdge.to][i];
			q.push(Edge(edgeToRelx.to, edgeToRelx.w + minEdge.w));
		}


	}

}
// Problems to Solve
// UVA 10740 
// SPOJ ROADS
