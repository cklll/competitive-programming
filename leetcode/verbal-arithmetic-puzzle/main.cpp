
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
  bool isSolvable(vector<string>& words, string result) {
    cout << words[0] << endl;

    unordered_map<char, unordered_set<int>> charOptions;

    for (auto &word : words) {
      for (auto &c : word) {
        if (charOptions.find(c) == charOptions.end()) {
          charOptions[c] = {0,1,2,3,4,5,6,7,8,9};
        }
      }

      charOptions[word[0]].erase(0); // cannot have leading zero
    }

    vector<char> letters;
    for (auto item : charOptions) {
      letters.push_back(item.first);
    }

    // brute force
    

    return false;
  }

  bool test(vector<string>& words, string result, unordered_map<char, int> charMap) {
    int current = 0;
    int mappedResult = convertWordToNumber(result, charMap);

    for (auto &word : words) {
      current += convertWordToNumber(word, charMap);
    }

    return current == mappedResult;
  }

  int convertWordToNumber(string word, unordered_map<char, int> charMap) {
    string numString = "";
    for (auto &c : word) {
      numString += to_string(charMap[c]);
    }
    return stoi(numString);
  }
};




int main() {



  Solution sol;

  vector<string> words = {"SEND","MORE"};
  string result = "MONEY";
  cout << sol.isSolvable(words, result) << endl;
  return 0;
}

// Example 1:

// Input: words = ["SEND","MORE"], result = "MONEY"
// Output: true
// Explanation: Map 'S'-> 9, 'E'->5, 'N'->6, 'D'->7, 'M'->1, 'O'->0, 'R'->8, 'Y'->'2'
// Such that: "SEND" + "MORE" = "MONEY" ,  9567 + 1085 = 10652

// Example 2:

// Input: words = ["SIX","SEVEN","SEVEN"], result = "TWENTY"
// Output: true
// Explanation: Map 'S'-> 6, 'I'->5, 'X'->0, 'E'->8, 'V'->7, 'N'->2, 'T'->1, 'W'->'3', 'Y'->4
// Such that: "SIX" + "SEVEN" + "SEVEN" = "TWENTY" ,  650 + 68782 + 68782 = 138214

// Example 3:

// Input: words = ["LEET","CODE"], result = "POINT"
// Output: false
// Explanation: There is no possible mapping to satisfy the equation, so we return false.
// Note that two different characters cannot map to the same digit.
