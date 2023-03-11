#include <iostream>
#include <string>

int RoomTempAfterHour(const int& troom, const int& tcond, const std::string& mode) {
    if (mode == "fan") {
        return troom;
    }
    if (mode == "auto") {
        return tcond;
    }
    if (mode == "heat") {
        if (troom >= tcond) {
            return troom;
        } else {
            return tcond;
        } 
    }
    if (mode == "freeze") {
        if (troom <= tcond) {
            return troom;
        } else {
            return tcond;
        } 
    }
    return 0;
}

void TestSolution() {
    std::cout << RoomTempAfterHour(10, 20, "heat");
    std::cout << RoomTempAfterHour(20, 10, "hot");
    std::cout << RoomTempAfterHour(10, 20, "freeze");
    std::cout << RoomTempAfterHour(10, 10, "hot");
    std::cout << RoomTempAfterHour(10, 20, "fan");
    std::cout << RoomTempAfterHour(1, 81940, "auto");
}

int main() {
    int troom, tcond;
    std::string mode;
    std::cin >> troom >> tcond;
    std::cin >> mode;
    std::cout << RoomTempAfterHour(troom, tcond, mode);
    //TestSolution();
    return 0;
}