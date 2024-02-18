fn sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
    for (index, item) in nums.iter().enumerate() {
        match nums.get(index + 1) {
            Some(v) => {
                if item + v == target {
                    return vec![index as i32, (index + 1) as i32];
                }
            }
            None => return vec![0, 0],
        }
    }
    vec![0, 0]
}

pub fn two_sum() {
    let vector = vec![2, 7, 11, 15];
    let _r1 = sum(vector, 9);
    let vector = vec![3, 2, 4];
    let _r2 = sum(vector, 6);
    let vector = vec![3, 3];
    let _r3 = sum(vector, 6);
    let vector = vec![3, 2, 3];
    let _r4 = sum(vector, 6);
    // dbg!(r1, r2, r3, r4);
}
