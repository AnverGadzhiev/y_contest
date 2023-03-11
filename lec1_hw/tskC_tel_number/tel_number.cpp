#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>

std::string ProcessNumber(const std::string& number) {
    std::string num = number;
    if (num[0] == '+') {
        num = num.substr(2, num.length() - 2);
    }
    char symb_to_remove[3] { '-', '(', ')' };
    for (int i = 0; i < 3; ++i) {
        num.erase(std::remove(num.begin(), num.end(), symb_to_remove[i]), num.end());
    }
    if (num.length() == 11 && num[0]=='8') {
        num = num.substr(1, 10);
    }
    if (num.length() == 7) {
        return std::string("495") + num;;
    } else {
        return num;
    }
}

void TestFunction() {
    std::cout << ProcessNumber("8(495)430-23-97") << std::endl;
    std::cout << ProcessNumber("+7-4-9-5-43-023-97") << std::endl;
    std::cout << ProcessNumber("4-3-0-2-3-9-7") << std::endl;
    std::cout << ProcessNumber("8-495-430") << std::endl;
    std::cout << ProcessNumber("86406361642") << std::endl;

}



int main() {
    // TestFunction();
    std::string new_num;
    std::vector<std::string> phone_book;
    
    std::getline(std::cin, new_num);
    new_num = ProcessNumber(new_num);

    std::string temp;
    for (int i = 3; i-->0;) {
        std::getline(std::cin, temp); 
        phone_book.push_back(ProcessNumber(temp));
    }
    
    for (std::string old : phone_book) {
        if (old == new_num) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}