#include <vector>
#include <string>

using namespace std;

int solution(string str1, string str2) {
    int length1 = str1.length();
    int length2 = str2.length();
    vector<vector<int>> dp(length2+1, vector<int>(length1+1, 0));
    for (int i = 1; i <= length2; ++i) {
        for (int j = 1; j <= length1; ++j) {
            if (str2[i-1] == str1[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[length2][length1];
}

#include <iostream>

using namespace std;

int main()
{
  cout << solution("ABCBDAB","BDCAB") << endl; //출력값: 4
  cout << solution("AGGTAB", "GXTXAYB") << endl; //출력값 :4
  return 0;
}
