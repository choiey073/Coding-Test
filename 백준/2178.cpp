#include <bits/stdc++.h>
using namespace std;

int n, m;
int graph[1001][1001];

//이동할 네가지 방향의 정의
int dx[] = { -1, 1, 0, 0 }; 
int dy[] = { 0, 0, -1, 1 };

int bfs(int x, int y) {
	queue<pair <int, int>> q;
	q.push({ x,y });

	while (!q.empty()) {
		int x = q.front().first;	// 현재 위치의 x좌표
		int y = q.front().second;	// 현재 위치의 y좌표
		q.pop();

		for (int i = 0; i < 4; i++) {	// 현재 위치에서 4가지 방향으로 확인
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)	continue;	// 범위 벗어나면 for문 빠져나오기
			if (graph[nx][ny] == 0) continue;	// 벽인 경우에도 무시
			if (graph[nx][ny] == 1) {	// 해당 노드를 처음 방문하는 경우에만 최단 거리 기록
				graph[nx][ny] = graph[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
	return graph[n - 1][m - 1];
}

int main() {
	
	freopen("input.txt", "rt", stdin);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}

	cout << bfs(0, 0);

	return 0;
}