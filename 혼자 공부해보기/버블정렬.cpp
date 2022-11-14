#include <vector>
#include <iostream>
using namespace std;

// 버블정렬
int main(void) {
    vector<int> nums = { 4, 6, 2, 1, 3, 5 };
    int answer = 0;
    int tmp = 0;
    int size = nums.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i-1; j++) {
            if (nums[j] > nums[j + 1]) {
                tmp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = tmp;
                answer++;

            }
        }
        for (auto n : nums) {
            cout << n << " ";
        }
        cout << endl;

    }
    
    cout << endl;
    cout << answer << endl;
}