struct Bonjour<'a>
{ x: &'a i32, }

impl<'a> Bonjour<'a>
{ fn x(&self) -> &'a i32
  { self.x }}

fn main()
{ let y = &5;
  let f = Bonjour{ x: y };
  println!("x is: {}", f.x()); }
