#include <bits/stdc++.h>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };	// 방향탐색
int dy[4] = { 0, 1, 0, -1 };	// 방향탐색
int board[1001][1001];	// 입력값
int dis[2][1001][1001];	
// dis[0] : 영희 -> 산딸기 거리 저장할 2차원 배열
// dis[1] : 산딸기 -> 기사 거리 저장할 2차원 배열
queue<pair<int, int>> Q;	// queue로는 좌표가 들어옴.
int w, h;

void BFS(int idx) {	// idx==0 : 영희->산딸기, idx==1 : 산딸기->기사
	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx >= 0 && nx < h && ny >= 0 && ny < w && dis[idx][nx][ny] == 0) {
				// 경계 설정 && dis==0이면 방문 안한거(방문했다면 이미 거리값이 갱신되어있음) 
				if (board[nx][ny] != 1) {	//1이면 막혀있으니까 못감
					dis[idx][nx][ny] = dis[idx][x][y] + 1;
					//[x][y]까지 간 날짜에 +1을해서 저장해주는 것.
					Q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	// 입력을 빨리하기 위함.
	freopen("input.txt", "rt", stdin);
	
	cin >> w >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> board[i][j];	// c언어는 input의 띄어쓰기와 엔터를 같은 구분자로 취급
		}
	}

	int j;
	for (int i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			if (board[i][j] == 2) {	// 영희의 위치
				dis[0][i][j] = 1;	// 영희의 위치 1로 check
				Q.push(make_pair(i, j));	// 영희의 위치를 pair로 queue에 넣음
				BFS(0);	// 그 다음에 영희(0)에서 출발하는 BFS 돌림.
				break;
			}
		}
		if (j < w)	break;	// 이미 발견 했으면 i for문 더 돌릴 필요 없음
	}

	for (int i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			if (board[i][j] == 3) {	// 기사의 위치
				dis[1][i][j] = 1;	// 기사의 위치 1로 check
				Q.push(make_pair(i, j));	// 기사의 위치를 pair로 queue에 넣음
				BFS(1);	// 그 다음에 영희(0)에서 출발하는 BFS 돌림.
				break;
			}
		}
		if (j < w)	break;	// 이미 발견 했으면 i for문 더 돌릴 필요 없음
	}
	//여기까지 하면 dis배열 두개 완성

	int mini = INT_MAX;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (board[i][j] == 4 && dis[0][i][j] > 0 && dis[1][i][j] > 0) {
				int result = dis[0][i][j] + dis[1][i][j];
				mini = min(result, mini);
			}
		}
	}
	cout << mini-2;

	return 0;
}