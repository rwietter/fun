use std::sync::{Arc, Mutex};

fn main() {
    let queue = Arc::new(Mutex::new(Vec::new()));

    queue.lock().unwrap().push(1);
    queue.lock().unwrap().push(2);

    let worker_queue = queue.clone();

    let handle = std::thread::spawn(move || {
        process_queue(worker_queue);
    });

    queue.lock().unwrap().push(3);

    handle.join().unwrap();
}

fn process_queue(queue: Arc<Mutex<Vec<i32>>>) {
    loop {
        let len = queue.lock().unwrap().len();
        match len {
            0 => break,
            _ => {
                let mut queue = queue.lock().unwrap();
                let item = queue.remove(0);
                println!("item: {}", item);
            }
        }
    }
}
