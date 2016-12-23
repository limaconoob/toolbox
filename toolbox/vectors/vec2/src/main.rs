
fn main()
{ let mut vec2d: Vec<Vec<u8>> = Vec::new();
  let row: u32 = 1;
  let col: u32 = 2;
  let mut i = 0;
  let mut j;
  while i < 4
  { let mut rowvec: Vec<u8> = Vec::new();
    j = 0;
    while j < 4 
    { rowvec.push(j as u8); 
      println!("{}, {}", i, j);
      j+=1; }
    vec2d.push(rowvec);
    i+=1; }
  println!("[{}]",vec2d[row as usize][col as usize]); }
