# Tests

In Rust, tests are written in the same file as the code they are testing. This is a deliberate design decision to encourage developers to write tests for their code. The tests are written in a separate module, annotated with `#[cfg(test)]`, and are run with the `cargo test` command.

## Cargo Test

Tests are running parallel by default. To run tests sequentially, use `cargo test -- --test-threads=1`. 

- To run a specific test, use `cargo test <test_name>`.
- To run multiple tests, use `cargo test <test_name_1> <test_name_2>`.
- To run all tests in a file, use `cargo test <file_name>`.
- To run all tests in a directory, use `cargo test <directory_name>`.
- To run all tests in a directory and its subdirectories, use `cargo test -- --test-threads=1`.
- To show the output of successful tests, use `cargo test -- --show-output`.
- To run test that have a common name, use `cargo test add`. This will run all tests that have `add` in their name.
- To run ignored tests, use `cargo test -- --ignored`.

How we know that tests running in parallel, if we have a test that depends of another dependency that is mutated by another test, we can't be sure that the test will pass. To solve this problem, we can use the `--test-threads=1` flag to run tests sequentially.

The #[cfg(test)] annotation on the tests module tells Rust to compile and run the test code only when you run cargo test, not when you run cargo build. This saves compile time when you only want to build the library and saves space in the resulting compiled artifact because the tests are not included.

Rust allow to test private functions. To do that, we need to add `#[cfg(test)]` annotation to the module that contains the private function and add `#[test]` annotation to the private function.

## Integration Tests

In Rust, integration tests are entirely external to your library. The integration tests are located in a directory called `tests` that is a sibling of `src`. Cargo treats the `tests` directory specially and compiles files in this directory only when we run `cargo test`. So, we don't need to annotate the tests module with `#[cfg(test)]`.