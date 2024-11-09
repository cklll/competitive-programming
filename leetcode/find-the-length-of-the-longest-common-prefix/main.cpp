// https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/

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

struct Node {
  Node* children[10];

  Node() {
    for (int i = 0; i < 10; i++) {
      children[i] = 0;
    }
  }
};

class Solution {
public:
  int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    Node* head = new Node();

    for (auto arr : arr1) {
      Node* current = head;

      string s = to_string(arr);
      for (auto &c : s) {
        int digit = c - '0';
        if (!current->children[digit]) {
          current->children[digit] = new Node();
        }
        current = current->children[digit];
      }
    }

    int result = 0;

    for (auto arr : arr2) {
      int count = 0;
      Node* current = head;

      string s = to_string(arr);
      for (auto &c : s) {
        int digit = c - '0';
        if (current->children[digit]) {
          count++;
          current = current->children[digit];
        } else {
          break;
        }
      }

      if (count > result) {
        result = count;
      }
    }

    return result;
  }
};

int main() {
// Example 1:

// Input: arr1 = [1,10,100], arr2 = [1000]
// Output: 3
// Explanation: There are 3 pairs (arr1[i], arr2[j]):
// - The longest common prefix of (1, 1000) is 1.
// - The longest common prefix of (10, 1000) is 10.
// - The longest common prefix of (100, 1000) is 100.
// The longest common prefix is 100 with a length of 3.

// Example 2:

// Input: arr1 = [1,2,3], arr2 = [4,4,4]
// Output: 0
// Explanation: There exists no common prefix for any pair (arr1[i], arr2[j]), hence we return 0.
// Note that common prefixes between elements of the same array do not count.

  Solution sol;

  // vector<int> arr1 = {1, 10, 100}; vector<int> arr2 = {1000};
  // vector<int> arr1 = {1,2,3}; vector<int> arr2 = {4,4,4};
  vector<int> arr1 = {8}; vector<int> arr2 = {48};

  cout << sol.longestCommonPrefix(arr1, arr2) << endl;

  return 0;
}
