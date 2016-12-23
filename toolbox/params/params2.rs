// https://doc.rust-lang.org/getopts/getopts/

use std::env;

for argument in env::args() 
{ println!("{}", argument); }
