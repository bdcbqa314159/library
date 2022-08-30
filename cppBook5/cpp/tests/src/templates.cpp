#include <cppBook5>
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <array>
#include <set>

using namespace std;

template <unsigned int DIM>
class DoubleVector
{

    double mData[DIM];

public:
    double &operator[](int index)
    {
        assert(index < DIM);
        assert(index > -1);
        return mData[index];
    }
};

void firstTemplate()
{
    DoubleVector<5> v;
    v[1] = 1.;
    // v[7] = 5.; =>Error
}

template <class T>
T getMax(T a, T b)
{
    return a < b ? b : a;
}

void secondTemplate()
{
    cout << "getMax with ints between 1 & 4: " << getMax<int>(1, 4) << endl;
    cout << "getMax with doubles between 19.90 & 5.63: " << getMax<double>(19.9, 5.63) << endl;
}

void testingVectorSTL()
{
    vector<string> destinations;
    destinations.reserve(6);

    destinations.push_back("Paris");
    destinations.push_back("NYC");
    destinations.push_back("Singapore");

    cout << "Length of vector is " << destinations.size() << endl;

    cout << "Entries: " << endl;
    for (auto destination : destinations)
        cout << destination << endl;

    vector<string>::const_iterator c;
    for (c = destinations.begin(); c != destinations.end(); c++)
        cout << *c << endl;

    destinations.insert(destinations.begin(), "Sydney");
    destinations.insert(destinations.begin() + 1, "Moscow");
    destinations.push_back("Frankfurt");

    cout << "Length of vector is " << destinations.size() << endl;
    for (c = destinations.begin(); c != destinations.end(); c++)
        cout << *c << endl;

    destinations.erase(destinations.begin() + 3, destinations.end());

    cout << "Length of vector is " << destinations.size() << endl;
    for (c = destinations.begin(); c != destinations.end(); c++)
        cout << *c << endl;

    sort(destinations.begin(), destinations.end());
    cout << "Length of vector is " << destinations.size() << endl;
    for (c = destinations.begin(); c != destinations.end(); c++)
        cout << *c << endl;
}

class Point2d
{
public:
    int x, y;

    Point2d() : x(0), y(0)
    {
    }

    Point2d(int a, int b) : x(a), y(b)
    {
    }

    bool operator<(const Point2d &other) const
    {
        if (x < other.x)
            return true;
        else if (x > other.x)
            return false;
        else if (y < other.y)
            return true;
        else
            return false;
    }
};

void testingSetSTL()
{
    set<Point2d> points;
    Point2d origin(0, 0);

    points.insert(origin);
    points.insert(Point2d(-2, 1));
    points.insert(Point2d(-2, -5));
    points.insert(Point2d(0, 0));

    cout << "Number of points in set : " << points.size() << endl;

    set<Point2d>::const_iterator it;
    for (it = points.begin(); it != points.end(); it++)
        cout << it->x << " -- " << it->y << endl;
}

int main()
{
    array<int, 4> num_array = {2, 4, 2, 8};

    vector<int> num_vector(num_array.begin(), num_array.end());
    set<int> num_set(num_array.begin(), num_array.end());

    assert(num_set.size() < num_array.size());

    tuple<string, string, int> explorer = make_tuple("The explorer", "Katherine Rundell", 2017);

    cout << "Title is " << get<0>(explorer) << endl;
    cout << "Published:  " << get<2>(explorer) << endl;

    auto h = make_tuple("The hobbit", "JRR Tolkien", 1937);

    return 0;
}