// https://codeforces.com/contest/1178/problem/C

#include <iostream>
using namespace std;

int main() {
  int w, h;
  cin >> w >> h;

  int result = 1;
  for (int i = 0; i < w + h; i++) {
    result *= 2;
    result %= 998244353;
  }
  cout << result << endl;;
  return 0;
}
