
fn third_last_vowel(input: &str) -> Option<char> {
    let is_vowel = |c: &char|
        matches!(c, 'a' | 'e' | 'i' | 'o' | 'u' | 'y');
    input.chars().rev().filter(is_vowel).nth(2)
}

fn main() {
    let input = String::from("Hi, hello world");
    println!("{}", third_last_vowel(input.as_str()).unwrap());
}
