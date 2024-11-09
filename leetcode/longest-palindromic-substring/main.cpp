// https://leetcode.com/problems/longest-palindromic-substring/description/

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
    string longestPalindrome(string s) {
      int currentLongestLength = 1;
      string currentResult = string() + s[0];

      // test odd number length
      for (int i = 0; i < s.size(); i++) {
        // ith char as the centre
        int left = i-1;
        int right = i+1;

        while (left >= 0 && right < s.size()) {
          if (s[left] == s[right]) {
            if (right - left + 1 > currentLongestLength) {
              currentLongestLength = right - left + 1;
              currentResult = s.substr(left, currentLongestLength);
            }
            left--; right++;
          } else {
            break;
          }
        }
      }

      // test even number length
      for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] != s[i+1]) {
          continue;
        }

        if (currentLongestLength < 2) {
          currentLongestLength = 2;
          currentResult = s.substr(i, 2);
        }

        int left = i-1;
        int right = i+2;

        while (left >= 0 && right < s.size()) {
          if (s[left] == s[right]) {
            if (right - left + 1 > currentLongestLength) {
              currentLongestLength = right - left + 1;
              currentResult = s.substr(left, currentLongestLength);
            }
            left--; right++;
          } else {
            break;
          }
        }
      }

      return currentResult;
    }
};

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

// Example 2:

// Input: s = "cbbd"
// Output: "bb"


int main() {
  string s1 = "babad";
  string s2 = "cbbd";

  Solution sol;

  cout << sol.longestPalindrome(s1) << endl;
  cout << sol.longestPalindrome(s2) << endl;

  return 0;
}
