#include <iostream>
#include <string_view>
#include <concepts>
#include <cassert>

// Define the Speak concept (equivalent to Rust's trait)
template <typename T>
concept Speak = requires(const T &x) {
    { x.speak(std::string_view{}) } -> std::same_as<void>;
    { x.get_age() } -> std::same_as<uint32_t>;
};

// Define the Dog struct with inline implementation
struct Dog
{
    uint32_t age;

    void speak(std::string_view msg) const
    {
        std::cout << msg << '\n';
    }

    uint32_t get_age() const
    {
        return age;
    }
};

// Verify Dog satisfies Speak concept at compile time
static_assert(Speak<Dog>);

// Generic function that works with any type that satisfies Speak
template <Speak T>
void make_speak(const T &speaker, std::string_view message)
{
    speaker.speak(message);
    std::cout << "Speaker's age: " << speaker.get_age() << std::endl;
}

int main()
{
    // Create a Dog instance
    Dog dog{5};

    // Use the methods directly
    dog.speak("Woof!");
    std::cout << "Dog's age is: " << dog.get_age() << std::endl;

    // Use the generic function
    make_speak(dog, "Generic woof!");

    return 0;
}
