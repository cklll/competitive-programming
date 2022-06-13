// https://codeforces.com/contest/1651/problem/D

#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <tuple>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;


// TLE for some reason
// we probably need to optimse the usage with https://codeforces.com/blog/entry/21853
// https://stackoverflow.com/questions/32685540/why-cant-i-compile-an-unordered-map-with-a-pair-as-key
// struct pair_hash {
//   template <class T1, class T2>
//   std::size_t operator () (const std::pair<T1,T2> &p) const {
//     auto h1 = std::hash<T1>{}(p.first);
//     auto h2 = std::hash<T2>{}(p.second);

//     // Mainly for demonstration purposes, i.e. works but is overly simple
//     // In the real world, use sth. like boost.hash_combine
//     return h1 ^ h2;
//   }
// };
// unordered_map<pair<int, int>, int, pair_hash> occupiedPointsToIndex; // map a coordinate back to index
// unordered_set<pair<int, int>, pair_hash> emptyPoints; // store all the empty points next to an occupied ones
map<pair<int, int>, int> occupiedPointsToIndex; // map a coordinate back to index
set<pair<int, int>> emptyPoints; // store all the empty points next to an occupied ones

int directionX[] = {1, -1, 0, 0};
int directionY[] = {0, 0, 1, -1};

int coordinatesX[200005];
int coordinatesY[200005];
int resultX[200005];
int resultY[200005];

int n;

// STRATEGY
// initially a queue of 4 items with all the closest empty points
// x, y represent current point, sx, sy represent the closest empty point
// initially, they are the same, but (x, y) will be changing to move toward occupied points
// foreach item, check if (x, y) is occupied
//    if (x, y) is occupied
//       sx, sy are their closest empty point
//    Move towards neighbors (4 directions)
//       if unvisited AND occupied neighbors to the queue
//       we don't need to add unoccupied ones, because it will be handled by the initial queue items

void bfs() {
  queue<tuple<int, int, int, int>> bfsQueue;
  set<pair<int, int>> visited;
  for (auto [x, y] : emptyPoints) {

    bfsQueue.push({ x, y, x, y });
    visited.insert({ x, y });
  }

  while (!bfsQueue.empty()) {
    int x, y, emptyX, emptyY;
    tie(x, y, emptyX, emptyY) = bfsQueue.front();
    bfsQueue.pop();

    if (occupiedPointsToIndex.count({ x, y })) {
      int index = occupiedPointsToIndex[{ x, y }];
      resultX[index] = emptyX;
      resultY[index] = emptyY;
    }
    for (int i = 0; i < 4; i++) {
      int nextX = x + directionX[i];
      int nextY = y + directionY[i];
      if (visited.count({ nextX, nextY })) {
        continue;
      }

      if (!occupiedPointsToIndex.count({ nextX, nextY })) {
        if (!emptyPoints.count({ nextX, nextY })) {
          continue;
        }
      }

      visited.insert({ nextX, nextY });
      bfsQueue.push({ nextX, nextY, emptyX, emptyY });
    }
  }
}

int main() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> coordinatesX[i];
    cin >> coordinatesY[i];
    occupiedPointsToIndex[{ coordinatesX[i], coordinatesY[i] }] = i;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      int x = coordinatesX[i] + directionX[j];
      int y = coordinatesY[i] + directionY[j];

      if (occupiedPointsToIndex.count({ x, y })) {
        continue;
      } else {
        emptyPoints.insert({ x, y });
      }
    }
  }

  bfs();

  for (int i = 0; i < n; i++) {
    cout << resultX[i] << " " << resultY[i] << endl;
  }

  return 0;
}
