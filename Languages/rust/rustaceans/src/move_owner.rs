use std::thread;

/*
 * move_owner.rs
 * -------------
 * Demonstrates how closures can take ownership of variables. Just Heap allocated variables; the stack allocated variables are copied.
 * This is useful when you want to move a variable into a closure.
 * This is especially useful when you want to use a closure to spawn a new thread.
 *
*/
pub fn move_owner() {
    let v = vec![1, 2, 3];
    let something = Box::new(4);

    let captured = move || {
        println!("v: {:?}", v);
        println!("slice: {:?}", something);
    };

    captured();

    // println!("something: {:?}", something); // error: use of moved value: `slice`
    // println!("v: {:?}", v); // error: use of moved value: `v`

    let one = 1;
    let cb = || one;
    cb();
    println!("Copied: {:?}", one);
}

/**
 * Neste exemplo, estamos criando uma thread que itera sobre um vetor de números (data).
 * A closure passada para a função thread::spawn captura a variável data usando move, o que
 * significa que a propriedade do vetor é movida para a closure. Isso permite que a thread
 * utilize o vetor independentemente do tempo de vida da função main.
 */
fn cb_thread() {
    let data = vec![1, 2, 3, 4, 5];

    // Criando uma thread que captura a variável `data` por movimento
    let thread_handle = thread::spawn(move || {
        for &num in &data {
            println!("Número: {}", num);
        }
    });

    // Esperando que a thread termine sua execução
    thread_handle.join().unwrap();
}

/**
 * Neste exemplo, temos um EventListener que pode manipular eventos. O método handle_event
 * recebe uma callback que será chamada quando um evento ocorrer. A closure passada para
 * handle_event captura a variável message por move, permitindo que ela a utilize dentro
 * da closure, mesmo que a função main tenha sido encerrada.
 */
struct EventListener {
    // Algum estado do ouvinte de eventos
}

impl EventListener {
    fn handle_event(&self, callback: Box<dyn Fn() + 'static>) {
        // Simulando a ocorrência de um evento
        // Quando o evento acontece, a callback é chamada
        callback();
    }
}

fn events() {
    let listener = EventListener {};

    let message = "Evento ocorreu!";

    // Usando uma closure com 'move' como callback para o evento
    listener.handle_event(Box::new(move || {
        println!("{}", message);
    }));
}
