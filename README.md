# Rust-like C++

This repo is an effort to prove that modern C++ has quite a lot of Rust's features, particularly regarding type and memory safety.

> Of course this is nothing to be taken seriously. Consider this to be (mostly) educated shitposting

## Common types
### Integers? Integers!
```rust
let a: i32 = -6;
let b: u16 = 9;
```
```cpp
int32_t a = -6;
uint16_t b = 9;
```
### Strings
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
```rust
let a: i32 = 3;
f(&a); // where fun f(x: &i32)
```
```cpp
int32_t a = 3;
f(a); // where void f(const& int32_t x)
```
### Don't copy, move
```rust
let a: i32 = 3;
f(a) // where fun f(x: i32)
```
```cpp
auto a = make_unique<int32_t>(3);
f(move(a)); // where void f(unique_ptr<int32_t> x)
```
## Traits
### Concepts everywhere
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
```rust
struct Dog {age: u32};
```
```cpp
struct Dog { int32_t age; }
```
### Templates do implement
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