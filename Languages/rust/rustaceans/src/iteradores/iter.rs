pub fn iterator_sum() {
    let v1 = vec![1, 2, 3];

    let v1_iter = v1.iter();

    // Sum is a consuming adaptor, because it takes ownership of the iterator it is called on.
    let total: i32 = v1_iter.sum();
    println!("Total: {}", total);
    // println!("v1_iter: {:?}", v1_iter); // borrow of moved value: `v1_iter`
}

pub fn iter_adaptors() {
    let v = vec![1, 2, 3];
    let result = v.iter().map(|x| x + 1).filter(|x| x > &2);
    let r: Vec<i32> = result.collect();
    println!("Result: {:?}", r);
}
