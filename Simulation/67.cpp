#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int green, int white) {
    int num = green + white;
    double limit = sqrt(num);
    for (int i = 3; i <= limit; ++i) {
        if (num / i == (double)num / i) {
            int horizontal = num / i;
            int vertical = i;
            if (horizontal * 2 + (vertical - 2) * 2 == green && (horizontal - 2) * (vertical - 2) == white) return {horizontal, vertical};
        }
    }
    return {};
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
  print(solution(10, 2)); //출력값 : 4 3
  print(solution(8, 1)); //출력값 : 3 3
  print(solution(24, 24)); //출력값 : 8 6
  
  return 0;
}
