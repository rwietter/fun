#[derive(Debug, Copy, Clone)]
pub enum ShirtColor {
  Red,
  Blue,
}

pub struct Inventory {
  pub shirts: Vec<ShirtColor>,
}

impl Inventory {
  pub fn giveway(&self, user_preference: Option<ShirtColor>) -> ShirtColor {
    // returns a user preference if it exists,
    // otherwise returns the most stocked color
    user_preference.unwrap_or_else(|| self.most_stocked())
  }

  pub fn most_stocked(&self) -> ShirtColor {
    let mut num_red = 0;
    let mut num_blue = 0;

    for color in &self.shirts {
      match color {
        ShirtColor::Red => num_red += 1,
        ShirtColor::Blue => num_blue += 1,
      }
    }

    if num_red > num_blue {
      return ShirtColor::Red;
    }
    ShirtColor::Blue
  }
}

#[cfg(test)]
mod tests {
  use super::*;
  use std::thread;

  #[test]
  fn closure() {
    let expensive_closure = |num| num;

    assert!(
      expensive_closure(2) == 2,
      "expensive_closure should be 2, got {}",
      expensive_closure(2)
    )
  }

  #[test]
  fn mutable_closure() {
    let mut list = vec![1, 2, 3];

    let mut borrows_mutably = |n| list.push(n);

    borrows_mutably(4);
    let expected = vec![1, 2, 3, 4];

    assert!(
      list == expected,
      "borrows_mutably should be [1, 2, 3, 4], got {:?}",
      list
    )
  }

  #[test]
  fn move_closure() {
    let list = vec![1, 2, 3];

    let result = thread::spawn(move || format!("From thread: {:?}", list))
      .join()
      .unwrap();

    // list is moved into the closure, so it can't be used here

    assert!(
      result == "From thread: [1, 2, 3]",
      "res should be 'From thread: [1, 2, 3]', got {}",
      result
    )
  }
}
