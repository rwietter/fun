fn getmaxvalue(array: &mut [i32], _length: i32) -> i32 {
  let maxValue: i32 = array[0];
  println!("{}", maxValue);
  for elem in 0..array.len() {
    println!("{}", elem);
  }
  return maxValue;
}

fn radixsort(array: &mut [i32], _length: i32){
  let maxValue = getmaxvalue(&mut array, _length);
  println!("{:?}", maxValue);
}

fn main(){
  let mut array: [i32; 3] = [15, 5, 19];
  radixsort(&mut array, 3);
}
// let foo: f32 = x as f32;
