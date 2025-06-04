// Implementation of options and results from README.md

fn find(id: u32) -> Option<u32> {
    if id > 0 { Some(id) } else { None }
}

fn divide(a: i32, b: i32) -> Result<i32, &'static str> {
    if b == 0 { Err("division by zero") } else { Ok(a / b) }
}

fn main() {
    // Option example
    let id = 42;
    match find(id) {
        Some(found_id) => println!("Found: {}", found_id),
        None => println!("Not found"),
    }

    // Also works with if let
    if let Some(found_id) = find(0) {
        println!("Found: {}", found_id);
    } else {
        println!("Not found");
    }

    // Result example
    match divide(10, 2) {
        Ok(result) => println!("10/2 = {}", result),
        Err(e) => println!("Error: {}", e),
    }

    match divide(5, 0) {
        Ok(result) => println!("5/0 = {}", result),
        Err(e) => println!("Error: {}", e),
    }
}
