use libexample_sys::*;

fn main() {
    println!("Initializing...");
    let data = unsafe { libexample_init() };
    println!("Incrementing...");
    unsafe { libexample_inc(data) };
    println!("Destroying...");
    unsafe { libexample_deinit(data) };
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn smoke_test() {
        unsafe {
            let data = libexample_init();
            libexample_inc(data);
            libexample_deinit(data)
        };
    }
}
