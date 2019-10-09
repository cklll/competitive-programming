#include <iostream>
#include <string>
#include <queue>
#include <vector>

class Query
{
public:
  int q;
  int period;
  int nextTime;

  Query(int q, int period) : q(q), period(period)
  {
    nextTime = period;
  }
};

bool operator<(const Query &lhs, const Query &rhs)
{
  if (lhs.nextTime == rhs.nextTime)
  {
    return lhs.q > rhs.q;
  }
  return lhs.nextTime > rhs.nextTime;
}

int main()
{
  int q, period;
  std::string word; // useless
  std::priority_queue<Query, std::vector<Query> > pq;
  while (true)
  {
    std::cin >> word;
    if (word == "#")
    {
      break;
    }
    std::cin >> q >> period;
    Query query(q, period);
    pq.push(query);
  }

  int k;
  std::cin >> k;

  for (int i = 0; i < k; i++)
  {
    Query topQuery = pq.top();
    pq.pop();
    std::cout << topQuery.q << std::endl;
    topQuery.nextTime += topQuery.period;
    pq.push(topQuery);
  }

  return 0;
}
