#include<iostream>
#include<string>
#include<vector>
#include<utility>
using namespace std;

class Solution {
public:
  int calculate(string s) {
    int result;
    return evaluate(s);
  }

  int evaluate(string s) {
    // <current value, operation>
    vector<pair<int, char>> stacks;
    stacks.push_back(make_pair(0, '+'));

    string currentNumberString = "";
    for (int i = 0; i < s.size(); i++) {
      char c = s[i];

      if (c >= '0' && c <= '9') {
        currentNumberString += c;
        continue;
      }

      // any other case, that means we just may have finished parsing a number
      // try to evaluate it
      if (currentNumberString != "") {
        int num = stoi(currentNumberString);
        if (stacks.back().second == '+') {
          stacks.back().first += num;
        } else {
          stacks.back().first -= num;
        }
        currentNumberString = "";
      }

      if (c == '+' || c == '-') {
        stacks.back().second = c;
        continue;
      }

      if (c == '(') {
        stacks.push_back(make_pair(0, '+'));
        continue;
      }

      if (c == ')') {
        pair<int, char> stack = stacks.back();
        stacks.pop_back();

        if (stacks.back().second == '+') {
          stacks.back().first += stack.first;
        } else {
          stacks.back().first -= stack.first;
        }
      }

      if (c == ' ') {
      }
    }


    if (currentNumberString != "") {
      int num = stoi(currentNumberString);
      if (stacks.back().second == '+') {
        stacks.back().first += num;
      } else {
        stacks.back().first -= num;
      }
      currentNumberString = "";
    }

    return stacks.back().first;
  }
};

int main() {
  Solution sol;
  cout << sol.calculate("1 + 1") << endl; // 2
  cout << sol.calculate("1 - 1") << endl; // 0
  cout << sol.calculate("1 - 1+ 1") << endl; // 1
  cout << sol.calculate(" 2-1 + 2 ") << endl; // 3
  cout << sol.calculate("(1+(4+5+2)-3)+(6+8)") << endl; // 23
  return 0;
}
