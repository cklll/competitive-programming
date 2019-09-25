#include <iostream>
#include <string>
#include <set>

class Point
{
public:
    Point(int x1, int y1)
    {
        x = x1;
        y = y1;
        to_sort = std::to_string(x) + " " + std::to_string(y);
    }

    void rotate()
    {
        int tmpX = x;
        x = y;
        y = -tmpX;
        to_sort = std::to_string(x) + " " + std::to_string(y); // not necessary in our use case since we don't need to iterate in order
    }

    bool operator<(const Point &rhs) const
    {
        return to_sort < rhs.to_sort;
    }

private:
    int x, y;
    std::string to_sort;
};

// std::set<std::string> translateTo00(std::set<std::string> &originalSet)
// {
//     std::set<std::string> newSet;

//     int mostLeft = 2000, mostBottom = 2000;

//     for (std::set<std::string>::iterator iter = originalSet.begin(); iter != originalSet.end(); iter++)
//     {
//         int x, y;
//         std::string line = *iter;
//         std::istringstream iss(line);

//         iss >> x >> y;

//         if (x < mostLeft)
//         {
//             mostLeft = x;
//         }
//         if (y < mostBottom)
//         {
//             mostBottom = y;
//         }
//     }

//     int translateX = -mostLeft;
//     int translateY = -mostBottom;

//     for (std::set<std::string>::iterator iter = originalSet.begin(); iter != originalSet.end(); iter++)
//     {
//         int x, y;
//         std::string line = *iter;
//         std::istringstream iss(line);

//         iss >> x >> y;

//         int newX = x + translateX;
//         int newY = y + translateY;

//         std::string newKey = std::to_string(newX) + " " + std::to_string(newY);
//         newSet.insert(newKey);
//     }

//     return newSet;
// }

// bool check(std::set<std::string> setM, std::set<std::string> setF)
// {
//     for (std::set<std::string>::iterator iter = setM.begin(); iter != setM.end(); iter++)
//     {
//         std::string keyToFind = *iter;
//         if (setF.find(keyToFind) == setF.end())
//         {
//             return false;
//         }
//     }

//     return true;
// }

int main()
{
    int t, n, x, y;
    std::cin >> t;

    for (int i = 0; i < t; i++)
    {
        std::cin >> n;
        std::set<Point> setM;
        std::set<Point> setF;

        for (int j = 0; j < n; j++)
        {
            std::cin >> x >> y;
            Point point(x, y);
            setM.insert(point);
        }
        for (int j = 0; j < n; j++)
        {
            std::cin >> x >> y;
            Point point(x, y);
            setF.insert(point);
        }

        std::cout << "NOT MATCHED" << std::endl;
    }

    return 0;
}
