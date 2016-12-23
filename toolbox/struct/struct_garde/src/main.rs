struct Point
{ x: i32,
  y: i32, }

fn move_origin(origin:&mut Point)
{ origin.x += 2;
  origin.y += 4; }

fn main()
{ let ref mut origin = Point { x: 0, y: 0 };
  move_origin(origin);
  println!("x::{}, y::{}", origin.x, origin.y); }
