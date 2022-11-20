#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("input.txt", "r", stdin);
	std::ios::sync_with_stdio(false);

	cin >> T;
	for (test_case = 1; test_case <= T; test_case++)
	{
		int n, s;
		int result;
		cin >> n >> s;
		vector <int> arr(n,0);

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		sort(arr.begin(), arr.end());
		int min = arr[0];
		int max = arr[arr.size() - 1];

		result = max - min;

		if (s > min && s < max) {
			if (s - min < max - s) {
				result += s - min;
			}
			else {
				result += max - s;
			}
		}

		if (s < min) {
			result += min - s;
		}
		else if (s > max) {
			result += s - max;
		}

		// 표준출력(화면)으로 답안을 출력합니다.
		cout << "#" << test_case << " "<<result << endl;
		
	}

	return 0; // 정상종료시 반드시 0을 리턴해야 합니다.
}
