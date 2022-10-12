#include <bits/stdc++.h>
using namespace std;
//백준 컬러볼
// 시간초과ㅠㅠ

struct Ball {
	int num, color;
	int size;

	Ball(int a, int b, int c) {
		num = a;
		color = b;
		size = c;
	}
	bool operator < (const Ball& b)const {	// size를 기준으로 오름차순 정렬
		return size < b.size;
	}
};

int main(){
	ios_base::sync_with_stdio(false);	// 입력의 양이 많을 때는 꼭 이 구문 쓰기!
	cin.tie(NULL);	// 입력을 빨리하기 위함.
	freopen("input.txt", "rt", stdin);

	int n;
	int sum = 0;
	cin >> n;	// 공의 개수
	vector<Ball> ball;	// Ball 자료형 구조체
	unordered_map<int, int> color;	// 공색깔별로 누적 크기
	vector<int> result(n);		// 결과

	for (int i = 0; i < n; i++) {
		int c;
		int s;
		cin >> c >> s;
		ball.push_back(Ball(i, c, s));
	}
	sort(ball.begin(), ball.end());

	int j = 0;
	for (int i = 1; i < n; i++) {
		if (ball[i].size > ball[j].size) {
				sum += ball[j].size;
				color[ball[j].color] += ball[j].size;
				j++;
		}
		else {
			break;
		} 
		result[ball[i].num] = sum - color[ball[i].color];
	}

	for (int i = 0; i < n; i++) {
		cout << result[i] << endl;;
	}
	
	return 0;
}