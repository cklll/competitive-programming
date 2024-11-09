// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/

#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<unordered_set>
#include<map>
#include<algorithm>
#include<unordered_map>
#include<deque>
#include<queue>
#include<utility>
#include<cmath>
using namespace std;

class Solution {
public:
  string minRemoveToMakeValid(string s) {
    int openCount = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        openCount++;
      } else if (s[i] == ')') {
        if (openCount > 0) {
          openCount--;
        } else {
          s[i] = '#';
        }
      }
    }

    for (int i = s.size() - 1; i >= 0; i--) {
      if (openCount == 0) {
        break;
      }
      if (s[i] == '(') {
        s[i] = '#';
        openCount--;
      }
    }

    string result = "";
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '#') {
        continue;
      }
      result += s[i];
    }

    return result;
  }
};

// Example 1:

// Input: s = "lee(t(c)o)de)"
// Output: "lee(t(c)o)de"
// Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

// Example 2:

// Input: s = "a)b(c)d"
// Output: "ab(c)d"

// Example 3:

// Input: s = "))(("
// Output: ""
// Explanation: An empty string is also valid.


int main() {
  string s1 = "lee(t(c)o)de)";
  string s2 = "a)b(c)d";
  string s3 = "))((";

  Solution sol;

  cout << sol.minRemoveToMakeValid(s1) << endl;
  cout << sol.minRemoveToMakeValid(s2) << endl;
  cout << sol.minRemoveToMakeValid(s3) << endl;

  return 0;
}
