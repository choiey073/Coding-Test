#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// 백준 컬러볼
// cin, cout은 scanf, printf보다 2배 이상 느림
// 그래서 백준에서 시간초과 났었음.

int color[200001];	// 공색깔별로 누적 크기
int result[200001];		// 결과
struct Ball {
	int num, color, weight;

	Ball(int a, int b, int c) {
		num = a;
		color = b;
		weight = c;
	}
	
	bool operator < (const Ball& b)const {	// weight를 기준으로 오름차순 정렬
		return weight < b.weight;
	}
};

int main() {
	ios_base::sync_with_stdio(false);	// 입력의 양이 많을 때는 꼭 이 구문 쓰기!
	freopen("input.txt", "rt", stdin);

	int n;
	int sum = 0;
	scanf("%d", &n);	// 공의 개수
	vector<Ball> ball;	// Ball 자료형 구조체

	for (int i = 0; i < n; i++) {
		int c, w;
		scanf("%d %d", &c, &w);
		ball.push_back(Ball(i, c, w));
	}
	sort(ball.begin(), ball.end());
	
	int j = 0;
	//이건 틀림..
	// 뭐가 틀린거지?
	for (int i = 1; i < n; i++) {
		if (ball[i].weight > ball[j].weight) {
			sum += ball[j].weight;
			color[ball[j].color] += ball[j].weight;
			j++;
		}
		result[ball[i].num] = sum - color[ball[i].color];
	}
	
	/*
	// 이렇게 하면 맞았다고 나옴.
	for (int i = 1; i < n; i++) {
		for (; ball[i].weight> ball[j].weight; j++){
			sum += ball[j].weight;
			color[ball[j].color] += ball[j].weight;
		}
		result[ball[i].num] = sum - color[ball[i].color];
	}
	*/
	for (int i = 0; i < n; i++) {
		printf("%d\n", result[i]);
	}

	return 0;
}