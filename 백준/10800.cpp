#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//백준 컬러볼
// 시간초과ㅠㅠ

struct Ball {
	int num, color, weight;

	Ball(int a, int b, int c) {
		num = a;
		color = b;
		weight = c;
	}
	/*
	bool operator < (const Ball& b)const {	// weight를 기준으로 오름차순 정렬
		return weight < b.weight;
	}
	*/
};
bool comp(const Ball& a, const Ball& b) { return a.weight < b.weight; }

int main() {
	ios_base::sync_with_stdio(false);	// 입력의 양이 많을 때는 꼭 이 구문 쓰기!
	cin.tie(NULL);	// 입력을 빨리하기 위함.
	freopen("input.txt", "rt", stdin);

	int n;
	int sum = 0;
	cin >> n;	// 공의 개수
	vector<Ball> ball;	// Ball 자료형 구조체
	int color[200001] = {0,};	// 공색깔별로 누적 크기
	vector<int> result(n);		// 결과

	for (int i = 0; i < n; i++) {
		int c, w;
		cin >> c >> w;
		ball.push_back(Ball(i, c, w));
	}
	sort(ball.begin(), ball.end(), comp);

	int j = 0;
	for (int i = 1; i < n; i++) {
		if (ball[i].weight > ball[j].weight) {
			sum += ball[j].weight;
			color[ball[j].color] += ball[j].weight;
			j++;
		}
		
		result[ball[i].num] = sum - color[ball[i].color];
	}

	for (int i = 0; i < n; i++) {
		cout << result[i] << endl;
	}

	return 0;
}