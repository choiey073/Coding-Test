#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);	// 입력의 양이 많을 때는 꼭 이 구문 쓰기!
	freopen("input.txt", "rt", stdin);
	
	int n;	// 강 건너는 사람 수
	cin >> n;

	vector<int> t(n+1); // 각 사람이 강을 건너는데 걸리는 시간 배열
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
	}
	sort(t.begin(), t.end());	// 입력을 시간대로 오름차순 정렬

	int result=0;	// 총 걸리는 시간(결과)
	int i;

	for (i = n; i >= 4; i -= 2) {	//가장 오래 걸리는 순으로 2명씩 세트로 처리(i-=2), 마지막에는 4명 미만이 남는 경우까지만 처리하면 됨

		// 가장 작은 사람(1번) 혼자 왕복하는 경우 vs 가장 작은 2명(1번,2번)이 협동하여 왕복하는 경우
		result += min(t[i] + t[1] + t[i - 1] + t[1], t[2] + t[2] + t[i] + t[1]);
	}
	if (i == 3) {	// 3명 남은경우
		result += t[1] + t[2] + t[3];	//	무조건 3명 다 한번씩 노 저음
	}
	if (i == 2){	// 2명 남은 경우
		result += t[2];	// 더 오래걸리는 사람이 노 저음.
	}
	//1명은 남을 수 없음
	
	cout << result;

	return 0;
}