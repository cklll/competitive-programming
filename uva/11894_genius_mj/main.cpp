#include <iostream>
#include <string>
#include <set>
#include <algorithm>

class Point
{
public:
    Point(int x1, int y1)
    {
        x = x1;
        y = y1;
        to_sort = std::to_string(x) + " " + std::to_string(y);
    }

    bool operator<(const Point &rhs) const
    {
        return to_sort < rhs.to_sort;
    }

    int x, y;

private:
    std::string to_sort;
};

int main()
{
    int t, n;
    std::cin >> t;

    for (int i = 0; i < t; i++)
    {
        std::cin >> n;
        std::set<Point> setM;
        std::set<Point> setF;

        int mostLeftM, mostBottomM;
        int mostLeftF = 100000, mostBottomF = 100000;

        for (int j = 0; j < n; j++)
        {
            int x, y;
            std::cin >> x >> y;
            Point point(x, y);
            setM.insert(point);
        }

        for (int j = 0; j < n; j++)
        {
            int x, y;
            std::cin >> x >> y;
            Point point(x, y);
            setF.insert(point);
            mostLeftF = std::min(mostLeftF, x);
            mostBottomF = std::min(mostBottomF, y);
        }

        // translate setF
        std::set<Point> tmpSetF;
        for (std::set<Point>::iterator iter = setF.begin(); iter != setF.end(); iter++)
        {
            Point rotatedPoint(iter->x - mostLeftF, iter->y - mostBottomF);
            tmpSetF.insert(rotatedPoint);
        }
        setF = tmpSetF;

        for (int i = 0; i < 4; i++)
        {
            mostLeftM = 100000, mostBottomM = 100000;

            // rotate first
            std::set<Point> tmpSetM;
            for (std::set<Point>::iterator iter = setM.begin(); iter != setM.end(); iter++)
            {
                Point rotatedPoint(iter->y, -(iter->x));
                tmpSetM.insert(rotatedPoint);

                mostLeftM = std::min(mostLeftM, rotatedPoint.x);
                mostBottomM = std::min(mostBottomM, rotatedPoint.y);
            }
            setM = tmpSetM;

            bool found = true;
            for (std::set<Point>::iterator iter = setM.begin(); iter != setM.end(); iter++)
            {
                Point pointToFind(iter->x - mostLeftM, iter->y - mostBottomM);

                if (setF.find(pointToFind) == setF.end())
                {
                    found = false;
                }
            }

            if (found)
            {
                std::cout << "MATCHED" << std::endl;
                break;
            }
            else if (i == 3)
            {
                std::cout << "NOT MATCHED" << std::endl;
            }
        }
    }

    return 0;
}
