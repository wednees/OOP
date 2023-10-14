#include <iostream>
#include "task.hpp"

int main (void){
    std::cout << "Enter lws and rws" << std::endl;
    int lws, rws;
    std::cin >> lws >> rws;
    if (lws > rws){
        std::cout << "Error: lws must be less than rws" << std::endl;
    }
    int ans = task(lws, rws);
    std::cout << "Answer for the task: " << ans << std::endl; 
}