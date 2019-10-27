#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

const long int INF = 5000000000;
const int MAX_E = 500000;
const int MAX_V = 100000;


int d[MAX_V][MAX_V];
int V;

void warshall_froyd(){
	for(int k = 0; k < V; k++)
	{
		for(int i = 0; i < V; i++)
		{
			for(int j = 0; j < V; j++)
			{
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}

int main()
{
	

	return 0;
}
	