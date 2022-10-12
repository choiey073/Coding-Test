#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);	// 입력의 양이 많을 때는 꼭 이 구문 쓰기!
	freopen("input.txt", "rt", stdin);
	
	int n;
	char t;

	cin >> n >> t;
	t = toupper(t);	//대문자로 변환

	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		transform(a.begin(), a.end(), a.begin(), ::toupper);
		// 1번째, 2번째 인자 : 복사 대상의 범위
		// 3번째 인자 : 복사 대상의 시작 주소
		// 4번째 인자 : 원소들을 변환할 함수. 앞에 namespace :: 붙여야 정상 작동.

		if (a.find(t) != string::npos) {	// a 문자열에 t가 존재할 때
			string res = "";
			for (int i = 0; i < a.size(); i++) {
				if (a.find(a[i]) == i) {	// 해당 문자열이 처음으로 발견됐을 때
					res += a[i];			// 해당 문자열을 누적 -> Unique한 문자열
				}
			}
			cout << res << endl;
		}
	}

	return 0;
}