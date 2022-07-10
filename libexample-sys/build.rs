fn main() {
    cc::Build::new()
        .file("libexample.c")
        .compile("example");
}
