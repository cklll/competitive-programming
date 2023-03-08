// https://leetcode.com/problems/find-median-from-data-stream/
// use a priority queue (min-heap) and vector (max-heap)
// min-heap stores the larger half of the numbers
// max-heap stores the smaller half of the numbers
// if total number is odd, stores the extra number in the min-heap

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

template<typename Q>
void print_queue(Q q) {
  // NB: q is passed by value because there is no way to traverse
  // priority_queue's content without erasing the queue.
  while (!q.empty()) {
    cout << q.top() << ' ';
    q.pop();
  }
  cout << '\n';
}


class MedianFinder {
public:
  priority_queue<int, vector<int>> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;

  MedianFinder() {
  }

  void addNum(int num) {
    // we want to push a new number to minHeap
    minHeap.push(num);

    if (minHeap.size() == maxHeap.size() + 1) {
      // minHeap has 1 more item than maxHeap
      // make sure the max number in maxHeap is smaller than the min number in minHeap
      if (maxHeap.size() > 0) {
        int numMin = minHeap.top();
        int numMax = maxHeap.top();

        if (numMin < numMax) {
          minHeap.pop();
          maxHeap.pop();
          minHeap.push(numMax);
          maxHeap.push(numMin);
        }
      }
    } else {
      // now minHeap has 2 more item than maxHeap
      // we move 1 item (first item) to maxHeap
      maxHeap.push(minHeap.top());
      minHeap.pop();
    }

    cout << "--------" << endl;

    cout << "maxHeap ";
    print_queue(maxHeap);

    cout << "minHeap ";
    print_queue(minHeap);
  }

  double findMedian() {
    if (minHeap.size() > maxHeap.size()) {
      return minHeap.top();
    }
    return (minHeap.top() + (double) maxHeap.top()) / 2;
  }
};


int main() {
  MedianFinder* obj = new MedianFinder();

  obj->addNum(5);
  cout << obj->findMedian() << endl;

  obj->addNum(4);
  cout << obj->findMedian() << endl;

  obj->addNum(2);
  cout << obj->findMedian() << endl;

  obj->addNum(6);
  cout << obj->findMedian() << endl;

  return 0;
}
