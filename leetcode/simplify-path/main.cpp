#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
      vector<string> dirs;

      string currentString = "";
      for (int i = 0; i < path.size(); i++) {
        if (path[i] == '/') {
          updateDirs(&dirs, currentString);
          currentString = "";
          continue;
        }

        currentString += path[i];
      }

      updateDirs(&dirs, currentString);

      string result = "";
      for (auto dir : dirs) {
        result += "/" + dir;
      }

      if (result == "") {
        result = "/";
      }

      return result;
    }

private:
  void updateDirs(vector<string>* dirs, string currentString) {
    if (currentString == "") {
      return;
    }

    if (currentString == "..") {
      if ((*dirs).size() > 0) {
        (*dirs).erase((*dirs).end() - 1);
      }

      return;
    }
    if (currentString == ".") {
      return;
    }

    (*dirs).push_back(currentString);
  }
};


int main() {
  Solution sol;
  cout << sol.simplifyPath("/home/") << endl;
  cout << sol.simplifyPath("/home/..") << endl;

  cout << sol.simplifyPath("/../") << endl;
  cout << sol.simplifyPath("/../abc/def/../aaa") << endl;
  cout << sol.simplifyPath("/home//foo/") << endl;
  cout << sol.simplifyPath("/home//foo/./") << endl;
  return 0;
}
