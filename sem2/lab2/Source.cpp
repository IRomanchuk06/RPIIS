#include "include.h"

int main() {
    setlocale(LC_ALL, "RU");
    int numElements;
    cout << "������� ���������� ��������� � ���������: ";
    cin >> numElements;

    PermutationGenerator generator(numElements);
    generator.readInputSet();
    generator.generatePermutations();

    return 0;
}
