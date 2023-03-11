#include <iostream>
#include <string>
#include <algorithm>

template <typename T> 
T Max(const T & t1, const T & t2) {
    if (t1 < t2) {
        return t2;
    }
    return t1;
} 

std::string IsItPossibleToCreateTriangular(const int& e1,const int& e2, const int& e3) {
    int c, a = std::max(e1, std::max(e2, e3)), b = std::min(e1, std::min(e2, e3));
    c = e1 + e2 + e3 - a - b;
    if (b > 0) {
        if (b + c > a) {
            return std::string("YES");
        }
    }
    return std::string("NO");
}

void TestFunction() {

}

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    std::cout << IsItPossibleToCreateTriangular(a, b, c);
    return 0;
}