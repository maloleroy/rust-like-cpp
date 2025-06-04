#include <iostream>
#include <optional>
#include <expected>
#include <string>
#include <cstdint>

std::optional<uint32_t> find(uint32_t id) {
    if (id > 0) return id;
    return std::nullopt;
}

std::expected<int32_t, std::string> divide(int32_t a, int32_t b) {
    if (b == 0) return std::unexpected("division by zero");
    return a / b;
}

int main() {
    // Option example
    auto id = 42;
    if (auto found_id = find(id)) {
        std::cout << "Found: " << *found_id << '\n';
    } else {
        std::cout << "Not found\n";
    }

    // Check non-existent id
    if (auto found_id = find(0)) {
        std::cout << "Found: " << *found_id << '\n';
    } else {
        std::cout << "Not found\n";
    }

    // Result example
    auto result1 = divide(10, 2);
    if (result1) {
        std::cout << "10/2 = " << *result1 << '\n';
    } else {
        std::cout << "Error: " << result1.error() << '\n';
    }

    auto result2 = divide(5, 0);
    if (result2) {
        std::cout << "5/0 = " << *result2 << '\n';
    } else {
        std::cout << "Error: " << result2.error() << '\n';
    }

    return 0;
}
