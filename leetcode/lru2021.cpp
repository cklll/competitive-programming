// https://leetcode.com/problems/lru-cache/

#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache
{
public:
  int capacity;
  unordered_map<int, list<pair<int, int> >::iterator> keyNodeMap;
  list<pair<int, int> > l;

  LRUCache(int capacity)
  {
    this->capacity = capacity;
  }

  int get(int key)
  {
    if (keyNodeMap.find(key) == keyNodeMap.end()) {
      return -1;
    }

    auto it = keyNodeMap[key];
    int value = it->second;
    l.push_front({key, value});
    l.erase(it);

    keyNodeMap[key] = l.begin();
    return value;
  }

  void put(int key, int value)
  {
    if (keyNodeMap.find(key) == keyNodeMap.end()) {
      if (l.size() == capacity) {
        pair<int, int> item = l.back();
        l.pop_back();
        keyNodeMap.erase(item.first);
      }
    } else {
      l.erase(keyNodeMap[key]);
    }
    l.push_front({key, value});
    keyNodeMap[key] = l.begin();
  }
};

int main()
{
  LRUCache *obj = new LRUCache(2);
  obj->put(1,1);
  obj->put(2,2);
  cout << obj->get(1) << endl;
  obj->put(3,3);
  cout << obj->get(2) << endl;
  obj->put(4,4);
  cout << obj->get(1) << endl;
  cout << obj->get(3) << endl;
  cout << obj->get(4) << endl;

// [[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]

  // obj->put(7,28);
  // obj->put(7,1);
  // obj->put(8,15);
  // cout << obj->get(6) << endl;
  // obj->put(10,27);
  // cout << obj->get(7) << endl;
  // obj->put(8,10);
  // cout << obj->get(8) << endl;
  // obj->put(6,29);
  // obj->put(1,9);
  // cout << obj->get(6) << endl;
  // obj->put(10,7);
  // obj->get(1);
  // obj->get(2);
  // obj->get(13);
  // obj->put(8,30);
  // obj->put(1,5);
  // obj->get(1);
  // obj->put(13,2);
  // obj->get(12);


  return 0;
}
