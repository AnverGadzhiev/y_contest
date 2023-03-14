#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>

std::pair<int, int> FindEntranceAndFloor(const int& K1,const int& M, const int &K2, const int& P, const int& N) {
    if (N + P == 2) {
        if (K1 <= K2) {
            return {1, 1};
        } else {
            return {0, 1};
        }
    } else {
        for (int Q = std::ceil(double(K2) / (N + (P - 1) * M)); Q < K2 + 1;++Q) {
            if (K2 % Q + Q * (N - 1 + (P - 1) * M) == K2)  {
                if (Q * M * (P - 1) + Q * (N - 1) < K2) { 
                    int ent = K1 / (Q * M) + 1;
                    int floor = 1 - M * (ent - 1) + (K1 / Q);
                    return {ent, floor};
                }
            }
        }
    }
    return {-1, -1};
}

void PrintAnswer(const std::pair<int, int> &ans) {
    std::cout << std::get<0>(ans) << " " << std::get<1>(ans);
}

void TestSolution() {
    PrintAnswer(FindEntranceAndFloor(89, 20, 41, 1, 11));
    PrintAnswer(FindEntranceAndFloor(11, 1, 1, 1, 1));
    PrintAnswer(FindEntranceAndFloor(3, 2, 2, 2, 1));
}

int main() {
    int K1, M, K2, P2, N2;
    std::cin >> K1 >> M >> K2 >> P2 >> N2;
    PrintAnswer(FindEntranceAndFloor(K1, M, K2, P2, N2));
    // TestSolution();
    return 0;
}