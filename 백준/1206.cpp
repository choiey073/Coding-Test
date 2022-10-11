#include <bits/stdc++.h>
using namespace std;

int N, M, V;	// 정점개수, 간선개수, 시작정점
int graph[1001][1001];	// 인접 행렬 그래프
bool visited[1001];	// 정점 방문 확인용 list
queue<int> q;

void reset() {	// 정점 개수만큼 정점 방문하지 않은 것(false)으로 방문 리스트 초기화
	for (int i = 1; i <= N; i++) {
		visited[i] = false;
	}
}
void DFS(int v) {
	visited[v] = true;	// 방문한 노드로 변경
	cout << v << ' ';	// 방문 노드 출력

	for (int i = 1; i <= N; i++) {
		if (graph[v][i] == 1 && visited[i] == false) {	// 인접한 노드 && 아직 방문한 노드가 아니라면
			DFS(i);		// 재귀적 방문
		}
	}
}
void BFS(int v) {
	q.push(v);				// 첫 노드를 queue에 삽입
	visited[v] = true;		// 첫 노드 방문처리

	while (!q.empty()) {	// 큐가 빌 때까지 반복
		int x = q.front();	// 큐의 가장 앞에 있는 원소
		q.pop();			// 가장 앞의 원소 뽑아서 출력
		cout << x << ' ';

		for (int i = 1; i <= N; i++) {
			if (graph[x][i] == 1 && visited[i] == false) {	// 방금 큐에서 뽑아낸 원소와 연결되어있고, 아직 방문하지 않은 노드라면
				q.push(i);			// queue에 삽입 후
				visited[i] = true;	// 해당 노드 방문처리
			}
		}
	}
}

int main() {
	
	freopen("input.txt", "rt", stdin);
	cin >> N >> M >> V;
	
	for (int i = 0; i < M; i++) {	// 인접 행렬 그래프에 정보 추가
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