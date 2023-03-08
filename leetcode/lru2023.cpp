#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
private:
  int capacity;
  unordered_map<int, int> cache;
  list<int> orderList;
  unordered_map<int, list<int>::iterator> keyToNode;

public:
    LRUCache(int capacity) {
      this->capacity = capacity;
    }

    int get(int key) {
      if (this->cache.find(key) != this->cache.end()) {

        list<int>::iterator iterator = keyToNode[key];
        this->orderList.erase(iterator);


        this->orderList.push_front(key);
        list<int>::iterator newIterator = this->orderList.begin();
        keyToNode[key] = newIterator;

        return this->cache[key];
      }

      return -1;
    }

    void put(int key, int value) {
      if (this->cache.find(key) != this->cache.end()) {
        list<int>::iterator oldIterator = this->keyToNode[key];

        this->orderList.erase(oldIterator);
        this->keyToNode.erase(key);
        this->cache.erase(key);
      } else {
        if (this->cache.size() == this->capacity) {
          list<int>::iterator lastIterator = this->orderList.end();
          lastIterator--;

          int valueToExpire = *lastIterator;
          this->orderList.erase(lastIterator);
          this->keyToNode.erase(valueToExpire);
          this->cache.erase(valueToExpire);
        }
      }

      this->cache[key] = value;

      this->orderList.push_front(key);
      list<int>::iterator iterator = this->orderList.begin();
      keyToNode[key] = iterator;
    }
};

int main() {
  auto lRUCache = new LRUCache(2);
  lRUCache->put(1, 1);                 // cache is {1=1}
  lRUCache->put(2, 2);                 // cache is {1=1, 2=2}
  cout << lRUCache->get(1) << endl;    // return 1
  lRUCache->put(3, 3);                 // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
  cout << lRUCache->get(2) << endl;    // returns -1 (not found)
  lRUCache->put(4, 4);                 // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
  cout << lRUCache->get(1) << endl;    // return -1 (not found)
  cout << lRUCache->get(3) << endl;    // return 3
  cout << lRUCache->get(4) << endl;    // return 4
  return 0;
}
