#include <iostream>
#include <string>
#include <string_view>

using namespace std;

// Function to demonstrate string_view usage
void f(string_view v) {
    cout << "Hello " << v << endl;
}

int main() {
    // Integers? Integers!
    int32_t a = -6; // let a: i32 = -6;
    uint16_t b = 9; // let b: u16 = 9;

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    string s = "world"; // let s = String::from("hello");

    f(s); // f(&s); where fun f(v: &str)

    return 0;
}
