struct User {
    username: String,
    email: String,
    sign_in_count: u64,
    active: bool,
}

struct Color(i32, i32, i32);
struct Point(i32, i32, i32);

fn main() {
    let mut user1 = User {
        email: String::from("someone@example.com"),
        username: String::from("someusername123"),
        active: true,
        sign_in_count: 1,
    };

    user1.email = String::from("anotheremail@example.com");

    let user2_email = String::from("email@corporation.com");
    let user2_name = String::from("Joe Shmoe");

    let user2 = build_user(user2_email, user2_name);

    let user3 = User {
        email: String::from("onemoreemail@example.com"),
        username: String::from("adifuser123"),
        ..user1
    };

    let black = Color(0, 0, 0);
    let origin = Point(0, 0, 0);
}

fn build_user(email: String, username: String) -> User {
    
    //If variables have the same name as struct fields, they can be used
    //without directly stating which field they belong to
    User {
        email,
        username,
        active: true,
        sign_in_count: 1,
    }
}
