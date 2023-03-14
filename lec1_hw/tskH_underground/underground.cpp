#include <iostream>
#include <cmath>
#include <algorithm>

int DefineMinStayingTime(int a, int b, int n, int m) {
    int t1 = 1, t2 = 1;

    t1 += (a + 1) * (n - 1);
    t2 += (b + 1) * (m - 1);

    return std::max(t1, t2);
}

int DefineMaxStayingTime(const int &a, const int &b, const int &n, const int &m) {
    int t1 = a, t2 = b;

    t1 += (a + 1) * (n - 1) + 1;
    t2 += (b + 1) * (m - 1) + 1;


    return std::max(t1, t2);
}

void TestSolution() {
    std::cout << DefineMinStayingTime(1, 3, 3, 2) << " " << DefineMaxStayingTime(1, 3, 3, 2) << std::endl;
    std::cout << DefineMinStayingTime(1, 5, 1, 2) << " " << DefineMaxStayingTime(1, 5, 1, 2) << std::endl;
    std::cout << DefineMinStayingTime(1, 1, 1, 1) << " " << DefineMaxStayingTime(1, 1, 1, 1) << std::endl;
}

int main() {
    int a, b, n, m;
    // std::cin >> a >> b >> n >> m;
    // std::cout << DefineMinAndMaxStayingTime(a, b, n, m) << std::endl;
    TestSolution();
    return 0;
}