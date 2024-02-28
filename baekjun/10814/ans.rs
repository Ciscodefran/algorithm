use std::io::{self, BufWriter, Write};

struct Person {
    age: i32,
    name: String,
}

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace();
    let n = input.next().unwrap().parse().unwrap();
    let mut persons: Vec<Person> = Vec::new();
    for _ in 0..n {
        let age = input.next().unwrap().parse().unwrap();
        let name = input.next().unwrap().to_string();
        persons.push(Person { age, name });
    }
    persons.sort_by(|a, b| a.age.cmp(&b.age));
    let mut out = BufWriter::new(io::stdout());
    persons.iter().for_each(|p| {
        writeln!(out, "{} {}", p.age, p.name).unwrap();
    });
}
