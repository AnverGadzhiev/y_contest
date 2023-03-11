#include <iostream>
#include <cmath>

std::string SolveSqrEquation(const int& a, const int& b, const int& c) {
    if (c >= 0) {
        if (a != 0) {
            double psb_ans = double(c * c - b) / a;
            if ( psb_ans == std::floor(psb_ans) ) {
                return std::to_string( int(psb_ans) );
            } else {
                return std::string("NO SOLUTION");
            }
        } else {
            if ( c * c == b ) {
                return std::string("MANY SOLUTIONS");
            } else {
                return std::string("NO SOLUTION");
            }
        }
    } 
    return std::string("NO SOLUTION");
}

void TestSolution() {
    std::cout << SolveSqrEquation(1, 0, 0) << std::endl;
    std::cout << SolveSqrEquation(1, 2, 3) << std::endl;
    std::cout << SolveSqrEquation(1, 2, -3) << std::endl;
    std::cout << SolveSqrEquation(0, 0, 0) << std::endl;
    std::cout << SolveSqrEquation(0, 4, 2) << std::endl;
    std::cout << SolveSqrEquation(4, 25, 5) << std::endl;
    std::cout << SolveSqrEquation(0, 22, 3) << std::endl;
    std::cout << SolveSqrEquation(3, 2, 2) << std::endl;

}

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    std::cout << SolveSqrEquation(a, b, c);
    // TestSolution();
    return 0;
}