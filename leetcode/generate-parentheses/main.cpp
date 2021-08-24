// https://leetcode.com/problems/generate-parentheses/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void dfs(int n, int usedLeftCount, string current, string fullString, vector<string> &result) {
  // Case 1: current only has 1 character
  if (current.size() == 1) {
    // if it is ")", found a bad combination. stop following
    if (current[0] == ')') {
      return;
    } else {
      /* nothing special */
    }
  } else if (current[current.size() - 1] == ')' && current[current.size() - 2] == '(') {
    // Case 2: if last 2 characters are ()
    //
    // found one of the combination
    if (fullString.size() == n * 2) {
      result.push_back(fullString);
      cout << fullString << endl;
      return;
    }
    // found a local pair, e.g. "(()"
    // we can remove the last 2 characters immediately
    current.pop_back();
    current.pop_back();
  }

  if (usedLeftCount < n) {
    dfs(n, usedLeftCount + 1, current + "(", fullString + "(", result);
  }

  dfs(n, usedLeftCount, current + ")", fullString + ")", result);
}

vector<string> generateParenthesis(int n) {
  vector<string> result;

  dfs(n, 1, "(", "(", result);

  return result;
}

int main() {
  cout << "---- 1 ----" << endl;
  generateParenthesis(1);
  // ()

  cout << "---- 2 ----" << endl;
  generateParenthesis(2);
  // // (()), ()()

  cout << "---- 3 ----" << endl;
  generateParenthesis(3);
  // // ((())), (()()), (())(), ()(()), ()()()

  cout << "---- 4 ----" << endl;
  generateParenthesis(4);

  return 0;
}
