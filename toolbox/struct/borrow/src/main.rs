struct TheDarkKnight;

impl TheDarkKnight
{ fn nothing_is_true(self) {}}

struct Batcave
{ knight: TheDarkKnight }

fn main()
{ use std::mem;
  let mut cave = Batcave
  { knight: TheDarkKnight };
  let borrowed = &mut cave;
//  borrowed.knight.nothing_is_true(); // E0507
  mem::replace(&mut borrowed.knight, TheDarkKnight).nothing_is_true(); // ok!
}
