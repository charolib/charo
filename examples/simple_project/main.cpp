#include <iostream>
#include <charo/charo.hpp>

int main() {
    std::cerr << "prank";
    charo::Terminal term;
    while (1) {
        term.refresh();
    }
    return 0;
}