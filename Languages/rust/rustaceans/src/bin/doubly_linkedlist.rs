use std::{
    cell::RefCell,
    rc::{Rc, Weak},
};

struct Node<T> {
    data: T,
    next: Option<Weak<RefCell<Node<T>>>>,
    prev: Option<Rc<RefCell<Node<T>>>>,
}

impl<T> Node<T> {
    fn new(
        data: T,
        next: Option<Weak<RefCell<Node<T>>>>,
        prev: Option<Rc<RefCell<Node<T>>>>,
    ) -> Self {
        Node { data, next, prev }
    }
}

fn main() {
    let a = Some(Rc::new(RefCell::new(Node::new(1, None, None))));
    let b = Node::new(2, None, a);
}
