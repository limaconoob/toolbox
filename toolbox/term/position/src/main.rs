
use std::io::{stdout, stdin};
use std::io::prelude::*;

fn main()
{ let stdin = stdin();
  print!("\x1B[6n\n");
  let mut ret = [0; 1];
  let mut buf: Vec<u8> = Vec::new();
  loop
  { stdin.lock().read(&mut ret);
    buf.push(ret[0]); 
    if ret[0] == 97
    { break; }}
  for k in buf
  { print!("[{}], ", k); }}
