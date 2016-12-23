
fn test_vec()
{ let mut v = vec![0; 10];
  let mut i = 0;
  let mut k = 0;
  while i < 10
  { v[i] = k;
    println!("{}", v[i]);
    i+=1;
    k+=1; }}
 
//let v = vec![1, 2, 3, 4, 5];

//let n: i32 = 10;
//let mut v = Vec::<i16>::with_capacity(n as usize);

//let v = vec![0; 10]; // ten zeroes

fn main()
{ test_vec(); }
