
fn revsplit(msg: &str)
{ let bonjour = msg.split(' ');
	let connard = bonjour.clone().rev();
	for i in connard
	{ if i != "" 
		{ print!("{} ", i); }}}

fn main()
{ let msg = "J'aime les        espaces     !";
	revsplit(msg); }

