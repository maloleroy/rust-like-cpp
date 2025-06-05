fn find(id: u32) -> Option<u32> {
    if id > 0 { Some(id) } else { None }
}

fn divide(a: i32, b: i32) -> Result<i32, &'static str> {
    if b == 0 { Err("division by zero") } else { Ok(a / b) }
}

// This function is marked as "must_use" - the compiler will warn if its return value is ignored
#[must_use]
fn compute_value() -> i32 {
    42
}

fn main() {
    // 1. Option
    let id = 42;
    assert_eq!(find(id), Some(42));
    assert_eq!(find(0), None);

    // 2. Result
    assert_eq!(divide(10, 2), Ok(5));
    assert_eq!(divide(5, 0), Err("division by zero"));

    // 3. Must Use
        let value = compute_value(); // used value
    println!("Computed value: {}", value);

    // We're ignoring the return value of a #[must_use] function
    compute_value(); // Compiler will generate a warning here

    // We can explicitly silence the warning by ignoring the return value
    let _ = compute_value();

}
