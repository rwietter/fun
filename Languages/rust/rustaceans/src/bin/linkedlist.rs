use std::{cell::RefCell, fmt::Debug, rc::Rc};

/**
 * A doubly linked list in rust normally needs clone because next or prev are moved. Clone works, but have high memory cost.
 * So, we need that the next and prev are shared ownership. We can use Rc<T> or Arc<T>. In other words, we can have two or more owners.
 * For values in stack, we have just one owner. For values in heap, we can have two or more owners using smart pointers.
 * However, Box is single ownership. So, we need Rc<T> (Reference Counting), Rc are immutable. Box clone the value, Rc clone the pointer at the stack.
 *
 * So, as Rc is immutable, we can't sign a new value to next or prev. Because of that, we need Interior Mutability Pattern.
 * Interior Mutability Pattern: ability to mutate data even when there are immutable references to that data. So, we can to use RefCell<T>.
 *
 * ref.borrow() -> get a immutable reference to the value.
 * ref.borrow_mut() -> get a mutable reference of the Node.
 * RefCell can be used with Rc<T>.
 */

#[derive(Debug)]
struct Node<T> {
    data: T,
    next: Option<Rc<RefCell<Node<T>>>>,
    prev: Option<Rc<RefCell<Node<T>>>>,
}

impl<T: Debug> Node<T> {
    fn new(
        data: T,
        next: Option<Rc<RefCell<Node<T>>>>,
        prev: Option<Rc<RefCell<Node<T>>>>,
    ) -> Self {
        Node { data, next, prev }
    }
}

fn main() {
    let a = Rc::new(RefCell::new(Node::new(1, None, None)));
    let b = Rc::new(RefCell::new(Node::new(2, Some(a), None)));
    let c = Rc::new(RefCell::new(Node::new(3, None, Some(b))));

    println!(
        "1 == {:?}",
        c.borrow()
            .prev
            .as_ref()
            .unwrap()
            .borrow()
            .next
            .as_ref()
            .unwrap()
            .borrow()
            .data
    );
    println!("2 == {:?}", c.borrow().prev.as_ref().unwrap().borrow().data);
    println!("3 == {:?}", c.borrow().data);

    let d = Rc::new(RefCell::new(Node::new(4, None, None)));
    c.borrow_mut().next = Some(d);

    println!("{:?}", c);
}
