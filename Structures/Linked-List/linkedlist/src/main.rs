use linkedlist::List;

fn main() {
  let mut list = List::new(1);
  list.head_append(2);
  list.head_append(3);
  list.head_append(4);
  println!("{:?}", list);
}
