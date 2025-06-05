#include <iostream>
#include <optional>
#include <expected>
#include <string>
#include <cstdint>
#include <cassert>

std::optional<uint32_t> find(uint32_t id) {
    if (id > 0) return id;
    return std::nullopt;
}

std::expected<int32_t, std::string> divide(int32_t a, int32_t b) {
    if (b == 0) return std::unexpected("division by zero");
    return a / b;
}

// This function is marked as "nodiscard" - the compiler will warn if its return value is ignored
[[nodiscard]]
int32_t compute_value() {
    return 42;
}

int main() {
    // 1. Option
    uint32_t id = 42;
    auto found_id = find(id);
    assert(found_id.has_value());
    assert(*found_id == id);
    auto not_found_id = find(0);
    assert(!not_found_id.has_value());
    assert(not_found_id == std::nullopt);

    // 2. Result
    auto result1 = divide(10, 2);
    assert(result1.has_value());
    assert(*result1 == 5);

    auto result2 = divide(5, 0);
    assert(!result2.has_value());
    assert(result2.error() == "division by zero");

    // 3. Must Use
    auto value = compute_value(); // used value
    std::cout << "Computed value: " << value << '\n';

    // We're ignoring the return value of a [[nodiscard]] function
    compute_value(); // Compiler will generate a warning here

    // We can explicitly silence the warning by casting to void
    (void)compute_value();
    return 0;
}
