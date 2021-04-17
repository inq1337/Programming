#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

const auto PI = 3.141592653589793;

const double PRECISION = 1e+10;

enum coord_sys {
    Cartesian,
    Polar
};

class Point {
private:
    double x, y;

public:
    Point(double a1 = 0, double a2 = 0, coord_sys coord_system = Cartesian) {
        if (coord_system == Cartesian) {
            x = a1;
            y = a2;
            return;
        }
        else {
            x = cos(a2) * a1;
            y = sin(a2) * a1;
        }
    }

    bool operator==(const Point &p) {
        return((trunc(x * PRECISION) / PRECISION) == (trunc(p.x * PRECISION) / PRECISION) and
               (trunc(y * PRECISION) / PRECISION) == (trunc(p.y * PRECISION) / PRECISION));
    }

    bool operator!=(const Point &p) {
        return((trunc(x * PRECISION) / PRECISION) != (trunc(p.x * PRECISION) / PRECISION) and
               (trunc(y * PRECISION) / PRECISION) != (trunc(p.y * PRECISION) / PRECISION));
    }

    friend std::ostream& operator<<(std::ostream& out, const Point& p);
    friend std::istream& operator>>(std::istream& in, Point& p);

    double get_x() const {
        return x;
    }

    double get_y() const {
        return y;
    }

    double get_r() {
        return sqrt(x * x + y * y);
    }

    double get_phi() {
        return atan(y / x) + (x < 0 ? PI : 0);
    }

    void set_x(double x) {
        this->x = x;
    }

    void set_y(double y) {
        this->y = y;
    }

    void set_r(double r) {
        double phi = get_phi();
        this->x = cos(phi) * r;
        this->y = sin(phi) * r;
    }

    void set_phi(double phi) {
        double r = get_r();
        this->x = cos(phi) * r;
        this->y = sin(phi) * r;
    }
};

std::ostream& operator<<(std::ostream& out, const Point& p) {
    return out << '(' << p.get_x() << ',' << p.get_y() << ')';
}

std::istream& operator>>(std::istream& in, Point& p) {
    double sym;
    in.ignore(1);
    in >> sym;
    p.set_x(sym);
    in.ignore(1);
    in >> sym;
    p.set_y(sym);
    in.ignore(1);
    return in;
}

int main() {
    std::vector<Point> original;
    std::ifstream fin("data.txt"); //нужно убедиться, что файл в нужной директории
    if (!fin.is_open()) {
        std::cout << "Can't open file" << std::endl;
        return 1;
    } else {
        while (!fin.eof()) {
            Point p;
            fin >> p;
            fin.ignore(2); // Точки разделены двумя символами ", "
            original.push_back(p);
        }
        fin.close();
    }

    std::vector<Point> simulacrum(original);
    for (auto& p : simulacrum) {
        std::cout << p;
        p.set_x(p.get_x() + 10);
        p.set_phi(p.get_phi() + 180*PI/180);
        p.set_y(-p.get_y());
        p.set_x(-p.get_x() - 10);
        std::cout << p << std::endl;
    }

    if (std::equal(original.begin(), original.end(), simulacrum.begin()))
        std::cout << "\nIt works!\n";
    else
        std::cout << "\nIt not works!\n";
}
