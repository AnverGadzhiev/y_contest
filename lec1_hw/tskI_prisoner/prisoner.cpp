#include <iostream>
#include <string>

bool Suit(int, int, int, int);

std::string Solution(int a, int b, int c, int d, int e) {
    if (Suit(a, b, d, e) || Suit(a, c, d, e) || Suit(b, c, d, e)) {
        return "YES";
    }
    return "NO";
} 

bool Suit(int a, int b, int d, int e) {
    if ((a <= d && b <= e) || (a <= e && b <= d)) {
        return true;
    }
    return false;
}

void TestSolution() {
    std::cout << Solution(1, 1, 1, 1, 1) << std::endl;
    std::cout << Solution(2, 2, 2, 1, 1) << std::endl;
}

int main() {
    int a, b, c, d, e;
    std::cin >> a >> b >> c >> d >> e;
    std::cout << Solution(a, b, c, d, e);
    // TestSolution();
    return 0;
}