use std::fmt::{self, Display, Write};

/// Concatenate display of the contents
struct Concat<T>(pub T);

impl<A, B, C> Display for Concat<(A, B, C)>
where A: Display, B: Display, C: Display,
{
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        let t = &self.0;
        write!(f, "{}{}{}", t.0, t.1, t.2)
    }
}

fn join<T>(sep: &str, iter: T) -> String
where T: IntoIterator,
      T::Item: Display,
{
    let mut out = String::new();
    let mut iter = iter.into_iter();
    if let Some(fst) = iter.next() {
        write!(&mut out, "{}", fst).unwrap();
        for elt in iter {
            write!(&mut out, "{}{}", sep, elt).unwrap();
        }
    }
    out
}

fn main() {
    let set = [("one", "one"),
    ("two", "two"),
    ("three", "three"),
    ("four", "four")];

    let out = join(",", set.iter().map(|&(l, r)| Concat((l, ':', r))));
    println!("{:?}", out);
}
