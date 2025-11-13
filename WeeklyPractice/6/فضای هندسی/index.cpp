#include <iostream>
#include <cmath>
#include <vector>
#include <memory>

using namespace std;

namespace GeometryUtils
{
    const double epsilon = 1e-6;
    bool isEqual(double a, double b)
    {
        return fabs(a - b) < epsilon;
    }
}

class Point
{
    const double x, y;
    static int count;

public:
    Point(double x, double y) : x(x), y(y) { ++count; }
    double getX() const { return x; }
    double getY() const { return y; }
    void print() const
    {
        cout << "(" << x << ", " << y << ")";
    }
    static int getCount() { return count; }
};
int Point::count = 0;

class Line
{
    const Point start;
    const Point end;

public:
    Line(const Point &s, const Point &e) : start(s), end(e) {}
    double length() const
    {
        return sqrt(pow(end.getX() - start.getX(), 2) + pow(end.getY() - start.getY(), 2));
    }
    void print() const
    {
        cout << "Line: ";
        start.print();
        cout << " -> ";
        end.print();
        cout << " | Length: " << length() << endl;
    }
};

class Rectangle
{
    const Point p1;
    const Point p2;

public:
    Rectangle(const Point &a, const Point &b) : p1(a), p2(b) {}
    double width() const { return fabs(p2.getX() - p1.getX()); }
    double height() const { return fabs(p2.getY() - p1.getY()); }
    double area() const { return width() * height(); }
    bool isSquare() const
    {
        return GeometryUtils::isEqual(width(), height());
    }
    void print() const
    {
        cout << "Rectangle: ";
        p1.print();
        cout << " - ";
        p2.print();
        cout << " | Width: " << width() << ", Height: " << height()
             << ", Area: " << area()
             << (isSquare() ? " (Square)" : "") << endl;
    }
};

class GeometrySpace
{
    static int nextId;
    static vector<GeometrySpace *> allSpaces;
    int id;
    vector<unique_ptr<Point>> points;
    vector<unique_ptr<Line>> lines;
    vector<unique_ptr<Rectangle>> rectangles;

public:
    GeometrySpace() : id(++nextId)
    {
        allSpaces.push_back(this);
    }
    int getId() const { return id; }

    const Point *createPoint(double x, double y)
    {
        points.push_back(make_unique<Point>(x, y));
        return points.back().get();
    }

    const Line *createLine(const Point *a, const Point *b)
    {
        lines.push_back(make_unique<Line>(*a, *b));
        return lines.back().get();
    }

    const Rectangle *createRectangle(const Point *a, const Point *b)
    {
        rectangles.push_back(make_unique<Rectangle>(*a, *b));
        return rectangles.back().get();
    }

    int getObjectCount() const
    {
        return points.size() + lines.size() + rectangles.size();
    }

    void print() const
    {
        cout << "GeometrySpace ID: " << id << endl;
        cout << "Points: " << points.size() << ", Lines: " << lines.size()
             << ", Rectangles: " << rectangles.size() << endl;
        for (const auto &p : points)
        {
            cout << "  ";
            p->print();
            cout << endl;
        }
        for (const auto &l : lines)
        {
            cout << "  ";
            l->print();
        }
        for (const auto &r : rectangles)
        {
            cout << "  ";
            r->print();
        }
        cout << endl;
    }

    static const GeometrySpace *getMostPopulated()
    {
        if (allSpaces.empty())
            return nullptr;
        const GeometrySpace *richest = allSpaces[0];
        for (const auto *s : allSpaces)
            if (s->getObjectCount() > richest->getObjectCount())
                richest = s;
        return richest;
    }
};

int GeometrySpace::nextId = 0;
vector<GeometrySpace *> GeometrySpace::allSpaces;

int main()
{
    GeometrySpace s1, s2;
    auto p1 = s1.createPoint(0, 0);
    auto p2 = s1.createPoint(3, 4);
    auto l1 = s1.createLine(p1, p2);
    auto r1 = s1.createRectangle(p1, p2);
    auto p3 = s2.createPoint(1, 1);
    auto p4 = s2.createPoint(2, 2);
    s1.print();
    s2.print();
    const GeometrySpace *richest = GeometrySpace::getMostPopulated();
    if (richest)
        cout << "Space with most objects: " << richest->getId() << endl;
    cout << "Total points created: " << Point::getCount() << endl;
    return 0;
}
