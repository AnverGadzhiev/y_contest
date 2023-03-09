#include <iostream>
#include <string>
#include <array>
#include <tuple>

namespace slv {

class RootIsNotIntExeption : public std::exception {
public: 
    std::string what() {
        return std::string("Found root is not integer");
    }   
};

class NoNumenatorRootsExeption : public std::exception {
public: 
    std::string what() {
        return std::string("Numenator has no roots");
    }   
};

class InfiniteNumberOfNumenatorRootsExeption : public std::exception {
public: 
    std::string what() {
        return std::string("Numenator has infinite number of roots");
    }   
};

class Solver {
public:
    std::tuple<std::string, int, bool> static Solution(const std::array<int, 4> &coef);
private:
    bool static DenomIsZero(const int &root, const int &c, const int &d);
    int static IntRootOfNumenator(const int &a, const int& b);
};
}

std::tuple<std::string, int, bool> slv::Solver::Solution(const std::array<int, 4> &coef) {
    try {
        const int psb_root = IntRootOfNumenator(coef[0], coef[1]);
        if (DenomIsZero(psb_root, coef[2], coef[3])) {
            return std::tuple<std::string, int, bool>(std::string("NO"), 0, false);
        }
        return std::tuple<std::string, int, bool>(std::string("YES"), psb_root, true);
    }
    catch (const slv::RootIsNotIntExeption &risi) {
        return std::tuple<std::string, int, bool>(std::string("NO"), 0, false);
    }
    catch (const slv::NoNumenatorRootsExeption &nnr) {
        return std::tuple<std::string, int, bool>(std::string("NO"), 0, false);
    }
    catch (const slv::InfiniteNumberOfNumenatorRootsExeption &inonr) {
        if (coef[2] == 0 && coef[3] == 0) {
            return std::tuple<std::string, int, bool>(std::string("NO"), 0, false);
        }
        return std::tuple<std::string, int, bool>(std::string("INF"), 0, false);
    }
}

bool slv::Solver::DenomIsZero(const int &root, const int &c, const int &d) {
    return (c * root + d) == 0;
}

int slv::Solver::IntRootOfNumenator(const int &a, const int& b) {
    if (a == 0 && b != 0) {
        throw slv::NoNumenatorRootsExeption();
    } else if (a * a + b * b == 0) {
        throw slv::InfiniteNumberOfNumenatorRootsExeption();
    } else {
        double root = - b * 1.0 / a;
        if (root - int(root) == 0 ) {
            return root;
        } else {
            throw slv::RootIsNotIntExeption();
        }
    }
}

void TestOneCase(const std::array<int, 4> &coefs) {
    std::tuple<std::string, int, bool> answer = slv::Solver::Solution(coefs);
    int ans_ind = std::get<2>(answer); 
    if (ans_ind) {
        int ans = std::get<1>(answer);
        std::cout << ans << std::endl; 
    } else {
        std::string ans = std::get<0>(answer);
        std::cout << ans << std::endl;
    }
}

// void TestAllCase 

int main() {
    std::array<int, 4> coefs;
    std::cin >> coefs[0] >> coefs[1] >> coefs[2] >> coefs[3];
    TestOneCase(coefs);
    return 0;
}