#include "hexagon.hpp"

using namespace std;

Hexagon::Hexagon() : po{Point(), Point(), Point(), Point()} {}

Hexagon::Hexagon(Point& p1, Point& p2, Point& p3, Point& p4, Point& p5, Point& p6) : 
        po{p1, p2, p3, p4, p5, p6}  {}

Point Hexagon::center() const {
    double x = 0, y = 0;
    for(size_t i = 0; i < 6; ++i){
        x += po[i].x_;
        y += po[i].y_;
    }
    return Point(x / 6.0, y / 6.0);
}

double Hexagon::square() const {
    double x1 = po[0].x_; double y1 = po[0].y_;
    double x2 = po[1].x_; double y2 = po[1].y_;
    double x3 = po[2].x_; double y3 = po[2].y_;
    double x4 = po[3].x_; double y4 = po[3].y_;
    double x5 = po[4].x_; double y5 = po[4].y_;
    double x6 = po[5].x_; double y6 = po[5].y_;

    double S = abs(x1*y2 + x2*y3 + x3*y4 + x4*y5 + x5*y6 + x6*y1 - x2*y1 - x3*y2 - x4*y3 - x5*y4 - x6*y5 - x1*y6) / 2.0;
    return S;
}

Hexagon& Hexagon::operator = (const Hexagon &other){
    if (this == &other) {
        return *this;
    }

    for(size_t i = 0; i < 6; ++i){
        po[i] = other.po[i];
    }

    return *this;
}

Hexagon& Hexagon::operator = (Hexagon &&other){
    if (this == &other) {
        return *this;
    }

    for(size_t i = 0; i < 6; ++i){
        po[i] = move(other.po[i]);
    }

    return *this;
}



bool Hexagon::operator == (const Hexagon& other){
    for(size_t i = 0; i < 6; ++i){
        if(po[i] != other.po[i]){
            return false;
        }
    }
    return true;
}

ostream& operator << (ostream& os, const Hexagon& Hexagon){
    for(size_t i = 0; i < 6; ++i){
        os << Hexagon.po[i] << endl;
    }
    return os;
}

istream& operator >> (istream& is, Hexagon& Hexagon) {
    cout << "Введите координаты шестиугольника через пробел следующим образом: x1 y1 ... x6 y6:" << endl;
    for (size_t i = 0; i < 6; ++i) {
         is >> Hexagon.po[i];
    }
    return is;
}

Hexagon::operator double() const{
    return square();
}