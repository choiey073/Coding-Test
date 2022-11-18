#include<iostream>
#include<string>
#include<queue>
#include <vector>
using namespace std;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int start[2];

int BFS(int x, int y, vector <string> graph) {
	int visited[100][100] = {0,};
	queue < pair<int, int> > q;
	q.push({ x, y });
	int flag = 0;
	while (!q.empty()) {
		
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			
			// 범위가 벗어난 경우
			if (nx < 0 || nx >= 100 || ny < 0 || ny >= 100) {
				continue;
			}
			// 벽인 경우
			if (graph[nx][ny] == '1') {
				continue;
			}
			if (graph[nx][ny] == '3') {
				flag = 1;
			}
			if (graph[nx][ny] == '0' && visited[nx][ny]==0) {
				visited[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}
	}
	return flag;
}

void find_start_end(vector <string> graph) {
	for (int i = 0; i < 100; i++) {
		size_t f = graph[i].find('2');
		if (f != string::npos) {
			start[0] = i;
			start[1] = f;
			return;
		}
	}
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);

	for (int tc = 1; tc <= 10; tc++) {
		vector <string> graph;
		int k;
		cin >> k;
		for (int n = 0; n < 100; n++) {
			string s;
			cin >> s;
			graph.push_back(s);
		}
		find_start_end(graph);
		cout << "#" << k << " ";
		cout << BFS(start[0], start[1], graph) << endl;
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}