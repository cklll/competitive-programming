// https://leetcode.com/problems/substring-with-concatenation-of-all-words/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
      vector<int> result;

      unordered_map<string, int> wordsDict;
      for (string word : words) {
        wordsDict[word]++;
      }

      int wordLength = words.at(0).length();

      // my implementation of https://leetcode.com/problems/substring-with-concatenation-of-all-words/solutions/13656/an-o-n-solution-with-detailed-explanation/?envType=study-plan-v2&envId=top-interview-150
      // i is the starting position
      for (int i = 0; i < wordLength; i++) {
        int foundWordCount = 0;
        unordered_map<string, int> foundWords;
        for (int j = i; (j + wordLength) <= s.size(); j+= wordLength) {
          string currentWord = s.substr(j, wordLength);

          if (wordsDict.find(currentWord) != wordsDict.end()) {
            foundWords[currentWord]++;
            foundWordCount++;

            // if the currentWord appears too many, remove foundWords until the first one is removed
            int startingPos = j - ((foundWordCount-1) * wordLength);
            while (foundWords[currentWord] > wordsDict[currentWord]) {
              string wordToRemove = s.substr(startingPos, wordLength);
              foundWordCount--;
              foundWords[wordToRemove]--;

              startingPos += wordLength;
            }

            if (foundWordCount == words.size()) {
              result.push_back(startingPos);

              // remove the first one
              foundWordCount--;
              foundWords[s.substr(startingPos, wordLength)]--;
            }
          } else {
            foundWordCount = 0;
            foundWords.clear();
          }
        }
      }

      return result;
    }
};

void printResult(vector<int> indexes) {
  for (int index : indexes) {
    cout << index << " ";
  }
  cout << endl;
}

int main() {
  vector<string> words = {"foo","bar"};
  printResult(Solution().findSubstring("barfoo", words)); // [0]
  printResult(Solution().findSubstring("barfoothefoobarman", words)); // [0,9]

  words = {"word","good","best","word"};
  printResult(Solution().findSubstring("wordgoodgoodgoodbestword", words)); // []

  words = {"bar","foo","the"};
  printResult(Solution().findSubstring("barfoofoobarthefoobarman", words)); // [6,9,12]

  words = {"word","good","best","good"};
  printResult(Solution().findSubstring("wordgoodgoodgoodbestword", words)); // [8]

  words = {"aa","aa"};
  printResult(Solution().findSubstring("aaaaaaaaaaaaaa", words)); // [0,1,2,3,4,5,6,7,8,9,10]

  return 0;
}
