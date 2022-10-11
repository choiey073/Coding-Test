#include <bits/stdc++.h>
using namespace std;

int n, d, k;	// 학생수, 총 재료의 개수, 선택 가능 재료의 수
int result = INT_MIN;

void DFS(int L, int s, int bit, vector<int>& st, vector<int>& pow) {	// vector를 값이 아니라 주소로 받아야 더 가벼움.
	// level, 들어가는 재료 번호, 재료의 현 가중치

	if (L == k) {	// k개로 구성 된 음식이 만들어졌을 때,
		int cnt = 0;
		for (int i = 1; i <= n; i++) {	// 학생 수만큼 반복
			if ((bit & st[i]) == st[i]) {	// bit 결과와 학생들의 가중치를 비트 연산. A & B = B 이면 B는 A에 포함된다(B는 A의 부분집합이다)
				cnt++;
			}
		}
		result = max(cnt, result);		// 최대 결과 저장
	}
	else {	// 아직 k Level에 다다르지 않았다면
		for (int i = s; i <= d; i++) {
			DFS(L + 1, i + 1, bit + pow[i], st, pow);
		}
	}
}

int main(){

	ios_base::sync_with_stdio(false);	// 입력의 양이 많을 때는 꼭 이 구문 쓰기!
	freopen("input.txt", "rt", stdin);

	cin >> n >> d >> k;

	vector<int> st(n + 1), pow(n + 1);	// index를 0이 아닌 1부터 사용
	pow[1] = 1;
	for (int i = 2; i <= d; i++) pow[i] = pow[i - 1] * 2;	// 재료의 가중치 입력

	for (int i = 1; i <= n; i++) {	//학생수 만큼 반복
		int m, num;	// 원하는 재료의 개수, 재료의 번호
		cin >> m;
		for (int j = 1; j <= m; j++) {
			cin >> num;
			st[i] += pow[num];
		}
	}

	DFS(0, 1, 0, st, pow);	// L, s, bit, st, pow

	cout << result;

	return 0;
}