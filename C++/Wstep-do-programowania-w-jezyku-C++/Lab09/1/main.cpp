#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Figure {
public:
    virtual ~Figure() {}
    virtual void print() const = 0;
    virtual double getArea() const = 0;
};

class Circle : public Figure {
public:
    Circle(double x = 0, double y = 0, double radius = 0)
        : centerX(x), centerY(y), radius(radius) {
        if (radius < 0) {
            radius = 0;
        }
    }

    void print() const {
        cout << "Circle centre = (" << centerX << "," << centerY << ") radius = " << radius << endl;
    }

    double getArea() const {
        return M_PI * radius * radius;
    }

protected:
    double centerX, centerY;
    double radius;
};

class Rectangle : public Figure {
public:
    Rectangle(double x = 0, double y = 0, double width = 0, double height = 0)
        : x(x), y(y) {
        this->width = (width > 0) ? width : 0;
        this->height = std::max(0.0, height);
    }

    void print() const {
        cout << "Rectangle position = (" << x << "," << y << ") width = " << width << " height = " << height << endl;
    }

    double getArea() const {
        return width * height;
    }

protected:
    double x, y;
    double width, height;
};

int main() {

    Circle c(1, 1, 3);
    Rectangle r(0, 1, 5, 6);

    // Polimorfizm: wskaŸnik do klasy bazowej
    Figure* fig;

    fig = &c;
    fig->print(); // Wywo³uje przys³oniêt¹ metodê
    cout << "Area = " << fig->getArea() << endl;

    fig = &r;
    fig->print(); // Wywo³uje przys³oniêt¹ metodê
    cout << "Area = " << fig->getArea() << endl;

    return 0;
}
