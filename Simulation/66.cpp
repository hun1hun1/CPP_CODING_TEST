#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int solution(vector<int> topping) {
    int equal_count = 0;
    unordered_map<int, int> right_side;
    unordered_set<int> left_side;

    for (int top : topping) {
        right_side[top]++;
    }

    for (int i = 0; i < topping.size() - 1; ++i) {
        left_side.insert(topping[i]);
        right_side[topping[i]]--;

        if (right_side[topping[i]] == 0) {
            right_side.erase(topping[i]);
        }

        if (right_side.size() == left_side.size()) equal_count++;
    }

    return equal_count;

    // int size = topping.size();
    // int equal_count = 0;
    // for (int i = 1; i < size; ++i) {
    //     unordered_set<int> left_side;
    //     unordered_set<int> right_side;
    //     for (int j = 0; j < i; ++j) {
    //         left_side.insert(topping[j]);
    //     }
    //     for (int j = i; j < size; ++j) {
    //         right_side.insert(topping[j]);
    //     }

    //     if (left_side.size() == right_side.size()) equal_count++;
    // }

    // return equal_count;
}

#include <iostream>

using namespace std;


int main()
{
  cout << solution({1, 2, 1, 3, 1, 4, 1, 2}) << endl; // 출력값 : 2
  cout << solution({1, 2, 3, 1, 4}) << endl; // 출력값 : 0
  
  return 0;
}
