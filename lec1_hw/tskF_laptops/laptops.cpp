#include <iostream>
#include <tuple>
#include <cmath>
#include <limits>
#include <tuple>
#include <vector>

std::pair<int, int> TableSize(const int a1, const int b1, const int a2, const int b2) {
    uint len = std::numeric_limits<int>::max(), wdth = 1;
  
     if ((a1 + a2) * std::max(b1, b2) < len * wdth) {
        len = (a1 + a2);
        wdth = std::max(b1, b2);
        std::cout << "case: " << 1 << std::endl;
    }
    if ((b1 + b2) * std::max(a1, a2) < len * wdth) {
        len = (b1 + b2);
        wdth = std::max(a1, a2);
        std::cout << "case: " << 2 << std::endl;

    }
    if ((a1 + b2) * std::max(b1, a2) < len * wdth) {
        len = (a1 + b2);
        wdth = std::max(b1, a2);
        std::cout << "case: " << 3 << std::endl;

    }
    if ((b1 + a2) * std::max(a1, b2) < len * wdth) {
        len = (b1 + a2);
        wdth = std::max(a1, b2);
        std::cout << "case: " << 4 << std::endl;
    }
    
    return std::pair<int, int>(len, wdth);
}

std::pair<int, int> TableSize2(const int a1, const int b1, const int a2, const int b2) {
    uint len = std::numeric_limits<int>::max(), wdth = 1;
    std::vector<std::tuple<int, int, int, int>> t = {std::tuple<int, int, int, int>(a1, a2, b1, b2), std::tuple<int, int, int, int>(b1, b2, a1, a2), 
    std::tuple<int, int, int, int>(a1, b2, b1, a2), std::tuple<int, int, int, int>(b1, a2, a1, b2)};

    for (auto &&tup : t) {
        if ((std::get<0>(tup) + std::get<1>(tup)) * std::max(std::get<3>(tup), std::get<2>(tup)) < len * wdth) {
            len = std::get<0>(tup) + std::get<1>(tup);
            wdth = std::max(std::get<3>(tup), std::get<2>(tup));
        }
    }

    return std::pair<int, int>(len, wdth);    
}
void printPair(const std::pair<int, int> p) {
    std::cout << std::get<0>(p) << " " <<  std::get<1>(p) << std::endl;
    std::cout << std::endl;
}

void TestSolution() {
    printPair(TableSize(10, 2, 2, 10));
    printPair(TableSize(5, 7, 3, 2));
    printPair(TableSize(10, 10, 10, 10));
    printPair(TableSize(4, 3, 2, 1));   

    printPair(TableSize2(10, 2, 2, 10));
    printPair(TableSize2(5, 7, 3, 2));
    printPair(TableSize2(10, 10, 10, 10));
    printPair(TableSize2(4, 3, 2, 1));   

}

int main() {
    int a1, b1, a2, b2;
    std::cin >> a1 >> b1 >> a2 >> b2;
    printPair(TableSize2(a1, b1, a2, b2));
    // std::cout << TableSize(a1, b1, a2, b2) << std::endl;
    // TestSolution();
    return 0;
}