struct HasDrop;

impl HasDrop
{ fn new() -> Self 
  { println!("constructor");
    HasDrop }}

impl Drop for HasDrop
{ fn drop(&mut self)
  { println!("Dropping!"); }}

fn main() 
{ { let _x = HasDrop::new(); }
  println!("line"); }
