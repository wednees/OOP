#include <iostream>

#include "Vector.hpp"
#include "point.hpp"
#include "figure.hpp"
#include "hexagon.hpp"
#include "rhomb.hpp"
#include "pentagon.hpp"

using namespace std;

int main(){
    // Point<int> p1(0, -2), p2(1, -2), p3(1, 2), p4(-1, 0), p5(1, 0);
    // Pentagon<int> fig(p1,p2,p3,p4,p5);
    // cout << fig.square() << endl;
    // double sqr = fig;
    // cout << sqr << endl;

    Point<double> p1(0.0, -2.0), p2(1.0, -2.0), p3(1.0, 2.0), p4(-1.0, 0.0), p5(1.0, 0.0);
    Pentagon<double> fig(p1,p2,p3,p4,p5);
    Point<double> p0;

    cout << p0 << ' ' << fig.center() << endl;
}