use std::thread;
pub struct ThreadPool {
    pub threads: Vec<thread::JoinHandle<()>>,
}

#[derive(Debug)]
pub enum PoolThreadError {
    UnavailableThreads,
}

impl ThreadPool {
    pub fn build(size: usize) -> Result<ThreadPool, PoolThreadError> {
        if size == 0 {
            return Err(PoolThreadError::UnavailableThreads);
        }
        let mut threads = Vec::with_capacity(size);
        for _ in 0..size {
            let thread = thread::spawn(|| {
                println!("Thread spawned!");
            });
            threads.push(thread);
        }
        Ok(ThreadPool { threads })
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
        let thread = thread::spawn(f);
        self.threads.push(thread);
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
