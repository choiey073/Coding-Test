#include <bits/stdc++.h>
using namespace std;

int N, M, V;	// 정점개수, 간선개수, 시작정점
int graph[1001][1001];	// 인접 행렬 그래프
bool visited[1001];	// 정점 방문 여부
queue<int> q;

void reset() {
	for (int i = 1; i <= N; i++) {
		visited[i] = false;
	}
}
void DFS(int v) {
	visited[v] = true;
	cout << v << ' ';

	for (int i = 1; i <= N; i++) {
		if (graph[v][i] == 1 && visited[i] == false) {
			DFS(i);
		}
	}
}
void BFS(int v) {
	q.push(v);
	visited[v] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << ' ';

		for (int i = 1; i <= N; i++) {
			if (graph[x][i] == 1 && visited[i] == false) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}


int main() {
	
	freopen("input.txt", "rt", stdin);
	cin >> N >> M >> V;
	
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	reset();
	DFS(V);

	cout << "\n";

	reset();
	BFS(V);

	return 0;
}