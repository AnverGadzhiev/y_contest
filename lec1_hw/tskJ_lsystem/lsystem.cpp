#include <iostream>
#include <tuple>

std::tuple<uint, double, double> Solution(int a, int b, int c, int d, int e, int f) {
    if (a*a + b*b + c*c + d*d + e*e + f*f == 0) {
        return {5, -1, -1};
    } else {
        if (a*d - c*b != 0) {
            return {2, double((f * a - c * e)) / (a * b - c * d), double(( e * d - b * f )) / (a * b - c * d)};
        } else {
            
        }
    }
    return {0, 0, 0};
}

void PrintAnswer(std::tuple<uint, double, double> t) {
    if (std::get<0>(t) != 0 && std::get<0>(t) != 5 ) {
        std::cout << std::get<0>(t) << " " << std::get<1>(t) << " " << std::get<2>(t) << std::endl;
    } else { 
        std::cout << std::get<0>(t) << std::endl;
    }
}

void TestSolution() {
    PrintAnswer(Solution(1, 0, 0, 1, 3, 3));
    PrintAnswer(Solution(1, 1, 2, 2, 1, 2));
    PrintAnswer(Solution(0, 2, 0, 4, 1, 2));
}

int main() {
    int a, b, c, d, e, f;
    // std::cin >> a >> b >> c >> d >> e >> f;
    // Solution(a, b, c, d, e, f);
    TestSolution();
    return 0;
}