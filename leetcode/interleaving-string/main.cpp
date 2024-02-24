// https://leetcode.com/problems/interleaving-string/description/?envType=study-plan-v2&envId=top-interview-150

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size()) {
      return false;
    }

    bool dp[s1.size()+1][s2.size()+1];

    dp[0][0] = true;

    for (int i = 1; i < s1.size()+1; i++) {
      dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
    }
    for (int i = 1; i < s2.size()+1; i++) {
      dp[0][i] = dp[0][i-1] && s2[i-1] == s3[i-1];
    }

    for (int i = 1; i < s1.size()+1; i++) {
      for (int j = 1; j < s2.size()+1; j++) {
        dp[i][j] = (dp[i][j-1] && s2[j-1] == s3[i+j-1]) || (dp[i-1][j] && s1[i-1] == s3[i+j-1]);
      }
    }

    for (int i = 0; i < s1.size()+1; i++) {
      for (int j = 0; j < s2.size()+1; j++) {
        // cout << dp[i][j] << " ";
      }
      // cout << endl;
    }

    return dp[s1.size()][s2.size()];
  }
};

int main() {
  Solution sol;
  // cout << sol.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
  // cout << sol.isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
  // cout << sol.isInterleave("", "", "") << endl;
  cout << sol.isInterleave("ab", "aa", "abaa") << endl;
  cout << sol.isInterleave("aa", "ab", "abaa") << endl;
  return 0;
}
