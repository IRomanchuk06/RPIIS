#include <iostream>
#include <vector>
#include "C:\Users\������\source\repos\���������\SetLib\Header.h"

using namespace std;
using namespace SetLib;

int main() {
    setlocale(LC_ALL, "rus");

    for (const auto& set : cartesianProduct(CreateSets(5))) {
        printSet(set);
    }

    return 0;
}