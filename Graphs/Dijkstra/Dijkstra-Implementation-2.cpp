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
vector<vector<Edge>> adjList(nodesSize);
priority_queue<Edge> q;
vector<long long > dis(nodesSize, LLONG_MAX);
//vector<int> path (nodesSize); // for constructing paths 
void dijkstra(int start)
{
	//path[start] = -1;
	q.push(Edge(start, 0));
	dis[start] = 0;
	while (!q.empty())
	{
		Edge minEdge = q.top();
		q.pop();

		if (dis[minEdge.to] < minEdge.w)
			continue;

		for (int i = 0; i < adjList[minEdge.to].size(); i++)
		{
			Edge edgeToRelx = adjList[minEdge.to][i];
			if (edgeToRelx.w + dis[minEdge.to] < dis[edgeToRelx.to])
			{
				//path[edgeToRelx.to] = minEdge.to;
				dis[edgeToRelx.to] = edgeToRelx.w + dis[minEdge.to];
				q.push(Edge(edgeToRelx.to, edgeToRelx.w + dis[minEdge.to]));

			}
		}
	}
}



int main()
{
}

