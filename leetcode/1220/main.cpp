#include <iostream>
using namespace std;

int main() {
  for (int n = 3; n < 145; n++) {
  if (n == 1) {
            return 5;
        }
        if (n == 2) {
            return 10;
        }

        unsigned long increments[] = { 3, 2, 2, 1, 2 };

        unsigned long result = 0;

        unsigned long modNumber = 1000000007;

        for (int i = 3; i <= n; i++) {
            unsigned long nextIncrements[5];
            nextIncrements[0] = (increments[1] + increments[2] + increments[4])  % modNumber;
            nextIncrements[1] = (increments[0] + increments[2])  % modNumber;
            nextIncrements[2] = (increments[1] + increments[3])  % modNumber;
            nextIncrements[3] = (increments[2])  % modNumber;
            nextIncrements[4] = (increments[2] + increments[3])  % modNumber;

            increments[0] = nextIncrements[0];
            increments[1] = nextIncrements[1];
            increments[2] = nextIncrements[2];
            increments[3] = nextIncrements[3];
            increments[4] = nextIncrements[4];
        }

        result = (increments[0] + increments[1] + increments[2] + increments[3] + increments[4])   % modNumber;
        cout << result << endl;
        // return result;
  }
  return 0;
}

// a
// e
// i
// o
// u
// ae
// ea
// ei
// ia
// ie
// io
// iu
// oi
// ou
// ua

// next ending with a
// = e + i + u

// next ending with e
// = a + i

// next ending with i
// = e + o

// next ending with o
// = i

// next ending with u
// = i + o

// n = 2
// a = 3, e = 2, i = 2, o = 1, u = 2
// 10

// n = 3
// a = 6, e = 5, i = 3, o = 2, u = 3

// n = 4
// a = 11, e = 9, i = 7, o = 3, u = 5

// n = 5
// a = 21, e = 18, i = 12, o = 7, u = 10


// a + 2e + 4i + 2o + u


// a=1
// e=2
// i=4
// o=2
// u=1
