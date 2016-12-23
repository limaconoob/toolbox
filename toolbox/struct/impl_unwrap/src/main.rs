struct Hello
{ foo: i32 }

impl Default for Hello
{ fn default() -> Self
  { Hello
    { foo: 42i32 }}}

//impl std::fmt::Display for Hello 
//{ fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result
//  { write!(f, "{}", self.foo) }}

//Option -> Some(T) | None, Result -> Ok(T) | Err(String)
fn main()
{ let x: Option<Hello> = Some(Hello {foo: 1i32});
  let y: Hello = Default::default();
  println!("{}", x.unwrap_or_default());
  println!("{}", y); }
