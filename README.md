# Rust-like C++

This repo is an effort to prove that modern C++ has quite a lot of Rust's features, particularly regarding type and memory safety.

> Of course this is nothing to be taken seriously. Consider this to be (mostly) educated shitposting

## Usage

`rustc`, `make`, and a (very) recent C++ compiler (like `clang++` 19.1.7) are required to build the examples in this repo.
```bash
# Build all executables
make

# Build and run all executables
make run-all
```

## Common types

### Integers? Integers!
Since C++11, C++ has a set of [fixed-width integer types](https://en.cppreference.com/w/cpp/types/integer.html) that are equivalent to Rust's primitive integer types.
```rust
let a: i32 = -6;
let b: u16 = 9;
```
```cpp
int32_t a = -6;
uint16_t b = 9;
```

### Strings
Since C++17, C++ has a [`std::string_view`](https://en.cppreference.com/w/cpp/string/basic_string_view.html) type that is equivalent to Rust's `&str` as a non-owning string slice.
```rust
let s = String::from("hello");
f(&s); // where fun f(v: &str)
```
```cpp
string a = "hello";
f(a); // where void f(string_view v)
```

## Memory

### Use const references
`const` [references](https://en.cppreference.com/w/cpp/language/reference.html) in C++ are similar to Rust's references, allowing you to pass around data without copying it, while ensuring that the data cannot be modified.
```rust
let a: i32 = 3;
f(&a); // where fun f(x: &i32)
```
```cpp
int32_t a = 3;
f(a); // where void f(const& int32_t x)
```

### Don't copy, move
Since C++11, C++ has [`std::unique_ptr`](https://en.cppreference.com/w/cpp/memory/unique_ptr.html) which is similar to Rust's ownership model, allowing you to transfer ownership of resources without copying them.
```rust
let a: i32 = 3;
f(a) // where fun f(x: i32)
```
```cpp
auto a = make_unique<int32_t>(3);
f(move(a)); // where void f(unique_ptr<int32_t> x)
```
For cases where you want to share ownership while still using *smart pointers*, C++ has [`std::shared_ptr`](https://en.cppreference.com/w/cpp/memory/shared_ptr.html).

## Traits

### Concepts everywhere
Since C++20, C++ has [constraints & concepts](https://en.cppreference.com/w/cpp/language/constraints.html) that allow you to define constraints on types, similar to Rust's traits.
```rust
trait Speak {
    fn speak(&self, msg: &str);
    fn get_age(&self) -> u32;
}
```
```cpp
template<typename T>
concept Speak = requires(const T& x) {
    { x.speak(std::string_view{}) } -> std::same_as<void>;
    { x.get_age() } -> std::same_as<uint32_t>;
};
```

### Structs be structin'
In C++, structs can be used similarly to Rust's structs, except that members are public by default.
> A slight difference is that in Rust, struct fields are laid out in memory in an order chosen by the compiler, which may rearrange them for optimal alignment and performance. In C++, struct fields are always laid out in the order they are declared. C++'s behavior can be enforced with Rust's `#[repr(C)]` attribute, and you can achieve Rust's behavior in C++ by using `#pragma pack` and ensuring that the fields are declared in the desired order.
```rust
struct Dog { pub age: i32 };
```
```cpp
struct Dog { int32_t age; }
```

### Templates do implement
In C++, you can use [templates](https://www.en.cppreference.com/w/cpp/language/templates.html) to implement concepts, similar to Rust's trait implementations.
```rust
impl Speak for Dog {
    fn speak(&self, msg: &str) {
        println!(msg);
    }
    fn get_age(&self) { self.age }
}
```
```cpp
struct Dog {
    uint32_t age;

    void speak(std::string_view msg) const {
        std::cout << msg << '\n';
    }

    uint32_t get_age() const {
        return age;
    }
};
static_assert(Speak<Dog>);
```

## Safer Return Values

### Options
Since C++17, C++ has [`std::optional`](https://en.cppreference.com/w/cpp/utility/optional.html) which is similar to Rust's `Option<T>`, allowing you to represent a value that may or may not be present.
```rust
fn find(id: u32) -> Option<u32> {
    if id > 0 { Some(id) } else { None }
}
```
```cpp
std::optional<uint32_t> find(uint32_t id) {
    if (id > 0) return id;
    return std::nullopt;
}
```

### Expected results
Since C++23, C++ has [`std::expected`](https://en.cppreference.com/w/cpp/utility/expected.html) which is similar to Rust's `Result<T, E>`, allowing you to represent a value that may be an error.
```rust
fn divide(a: i32, b: i32) -> Result<i32, &'static str> {
    if b == 0 { Err("division by zero") } else { Ok(a / b) }
}
```
```cpp
std::expected<int32_t, std::string> divide(int32_t a, int32_t b) {
    if (b == 0) return std::unexpected("division by zero");
    return a / b;
}
```

### Don't ignore me
Since C++17, C++ has the [`[[nodiscard]]`](https://en.cppreference.com/w/cpp/language/attributes/nodiscard) attribute which is similar to Rust's `#[must_use]`, allowing you to indicate that a function's return value should not be ignored.
```rust
#[must_use]
fn compute_value() -> i32 {
    42
}
```
```cpp
[[nodiscard]]
int32_t compute_value() {
    return 42;
}
```