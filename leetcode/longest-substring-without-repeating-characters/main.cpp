// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

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

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      if (s == "") {
        return 0;
      }

      int currentStart = 0;
      unordered_map<char, int> charPosMap;
      charPosMap[s[0]] = 0;

      int result = 1;

      for (int i = 1; i < s.size(); i++) {
        if (charPosMap.find(s[i]) != charPosMap.end()) {
          if (charPosMap[s[i]] >= currentStart) {
            int len = i - currentStart;
            if (len > result) {
              result = len;
            }

            currentStart = charPosMap[s[i]] + 1;
          }
        }

        charPosMap[s[i]] = i;
      }

      if (s.size() - currentStart > result) {
        return s.size() - currentStart;
      }

      return result;
    }
};


int main() {
  string s1 = "abcabcbb";
  string s2 = "bbbbb";
  string s3 = "pwwkew";
  string s4 = "au";

  Solution sol;
  cout << sol.lengthOfLongestSubstring(s1) <<endl;
  cout << sol.lengthOfLongestSubstring(s2) <<endl;
  cout << sol.lengthOfLongestSubstring(s3) <<endl;
  cout << sol.lengthOfLongestSubstring(s4) <<endl;

  return 0;
}
