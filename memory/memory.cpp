#include <iostream>
#include <memory>
#include <string>

// Function that accepts a const reference
void f_ref(const int32_t& x) {
    std::cout << "Received const reference to: " << x << std::endl;
}

// Function that takes ownership through move
void f_move(std::unique_ptr<int32_t> x) {
    std::cout << "Took ownership of: " << *x << std::endl;
}

int main() {
    // "Use const references" example
    int32_t a = 3;
    std::cout << "Example: Use const references" << std::endl;
    f_ref(a);
    std::cout << "After reference use, a = " << a << std::endl;

    // "Don't copy, move" example
    std::cout << "\nExample: Don't copy, move" << std::endl;
    auto b = std::make_unique<int32_t>(3);
    std::cout << "Before move, b points to value: " << *b << std::endl;
    f_move(std::move(b));
    std::cout << "After move, b is " << (b ? "still valid" : "null") << std::endl;

    // Another move example with a string
    std::cout << "\nMoving a string example:" << std::endl;
    auto str = std::make_unique<std::string>("hello");
    std::cout << "Before move, str = " << *str << std::endl;
    auto str2 = std::move(str);
    std::cout << "After move, str is " << (str ? "still valid" : "null") << std::endl;
    std::cout << "str2 now owns the data: " << *str2 << std::endl;

    return 0;
}
