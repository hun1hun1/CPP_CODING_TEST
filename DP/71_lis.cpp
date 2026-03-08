#include <vector>

using namespace std;

int solution(const vector<int> nums) {
    int size = nums.size();
    vector<int> dp(size, 1);
    for (int i = 1; i < size; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int result = 1;
    for (int i = 1; i < size; ++i) {
        if (result < dp[i]) result = dp[i];
    }

    return result;
}

#include <iostream>

using namespace std;

int main()
{
  cout << solution({1, 4, 2, 3, 1, 5, 7, 3}) << endl; //출력값 : 5
  cout << solution({3, 2, 1}) << endl; //출력값 : 1
  
  return 0;
}
