#include <iostream>

int main() {
    std::cout << "=== CLI Todo ===\n";
    std::cout << "1. Add\n2. List\n3. Exit\n> ";
    int choice;
    std::cin >> choice;
    std::cout << "You chose: " << choice << '\n';
    return 0;
}