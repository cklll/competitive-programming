// https://codeforces.com/contest/1237/problem/C1

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;

// keep a neighbor queue for all x, y, z

class Point {
  public:
    int x, y, z, number;

    Point() {}
    Point(int _x, int _y, int _z, int _number) {
      x = _x;
      y = _y;
      z = _z;
      number = _number;
    }

    string stringXYZ() const {
      return to_string(x) + "," + to_string(y) + "," + to_string(z);
    }
    string stringYXZ() {
      return to_string(y) + "," + to_string(x) + "," + to_string(z);
    }
    string stringZXY() {
      return to_string(z) + "," + to_string(x) + "," + to_string(y);
    }

    bool operator<(const Point &rhs) const
    {
        return stringXYZ() < rhs.stringXYZ();
    }
};

int main() {
  int n;
  map<string, Point> neighboursByX;
  map<string, Point> neighboursByY;
  map<string, Point> neighboursByZ;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    x = x + 100000000; // no need to deal with negative number
    y = y + 100000000;
    z = z + 100000000;
    int number = i + 1;
    Point point(x, y, z, number);

    neighboursByX[point.stringXYZ()] = point;
    neighboursByY[point.stringYXZ()] = point;
    neighboursByZ[point.stringZXY()] = point;
  }

  while (neighboursByX.size() > 0) {
    Point pointA = neighboursByX.begin()->second;

    set<Point> neighbours;

    auto pointAXIter = neighboursByX.find(pointA.stringXYZ());

    // +x neighbour
    Point neighbour1 = (++pointAXIter)->second;
    neighbours.insert(neighbour1);

    auto pointAYIter = neighboursByY.find(pointA.stringYXZ());
    // -y neighbour
    if (pointAYIter != neighboursByY.begin()) {
      Point neighbour2 = (--pointAYIter)->second;

      if (neighbours.find(neighbour2) == neighbours.end()) {
        neighbours.insert(neighbour2);
      }
      pointAYIter++;
    }
    // +y neighbour
    if (++pointAYIter != neighboursByY.end()) {
      Point neighbour2 = pointAYIter->second;

      if (neighbours.find(neighbour2) == neighbours.end()) {
        neighbours.insert(neighbour2);
      }
    }

    auto pointAZIter = neighboursByZ.find(pointA.stringZXY());
    // -z neighbour
    if (pointAZIter != neighboursByZ.begin()) {
      Point neighbour2 = (--pointAZIter)->second;
      if (neighbours.find(neighbour2) == neighbours.end()) {
        neighbours.insert(neighbour2);
      }
      pointAZIter++;
    }
    // +z neighbour
    if (++pointAZIter != neighboursByZ.end()) {
      Point neighbour2 = pointAZIter->second;
      if (neighbours.find(neighbour2) == neighbours.end()) {
        neighbours.insert(neighbour2);
      }
    }

    for (auto it1 = neighbours.begin(); it1 != neighbours.end(); it1++) {
      // we try to elimate the i-th neighbour
      Point pointB = *it1;

      bool isLyingInBound = false;
      for (auto it2 = neighbours.begin(); it2 != neighbours.end(); it2++) {
        if (it1 == it2) {
          continue;
        }
        Point pointC = *it2;
        if (pointC.x >= min(pointA.x, pointB.x) && max(pointA.x, pointB.x) >= pointC.x &&
            pointC.y >= min(pointA.y, pointB.y) && max(pointA.y, pointB.y) >= pointC.y &&
            pointC.z >= min(pointA.z, pointB.z) && max(pointA.z, pointB.z) >= pointC.z) {
          isLyingInBound = true;
          break;
        }
      }

      if (!isLyingInBound || neighbours.size() == 1) {
        cout << pointA.number << " " << pointB.number << endl;

        neighboursByX.erase(pointA.stringXYZ());
        neighboursByY.erase(pointA.stringYXZ());
        neighboursByZ.erase(pointA.stringZXY());

        neighboursByX.erase(pointB.stringXYZ());
        neighboursByY.erase(pointB.stringYXZ());
        neighboursByZ.erase(pointB.stringZXY());
        break;
      }
    }
  }

  return 0;
}
