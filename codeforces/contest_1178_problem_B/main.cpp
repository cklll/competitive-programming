// https://codeforces.com/contest/1178/problem/B

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string input;
  cin >> input;

  string tmp; // convert vv to w
  for (int i = 0; i < input.size() - 1; i++) {
    if (input[i] == 'v' && input[i+1] == 'v') {
      tmp += 'w';
    } else if (input[i] == 'o') {
      tmp += 'o';
    }
  }
  input = tmp;

  while (input.size() > 0 && input[0] != 'w') {
    input.erase(0, 1);
  }
  while (input.size() > 0 && input[input.size() - 1] != 'w') {
    input.erase(input.size() - 1, 1);
  }

  int currentWCount = 0;
  int currentOCount = 0;

  vector<int> groupX, groupY;
  for (int i = 0; i < input.size(); i++) {
    if (input[i] == 'w') {
      currentWCount++;
    } else if (input[i] == 'o') {
      currentOCount++;
    }

    // char change from o to w
    // we have a new group
    if (i > 0 && input[i] == 'w' && input[i-1] == 'o') {
      groupX.push_back(currentWCount - 1); // don't count the trailing w
      groupY.push_back(currentOCount);
      currentOCount = 0;
    }
  }

  unsigned long long int result = 0; // test case 10: 5194808902313398
  for (int i = 0; i < groupX.size(); i++) {
    result += ((unsigned long long int) groupX[i] * groupY[i] * (currentWCount - groupX[i]));
  }
  cout << result << endl;
  return 0;
}



// vvovooovovvovoovoovvvvovovvvov
// wooooowooooowwwooww

// wooooow = 1*5*1
// wooooowooooow = 1*5*(1+1) + 2*5*1
// wooooowoooooww = 1*5*(1+1+1) + 2*5*2
// wooooowooooowww = 1*5*4 + 2*5*3
// wooooowooooowwwoow = 1*5*5 + 2*5*4 + 3*2*1
// wooooowooooowwwooww = 1*5*6 + 2*5*5 + 5*2*2  (x1*y1*z1 + x2*y2*z2 + ....) where z values are actually (number of W) - x
