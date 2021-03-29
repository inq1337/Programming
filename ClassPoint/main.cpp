#include <iostream>

#include <cmath>

class Point {
public:
    enum coord_system {
        Cartesian,
        Polar
    };

    double a1, a2;

    Point(double a1 = 0, double a2 = 0, coord_system = Cartesian) {
    }

    bool operator== (const Point p) {
        return((trunc(a1 * 10) / 10) == (trunc(p.a1 * 10) / 10) and
               (trunc(a2 * 10) / 10) == (trunc(p.a2 * 10) / 10));
    }

    bool operator!= (const Point p) {
        return((trunc(a1 * 10) / 10) != (trunc(p.a1 * 10) / 10) and
               (trunc(a2 * 10) / 10) != (trunc(p.a2 * 10) / 10));
    }

    std::ostream& operator<< (std::ostream& out) {
        return out << "(" << a1 << ", " << a2 << ")";
    }

    std::istream& operator>> (std::istream& in) {
        char br1, comma, br2;
        return in >> br1 >> a1 >> comma >> a2 >> br2;
    }
};

int main() {
}
