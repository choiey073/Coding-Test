#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);	// 입력의 양이 많을 때는 꼭 이 구문 쓰기!
	//freopen("input.txt", "rt", stdin);

	int n, input[10];
	cin >> n;

	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < 10; j++) {
			cin >> input[j];
			if (input[j] % 2 == 1) {
				sum += input[j];
			}
		}
		cout << "#" << i + 1 << " " << sum<<endl;
	}
	
	return 0;
}