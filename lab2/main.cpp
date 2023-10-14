#include "six.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
    Six elem1{'0', '0', '2', '0', '0'};
    Six elem2;
    string a = "010";
    elem2 = Six(a);

    Six sum = elem1 + elem2;
    Six diff = elem1 - elem2;

    cout << elem1 << ' ' << elem2 << endl;
    cout << sum << endl;
    cout << diff << endl;

    return 0;
}
