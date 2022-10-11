#include <bits/stdc++.h>
using namespace std;

int arr[]= { 1,2,3, 4, 5 };
int result[2];
int r = sizeof(result) / sizeof(int);

void DFS(int level, int begin) {
	if (level == r) {
		for (auto x : result) {
			cout << x << ' ';
		}
		cout << endl;
	}
	else {
		for (int i = begin; i < 3; i++) {
			result[level] = arr[i];
			DFS(level + 1, i + 1);
		}
	}
}

int main(){

	ios_base::sync_with_stdio(false);	// 입력의 양이 많을 때는 꼭 이 구문 쓰기!
	freopen("input.txt", "rt", stdin);
	
	DFS(0, 0);

	return 0;
}