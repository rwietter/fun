use std::{
    sync::{mpsc, Arc, Mutex},
    thread,
};

#[derive(Debug)]
pub enum PoolThreadError {
    UnavailableThreads,
}

struct Worker {
    id: usize,
    thread: Option<thread::JoinHandle<()>>,
}

pub struct ThreadPool {
    pub workers: Vec<Worker>,
    sender: Option<mpsc::Sender<Job>>,
}

type Job = Box<dyn FnOnce() + Send + 'static>;

impl Worker {
    pub fn new(id: usize, receiver: Arc<Mutex<mpsc::Receiver<Job>>>) -> Worker {
        let thread = thread::spawn(move || loop {
            let message = receiver.lock().unwrap().recv();

            match message {
                Ok(jon) => {
                    println!("Worker {} got a job; executing.", id);
                    jon();
                }
                Err(_) => {
                    println!("Worker {id} disconnected; shutting down.");
                    break;
                }
            }
        });

        Worker {
            id,
            thread: Some(thread),
        }
    }
}

impl ThreadPool {
    pub fn build(size: usize) -> Result<ThreadPool, PoolThreadError> {
        if size == 0 {
            return Err(PoolThreadError::UnavailableThreads);
        }
        let (sender, receiver) = mpsc::channel();
        let receiver = Arc::new(Mutex::new(receiver));
        let mut workers = Vec::with_capacity(size);
        for id in 0..size {
            workers.push(Worker::new(id, Arc::clone(&receiver)));
        }
        Ok(ThreadPool {
            workers,
            sender: Some(sender),
        })
    }

    pub fn new(thread_pool: Result<ThreadPool, PoolThreadError>) -> ThreadPool {
        match thread_pool {
            Ok(pool) => pool,
            Err(e) => {
                panic!("Failed to create thread pool: {:?}", e);
            }
        }
    }

    pub fn execute<F>(&mut self, f: F)
    where
        F: FnOnce() + Send + 'static,
    {
        let job = Box::new(f);
        self.sender.as_ref().unwrap().send(job).unwrap();
    }
}

// ---------------------------------
// Graceful shutdown and cleanup
// ---------------------------------

impl Drop for ThreadPool {
    fn drop(&mut self) {
        drop(self.sender.take()); // A eliminação do sender fecha o canal, o que indica que nenhuma outra mensagem será enviada.
        for worker in &mut self.workers {
            println!("Shutting down worker {}", worker.id);
            if let Some(thread) = worker.thread.take() {
                thread.join().unwrap();
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        assert_eq!(4, 4);
    }
}
