fn main()
{ use std::fmt;
  use std::ops::AddAssign;
  trait Geometric : fmt::Display
  { fn my_fmt(&self);
    fn display(&self); }
#[derive(Default, Copy, Clone)]
  struct Square
  { size: f32, }
  impl Square
  { fn new(s: f32) -> Self
    { Square
      { size: s, }}
    fn mul(&self) -> f32
    { self.size * 2.0 * 2.0 }}
  impl Geometric for Square
  { fn my_fmt(&self)
    { println!("{}", self.size); }
    fn display(&self)
    {}}
  impl fmt::Display for Square
  { fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result
    { write!(f, "{}", self.size) }}
  impl AddAssign for Square
  { fn add_assign(&mut self, _rhs: Square)
    { self.size = _rhs.size + self.size;
      println!("Adding!"); }}
  fn main()
  { //let s: Square = Square::new(1.0);
    let mut s = Square::new(2.);
    s.my_fmt();
    s += s;
    println!("{}", s); }}
