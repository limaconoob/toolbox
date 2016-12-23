/*
trait Foo {
      fn f(&self);
}

trait Bar {
      fn f(&self);
}

struct Baz;

impl Foo for Baz {
      fn f(&self) { println!("Baz’s impl of Foo"); }
}

impl Bar for Baz {
      fn f(&self) { println!("Baz’s impl of Bar"); }
}

let b = Baz;

   impl<T: PartialEq> Rectangle<T> {
   fn is_square(&self) -> bool {
   self.width == self.height
   }
*/

trait Robot
{ fn energy(&self) -> i32
  { 40 }}

trait Mecano : Robot
{ fn speak(&self)
  { println!("Mecano!"); }}

trait Android : Robot
{ fn speak(&self)
  { println!("Android!"); }
  fn kill(&self)
  { println!("Kill!"); }}

struct Me;

impl Robot for Me {}
impl Android for Me {}
impl Mecano for Me {}

trait Animal
{ fn age(&self)
  {}}

trait Cat : Animal
{ fn speak(&self)
  { println!("Cat!"); }
  fn despise(&self)
  { println!("Despise!"); }}

trait Wolf : Animal
{ fn speak(&self)
  { println!("Wolf!"); }
  fn friend(&self)
  { println!("Friend!"); }}

struct Neko;

impl Animal for Neko {}
impl Cat for Neko {}

// bonjour = Robot
// neko = Cat
fn main()
{ println!("bonjour == ROBOT");
  let bonjour: Me = Me{};
  println!("Energy = {}!", bonjour.energy());
  Mecano::speak(&bonjour);
  Android::speak(&bonjour);
  bonjour.kill();
  println!("\nneko == CAT");
  let neko: Neko = Neko{};
  neko.age();
  neko.speak();
  neko.despise(); }
