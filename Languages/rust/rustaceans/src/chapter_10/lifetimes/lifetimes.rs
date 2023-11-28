fn scope() {
    let r: &i32;

    {
        let x = 5;
        // r = &x; // o valor emprestado não dura o suficiente
    }

    // println!("r: {}", r); // emprestar mais tarde usado aqui
}

fn longest<'a>(str1: &'a str, str2: &'a str) -> &'a str {
    if str1.len() > str2.len() {
        str1
    } else {
        str2
    }
}

fn longest2<'a, 'b>(str1: &'a str, str2: &'b str) -> &'a str
where
    'b: 'a, // 'b dura pelo menos tanto quanto 'a
{
    if str1.len() > str2.len() {
        str1
    } else {
        str2
    }
}

fn longest3(str1: String, str2: String) -> String {
    if str1.len() > str2.len() {
        str1
    } else {
        str2
    }
}

fn str_ref() {
    // ----------- lifetime ------------
    let string1 = String::from("abcd");
    let string2 = "xyz";

    let result = longest(&string1.as_str(), &string2);
    println!("The longest string is {}", result);

    // ----- lifetime with ownership -----
    let str1 = String::from("test1");

    let r;
    {
        let str2 = String::from("test2");
        r = longest3(str1, str2); // r recebe a propriedade de str1
    }
    println!("The longest string is {}", r);

    // ----------- lifetime ------------
    // let str1 = String::from("test1");
    // let r;
    // {
    //     let str2 = String::from("test2");
    //     r = longest(&str1, &str2); // str2 não vive o suficiente
    // }
    // println!("The longest string is {}", r); // r não vive o suficiente
}

pub fn lifetimes() {}
