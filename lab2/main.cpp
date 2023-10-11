#include "six.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
    Six elem1{'0', '0', '2', '0', '0'};
    Six elem2;
    string a = "010";
    elem2 = Six(a);

    Six sum1 = elem1 + elem2;
    Six sum2 = elem1 += Six("1");
    Six diff1 = elem1 - elem2;
    Six diff2 = elem1 -= Six("1");

    cout << elem1 << ' ' << elem2 << endl;
    cout << sum1 << ' ' << sum2 << endl;
    cout << diff1 << ' ' <<  diff2 << endl;

    return 0;
}
