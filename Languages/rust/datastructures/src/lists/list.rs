use std::fmt::Display;

struct Node<T> {
    value: T,
    next: Option<Box<Node<T>>>,
}

struct List<T> {
    head: Option<Box<Node<T>>>,
}
impl<T: Display> List<T> {
    pub fn new() -> Self {
        List { head: None }
    }

    pub fn insert(&mut self, v: T) {
        let new_node = Node {
            value: v,
            next: self.head.take(),
        };
        self.head = Some(Box::new(new_node));
    }

    fn print_list(&self) {
        let mut current_node = &self.head;
        print!("List: ");
        while let Some(node) = current_node {
            print!("{} ", node.value);
            current_node = &node.next;
        }
        println!();
    }
}

pub fn list() {
    let mut l: List<i32> = List::new();

    l.insert(25);
    l.insert(2);
    l.insert(5);
    l.print_list();
}
