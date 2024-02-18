#[derive(Debug)]
pub struct Rectangle {
    pub width: u32,
    pub height: u32,
}

impl Rectangle {
    pub fn can_hold(&self, other: &Rectangle) -> bool {
        self.width > other.width && self.height > other.height
    }

    pub fn square(width: u32, height: u32) -> Rectangle {
        if width < 1 {
            panic!("expected width to be greater than 0, but width = {}", width);
        }

        if height < 1 {
            panic!(
                "expected height to be greater than 0, but height = {}",
                height
            );
        }

        Rectangle { width, height }
    }
}
