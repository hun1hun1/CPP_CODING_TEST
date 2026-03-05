#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    string x = s;
    int zero_count = 0;
    int loop_count = 0;
    while (x != "1") {
        int zero_length = 0;
        for (int i = 0; i < x.length(); ++i) {
            if (x[i] == '0') zero_length++;
        }
        zero_count += zero_length;
        int one_length = x.length() - zero_length;
        string bi_x = "";
        while (one_length != 1) {
            bi_x += (one_length % 2) + '0';
            one_length /= 2;
        }
        bi_x += '1';
        reverse(bi_x.begin(), bi_x.end());
        x = bi_x;
        loop_count++;
    }

    vector<int> result;
    result.push_back(loop_count);
    result.push_back(zero_count);
    return result;
}

#include <iterator>
#include <iostream>

using namespace std;

void print(vector<int> vec)
{
  copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
  cout << endl;
}

int main()
{
  print(solution("110010101001")); //출력값 : 3 8
  print(solution("01110")); //출력값 : 3 3
  print(solution("1111111")); //출력값 : 4 1
  
  return 0;
}
