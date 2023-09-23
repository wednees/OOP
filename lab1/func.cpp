#include <cmath>
#include "task.h"
using namespace std;

int task (int a, int b){
    int ans = 0;
    for (int i = a; i <= b; ++i){
        int tmp = abs(i);
        while (tmp != 0){
            ans = ans + (tmp % 2);
            tmp = tmp / 2;
        }
    }
    return ans;
}
