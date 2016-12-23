#[macro_use] extern crate itertools;

use itertools::Itertools;

fn main()
{ (0..5).foreach(|x|
  { println!("{}", x) }); }
