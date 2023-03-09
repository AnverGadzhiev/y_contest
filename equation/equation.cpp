#include "equation.h"

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
        return std::tuple<std::string, int, bool>(std::string("NO"), 0, false);
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
