use closures::{Inventory, ShirtColor};

pub fn main() {
  let store = Inventory {
    shirts: vec![ShirtColor::Red, ShirtColor::Blue],
  };

  let user_pref = Some(ShirtColor::Red);
  let shirt = store.giveway(user_pref);
  println!(
    "Store: {:?} - User pref: {:?} - Shirt: {:?}",
    store.shirts, user_pref, shirt
  );

  let user_pref = None;
  let shirt = store.giveway(user_pref);
  println!(
    "Store: {:?} - User pref: {:?} - Shirt: {:?}",
    store.shirts, user_pref, shirt
  );
}
