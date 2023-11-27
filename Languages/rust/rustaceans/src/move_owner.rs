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
