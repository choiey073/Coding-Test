#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	freopen("input.txt", "r", stdin);
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
		long long result = 0;
		vector <int> price;
		stack <int> st;

		for (int i = 0; i < n; i++) {
			int p;
			cin >> p;
			price.push_back(p);
		}
		int max_price = price[n - 1];

		for (int i = n - 2; i >= 0; i--) {
			
			if (price[i] < max_price) {
				result += max_price - price[i];
			}
			else {
				max_price = price[i];
			}
		}
		cout << "#" <<test_case <<" " << result << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}