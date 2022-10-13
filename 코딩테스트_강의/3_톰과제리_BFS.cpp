#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios_base::sync_with_stdio(false);	// 입력의 양이 많을 때는 꼭 이 구문 쓰기!
	freopen("input.txt", "rt", stdin);

	int n;	// 정사각형 방의 크기
	cin >> n;

	vector<vector<int> > pan(n + 1, vector<int>(n + 1, 0));	// 정사각형 방의 정보
	// 2차원 벡터, n+1의 원소를 가지고 있고, 각 원소(vector)는 n+1의 원소를 가지며 해당 원소들은 0으로 초기화된다.
	// v[0][0] ~ v[n+1][n+1]까지 전부 0인 2차원 vector로 초기화.

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> pan[i][j];	// 2차원 벡터에 방 정보 입력
		}
	}

	int sx, sy, ex, ey;
	cin >> sx >> sy;	// 톰의 위치
	cin >> ex >> ey;	// 제리의 위치

	queue<pair<int, int> > Q;	// pair형 Queue. pair를 쓴 이유는 좌표를 넣으려고..
	Q.push(make_pair(sx, sy));	// 처음에 큐에 톰의 위치 push
	pan[sx][sy] = 2;	// 톰의 위치에 2를 넣어줌.(2로 출발)

	while (!Q.empty()) {
		// (x,y) : Q의 첫번째 좌표
		int x = Q.front().first;	
		int y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {	// 4방향 탐색
			int xx = x;
			int yy = y;
			
			// 직선탐색하는 while문
			while (xx + dx[i] > 0 && xx + dx[i] <= n && yy + dy[i] > 0 && yy + dy[i] <= n	// 경계선 조건
				&& pan[xx+dx[i]][yy+dy[i]] !=1 ) {	// 가고자 하는 곳이 벽이 아닌 경우
				
				if (pan[xx + dx[i]][yy + dy[i]] == 0) {	// 아직 방문하지 않은 경우에만 갱신.
					Q.push(make_pair(xx + dx[i], yy + dy[i]));
					pan[xx + dx[i]][yy + dy[i]] = pan[x][y] + 1;	// 이미 있는 회전수에 + 1
				}
				xx = xx + dx[i];
				yy = yy + dy[i];
			}
		}
		for (int k = 1; k <= n; k++) {
			for (int kk = 1; kk <= n; kk++) {
				cout << pan[k][kk] << " ";
			}
			cout << endl;
		}
		cout << "--------------------------------" << endl;
	}


	if (pan[ex][ey] == 0) {	// 제리한테까지 도달하지 못한 경우
		cout << -1;
	}
	else {
		cout << pan[ex][ey] - 3;	// 2부터 시작했고, 회전수는 -1 계산 해줘야하므로 총 -3
	}


	return 0;
}