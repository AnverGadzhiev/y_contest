#include <string>
#include <array>
#include <tuple>

namespace slv {

class RootIsNotIntExeption : public std::exception {
public: 
    char * what() {
        return "Found root is not integer";
    }   
};

class NoNumenatorRootsExeption : public std::exception {
public: 
    char * what() {
        return "Numenator has no roots";
    }   
};

class InfiniteNumberOfNumenatorRootsExeption : public std::exception {
public: 
    char * what() {
        return "Numenator has infinite number of roots";
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