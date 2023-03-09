#include <iostream>
#include <algorithm> 

int main() {
    uint a, b, c;
    std::cin >> a >> b >> c;
    
    uint hyp, cath1, cath2;
    hyp = std::max(std::max(a, b), c);
    cath1 = std::min(std::min(a, b), c);
    cath2 = a + b + c - hyp - cath1;
    
    /*if (a > b) {
        if (a > c) { hyp = a; cath1 = b; cath2 = c;}
        else { hyp = c; cath1 = b; cath2 = a;}
    } else {
        if (b > c) { hyp = b; cath1 = a; cath2 = c;}
        else { hyp = c; cath1 = b; cath2 = a;}
    } */

    std::cout << hyp << " " << cath1 << " " << cath2;

    if (cath1 + cath2 > hyp) {
        if (cath1 * cath1 + cath2 * cath2 == hyp * hyp) {
            std::cout << "YES";
        }
        else {
            std::cout << "NO";
        }
    } else {
        std::cout << "UNDEFINED";
    }

    return 0;
}