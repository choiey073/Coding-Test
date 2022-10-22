#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
//소용돌이 예쁘게 출력하기
int main()
{
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);

	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;

	vector<vector<int>> map(r2 - r1 + 1, vector<int>(c2 - c1 + 1));	//(r2-r1+1)*(c2-c1+1) size의 2차원 벡터 선언

	int curX = 0, curY = 0;	// 현재 위치
	int curN = 1;			// 현재 숫자

	//(0,0)에 1을 넣는 원리
	if (curX >= c1 && curX <= c2 && curY >= r1 && curY <= r2) map[curY - r1][curX - c1] = curN;
	
	// x+1, y-1 방향으로 갈때는 cnt가 홀수
	// x-1, y+1 방향으로 갈땐느 cnt가 짝수
	int cnt = 1;

	while (map[0][0] == 0 || map[0][c2 - c1] == 0 || map[r2 - r1][0] == 0 || map[r2 - r1][c2 - c1] == 0)	// 전부 채워질 때까지 반복.(하나라도 안채워져있으면 반복)
	{
		// cnt가 홀수
		// x+1 -> y-1 방향으로 이동.
		// map 범위 안에 있다면 숫자 추가
		if (cnt % 2 == 1)
		{
			for (int i = 0; i < cnt; i++)	
			{
				curN++;
				curX++;		// x+1 방향
				if (curX >= c1 && curX <= c2 && curY >= r1 && curY <= r2) map[curY - r1][curX - c1] = curN;
			}
			for (int j = 0; j < cnt; j++)	// y-1 방향
			{
				curN++;
				curY--;		// y-1 방향
				if (curX >= c1 && curX <= c2 && curY >= r1 && curY <= r2) map[curY - r1][curX - c1] = curN;
			}
		}
		// cnt가 짝수
		// x-1 -> y+1 방향으로 이동.
		if (cnt % 2 == 0)
		{
			for (int i = 0; i < cnt; i++)
			{
				curN++;
				curX--;		// x-1 방향
				if (curX >= c1 && curX <= c2 && curY >= r1 && curY <= r2) map[curY - r1][curX - c1] = curN;
			}
			for (int j = 0; j < cnt; j++)
			{
				curN++;
				curY++;		// y+1 방향
				if (curX >= c1 && curX <= c2 && curY >= r1 && curY <= r2) map[curY - r1][curX - c1] = curN;
			}
		}
		cnt++;
	}
	
	int n = 0;
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[0].size(); j++)
		{
			if (n < map[i][j]) n = map[i][j];	//	map에서 가장 큰 숫자 찾기
		}
	}

	int len = to_string(n).size();	// 가장 큰 수의 길이

	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[0].size(); j++)
		{
			cout.width(len);	// 가장 큰 수의 길이만큼 너비 설정
			cout.fill(' ');		// 숫자가 들어가지 않는 공간은 빈 문자열 출력
			cout << map[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}