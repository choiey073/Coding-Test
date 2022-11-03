#include <vector>
#include <iostream>
using namespace std;

vector<int> selected;
int N;
bool visited[51] = { false, };
int answer = 0;

// 소수인지 확인하는 함수
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)  return false;
    }
    return true;
}

// 조합구하기 : nC3
void DFS(int idx, int cnt, vector<int> nums) {
    if (cnt == 3) {
        int sum = 0;
        for (auto x : selected) {
            sum += x;
        }
        if (isPrime(sum))    answer++;
        return;
    }
    for (int i = idx; i < N; i++) {
        if (visited[i] == true)    continue;

        visited[i] = true;
        selected.push_back(nums[i]);

        DFS(i, cnt + 1, nums);

        visited[i] = false;
        selected.pop_back();
    }
}
int main(void) {
    vector<int> nums = { 1,2,7,6,4 };
    N = nums.size();
    DFS(0, 0, nums);
    cout << answer;
    return 0;
}