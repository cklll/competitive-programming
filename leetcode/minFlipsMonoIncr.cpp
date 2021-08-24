// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/614/week-2-august-8th-august-14th/3876/
#include <string>
#include <iostream>
using namespace std;

int minFlipsMonoIncr(string s) {
    // we want to find a index I
    // flip all the character before I to 0
    // flip all the character after or equal I to 1
    int zeroCounter[100000]; // store how many 1s before or at oneCounter[i]

    zeroCounter[0] = s[0] == '0';

    for (int i = 1; i < s.size(); i++) {
      if (s[i] == '0') {
        zeroCounter[i] = zeroCounter[i-1] + 1;
      } else {
        zeroCounter[i] = zeroCounter[i-1];
      }
    }

    int totalZero = zeroCounter[s.size() - 1];
    int totalOne = s.size() - totalZero;
    // base case: change everything to 1
    int result = totalZero;
    int tmpResult;


    for (int i = 0; i < s.size(); i++) {
      // we try to change everything before or at i to 0
      // and after i to 1
      tmpResult = ((i + 1) - zeroCounter[i]) + (totalZero - zeroCounter[i]);
      if (tmpResult < result) {
        result = tmpResult;
      }
    }
    return result;
}

int main() {
  cout << minFlipsMonoIncr("11011") << endl;;                      /* 1 */
  cout << minFlipsMonoIncr("0") << endl;;                      /* 0 */
  cout << minFlipsMonoIncr("1") << endl;;                      /* 0 */
  cout << minFlipsMonoIncr("00") << endl;;                     /* 0 */
  cout << minFlipsMonoIncr("01") << endl;;                     /* 0 */
  cout << minFlipsMonoIncr("10") << endl;;                     /* 1 */
  cout << minFlipsMonoIncr("000") << endl;                     /* 0 */
  cout << minFlipsMonoIncr("001") << endl;                     /* 0 */
  cout << minFlipsMonoIncr("010") << endl;                     /* 1 */
  cout << minFlipsMonoIncr("100") << endl;                     /* 1 */
  cout << minFlipsMonoIncr("011") << endl;                     /* 0 */
  cout << minFlipsMonoIncr("101") << endl;                     /* 1 */
  cout << minFlipsMonoIncr("111") << endl;                     /* 0 */
  cout << minFlipsMonoIncr("00110") << endl;                   /* 1 */
  cout << minFlipsMonoIncr("010110") << endl;                  /* 2 */
  cout << minFlipsMonoIncr("00011000") << endl;                /* 2 */
  cout << minFlipsMonoIncr("10011111110010111011") << endl;    /* 5 */
  return 0;
}
