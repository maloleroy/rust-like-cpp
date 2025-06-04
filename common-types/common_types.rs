fn main() {
    // Integers? Integers!
    let a: i32 = -6; // int32_t a = -6;
    let b: u16 = 9;  // uint16_t b = 9;

    println!("a: {}", a);
    println!("b: {}", b);

    // Strings
    let s = String::from("world"); // string a = "hello";
    f(&s); // f(a); where f is a function taking &str (string_view in C++)
}

fn f(input: &str) {
    println!("Hello {}", input);
}
