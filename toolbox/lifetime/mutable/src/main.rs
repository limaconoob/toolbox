struct Point
{ x: i32,
  y: i32, }

struct Bonjour<'a>
{ x: &'a mut i32,
  y: &'a mut i32, }

fn main()
{ let mut point = Point { x: 0, y: 0 };
  println!("point! x::{}, y::{}", point.x, point.y);
  { let r = Bonjour { x: &mut point.x, y: &mut point.y };
    *r.x = 5;
    *r.y = 6; }
  println!("point! x::{}, y::{}", point.x, point.y); }
