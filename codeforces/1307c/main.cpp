#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// hints: the secret message is either length of 1 or 2
// because the length of 3 will be covered in the message with length of 2
int main() {
  string s;
  cin >> s;

  map<string, long long> messageCounters;
  map<char, long long> characterCounter;

  for (int i = 0; i < s.size(); i++) {
    characterCounter[s[i]]++;
    string newCharacter = string(1, s[i]);

    for (auto it = characterCounter.begin(); it != characterCounter.end(); it++) {
      string newMessage = "" + newCharacter + it->first;

      if (it->first == s[i]) {
        messageCounters[newMessage] += it->second - 1;
      } else {
        messageCounters[newMessage] += it->second;
      }
    }
  }

  long long max = 0;
  for (auto it = messageCounters.begin(); it != messageCounters.end(); it++) {
    if (it->second > max) {
      max = it->second;
    }
  }
  for (auto it = characterCounter.begin(); it != characterCounter.end(); it++) {
    if (it->second > max) {
      max = it->second;
    }
  }

  cout << max << endl;
  return 0;
}
