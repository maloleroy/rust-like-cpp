// Implementation of memory examples from README.md

// Function that accepts a reference (const reference example)
fn f_ref(x: &i32) {
    println!("Received reference to: {}", x);
}

// Function that takes ownership (move example)
fn f_move(x: i32) {
    println!("Took ownership of: {}", x);
}

fn main() {
    // "Use const references" example
    let a: i32 = 3;
    println!("Example: Use const references");
    f_ref(&a);
    println!("After reference use, a = {}", a);

    // "Don't copy, move" example
    let a: i32 = 3;
    println!("Example: Don't copy, move");
    f_move(a);
    // In Rust, primitive types like i32 implement Copy,
    // so we can still use 'a' after passing it to f_move
    println!("In Rust, primitives implement Copy, so a = {}", a);

    // To demonstrate true move semantics, let's use a non-Copy type like String
    let s = String::from("hello");
    println!("Moving a String, s = {}", s);
    let s2 = s;  // s is moved to s2
    // println!("Can't use s anymore: {}", s); // This would cause a compile error
    println!("s2 now owns the data: {}", s2);
}
