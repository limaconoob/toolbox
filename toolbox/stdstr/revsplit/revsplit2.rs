fn revsplit(msg: &str)
{ let bonjour = msg.split(' ').collect::<Vec<&str>>();
  for i in bonjour.iter()
  { if *i != "" 
	  { print!("{} ", i); }}
  let connard = bonjour.iter().rev();
  for i in connard
  { if *i != ""
    { print!("{} ", i); }}}

fn main() 
{ let msg = "J'aime les        espaces     !";
	revsplit(msg); }

