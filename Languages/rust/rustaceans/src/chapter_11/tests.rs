// To run tests: cargo test

fn internal_adder(a: i32, b: i32) -> i32 {
    a + b
}

#[cfg(test)]
mod tests {
    #[warn(unused_imports)]
    use super::*;
    use crate::chapter_11::rectangle::Rectangle;

    #[test]
    fn larger_can_hold_smaller() {
        let larger = Rectangle {
            width: 8,
            height: 7,
        };
        let smaller = Rectangle {
            width: 5,
            height: 1,
        };

        assert!(larger.can_hold(&smaller)); // boolean assertion
    }

    #[test]
    fn equality_test() {
        assert_eq!(5, 5); // equality assertion
        assert_ne!(2, 7); // inequality assertion
    }

    #[test]
    fn message_test() {
        let x = 5;
        let y = 5;
        // after first argument, all arguments are passed to format! macro and converted to string
        assert!(
            x == y,
            "expected x to be equal to y, but x = {}, y = {}",
            x,
            y
        );
    }

    #[test]
    // This test will fail, but we must use specific test with message to know why it failed
    #[should_panic(expected = "expected width to be greater than 0, but width = 0")] // message must be exact match of panic message
    fn should_panic_test() {
        let rect = Rectangle::square(0, 1);
    }

    #[test]
    // We wouldn't to use panic! macro with Err variant
    fn result_test() -> Result<(), String> {
        let rect = Rectangle::square(4, 4);
        if rect.height == rect.width {
            return Ok(());
        }
        Err(String::from(
            "Expected height to be equal to width, but it is not",
        ))
    }

    #[test]
    #[ignore]
    fn ignored_test() {
        assert_eq!(2 + 2, 4);
    }

    #[test]
    fn internal() {
        assert_eq!(internal_adder(2, 2), 4); // Test private function from this module
    }
}
