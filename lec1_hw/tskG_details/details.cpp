#include <iostream>

int DetailsQuantity(const int n, const int k, const int m) {
    int detq = 0, new_det = 0;

    for (int new_det = (n / k) * ( k / m); new_det > 0;  new_det = ((n - detq * m) / k) * ( k / m)) {
        detq += new_det;
    }

    return detq;
}

void TestSolution() {
    std::cout << DetailsQuantity(10, 5, 2) << "\n\n";
    std::cout << DetailsQuantity(13, 5, 3) << "\n\n";
    std::cout << DetailsQuantity(14, 5, 3) << "\n\n";
    std::cout << DetailsQuantity(1, 1, 1) << "\n\n";
}

int main() {
    int n, k, m;
    std::cin >> n >> k >> m;
    std::cout << DetailsQuantity(n, k, m) << std::endl;
    // TestSolution();
    return 0;
}