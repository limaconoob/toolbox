struct Bonjour<'a> {
  x: Option<&'a Bonjour<'a>>,
}

impl<'a> Bonjour<'a> {
  fn new() -> Self {
     Bonjour {
       x: x,
     }
  }
}

fn main() {
}
