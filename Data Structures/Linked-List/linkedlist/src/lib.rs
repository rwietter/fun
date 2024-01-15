#[derive(Debug)]
pub struct List<T> {
  head: T,
  next: Option<Box<List<T>>>,
}

impl<T: std::fmt::Debug> List<T> {
  pub fn new(head: T) -> Self {
    List { head, next: None }
  }

  pub fn tail_append(&mut self, head: T) {
    let mut current = self;
    while let Some(ref mut next) = current.next {
      current = next;
    }
    current.next = Some(Box::new(List::new(head)));
  }

  pub fn head_append(&mut self, head: T) {
    let list = self;
    let next = list.next.take();
    list.next = Some(Box::new(List { head, next }));
  }
}

#[cfg(test)]
mod tests {
  use super::*;

  #[test]
  fn it_works() {
    // let result = add(2, 2);
    assert_eq!(4, 4);
  }
}
