#[derive(Debug)]
struct Node<T> {
    data: T,
    next: Option<Box<Node<T>>>,
}

impl<T: std::fmt::Debug> Node<T> {
    fn new(data: T, next: Option<Box<Node<T>>>) -> Self {
        Node { data, next }
    }

    fn show(node: Node<T>) {
        println!("{:?}", node.data);
        match node.next {
            Some(n) => Node::show(*n),
            None => (),
        }
    }
}

fn main() {
    let a = Node::new(1, None);
    let b = Node::new(2, Some(Box::new(a)));
    let c = Node::new(3, Some(Box::new(b)));

    Node::show(c);
}
