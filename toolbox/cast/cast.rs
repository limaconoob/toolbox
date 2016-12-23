
fn main()
{ let a: u64 = 4294967295;
  let b = if a > std::u32::MAX as u64
  { None } 
  else
  { Some(a as u32) };
  println!("{} -> {}", a, b.unwrap()); }
