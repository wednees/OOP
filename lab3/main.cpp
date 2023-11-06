#include <iostream>

#include "Vector.hpp"
#include "point.hpp"
#include "figure.hpp"
#include "hexagon.hpp"
#include "rhomb.hpp"
#include "pentagon.hpp"

using namespace std;

int main(){
    // Point p1(-4, 0), p2(0, 5), p3(4, 0), p0(0, -5);
    // Point p4 = p0;
    // Rhomb fig2(p1,p2,p3,p4);
    // double sqr = fig2;
    // cout << sqr << endl;
    // cout << fig2.square() << endl;
    // return 0;

    Rhomb fig1;
    Hexagon fig2;
    Vector arr;

    arr.push_back(&fig1);
    arr.push_back(&fig2);

    for (size_t i = 0; i < arr.size(); ++i){
        cout << *arr[i] << endl;;
    }

    arr.remove(0);

        for (size_t i = 0; i < arr.size(); ++i){
        cout << *arr[i] << endl;
    }
}