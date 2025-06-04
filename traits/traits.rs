// Implementation of trait examples from README.md

// Define the Speak trait
trait Speak {
    fn speak(&self, msg: &str);
    fn get_age(&self) -> u32;
}

// Define the Dog struct
struct Dog {
    age: u32,
}

// Implement Speak trait for Dog
impl Speak for Dog {
    fn speak(&self, msg: &str) {
        println!("{}", msg);
    }

    fn get_age(&self) -> u32 {
        self.age
    }
}

fn main() {
    // Create a Dog instance
    let dog = Dog { age: 5 };

    // Use the trait methods
    dog.speak("Woof!");
    println!("Dog's age is: {}", dog.get_age());

    // Demonstrate using the trait in a generic function
    fn make_speak<T: Speak>(speaker: &T, message: &str) {
        speaker.speak(message);
        println!("Speaker's age: {}", speaker.get_age());
    }

    make_speak(&dog, "Generic woof!");
}
