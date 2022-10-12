#include <bits/stdc++.h>
using namespace std;

// 해당 문제에서 check하는 방법 등을 익숙하게 하기.

int pan[9][9];	// 처음 입력받는 판
int p[2][81];	// 0인 칸의 위치를 입력받는 배열
int h[9][9], y[9][9], g[9][9];	// 행,열,group check
int cnt = 0;	// 0의 갯수 check

int find(int x, int y) {	// 그룹 번호 check
	return (x / 3) * 3 + y / 3;
}
void DFS(int L) {
	if (L == cnt) {	// L이 0의 총 갯수가 되는 순간, 스도쿠 판 출력 후 프로그램 종려
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << pan[i][j] << " ";
			}
			cout << endl;
		}
		exit(0);	// 재귀 자체를 멈추기 위함(프로그램 종료)
	}
	int xx = p[0][L];		// L번째 0의 행번호
	int yy = p[1][L];		// L번째 0의 열번호
	int gg = find(xx, yy);	// L번째 0의 그룹번호

	for (int i = 1; i <= 9; i++) {
		if (h[xx][i] == 0 && y[yy][i] == 0 && g[gg][i] == 0) {	// i가 행, 열, group에 아직 사용되지 않았다면,
			h[xx][i] = y[yy][i] = g[gg][i] = 1;	// i를 행, 열, 그룹에 사용한 것으로 표시
			pan[xx][yy] = i;	// i를 사용한다.
			DFS(L + 1);
			pan[xx][yy] = 0;	// 해당 숫자가 들어갈 위치가 아니었다면 뒤로 돌아가서 다시 빈칸으로 바꿔줌
			h[xx][i] = y[yy][i] = g[gg][i] = 0;	// 사용하지 않은 것으로 표시
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);	// 입력의 양이 많을 때는 꼭 이 구문 쓰기!
	freopen("input.txt", "rt", stdin);

	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> pan[i][j];
			if (pan[i][j] == 0) {	// 해당 칸이 0(빈공간)이라면
				p[0][cnt] = i;	// 0의 x좌표
				p[1][cnt] = j;	// 0의 y좌표
				cnt++;	// 0의 개수
			}
			else {	// 해당 숫자가 쓰인 행, 열, group 체크
				h[i][pan[i][j]] = 1;	// i행에 pan[i][j]라는 수가 사용되었다.
				y[j][pan[i][j]] = 1;	// j열에 pan[i][j]라는 수가 사용되었다.
				g[find(i, j)][pan[i][j]] = 1;	// find(i,j)번째 그룹에 pan[i][j]라는 수가 사용되었다.
			}
		}
	}
	DFS(0);

	return 0;
}