#include <vector>
#include <string>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    int horizontal_limit = board[0] / 2;
    int vertical_limit = board[1] / 2;
    vector<int> result = {0, 0};

    for (string s : keyinput) {
        if (s == "left") {
            if (result[0] - 1 < -horizontal_limit) continue;
            result[0]--;
        } else if (s == "right") {
            if (result[0] + 1 > horizontal_limit) continue;
            result[0]++;
        } else if (s == "up") {
            if (result[1] + 1 > vertical_limit) continue;
            result[1]++;
        } else if (s == "down") {
            if (result[1] - 1 < -vertical_limit) continue;
            result[1]--;
        }
    }

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
  print(solution({"left", "right", "up", "right", "right"}, {11, 11})); //출력값 : 2 1 
  print(solution({"down", "down", "down", "down", "down"}, {7, 9})); //출력값 : 0 -4  
  
  return 0;
}
