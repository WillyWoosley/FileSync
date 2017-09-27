use std::collections::HashMap;
use std::io;
use std::process::exit;

enum Command {
    Add(Option<(String, String)>),
    List,
    Quit,
}

impl Command {
    fn process(self, database: &mut HashMap<String, String>) {
        match self {
            Command::Quit                          => {
                exit(0);
            },
            Command::List                          => {
                println!("Employee Name : Occupation");
                for (key, val) in database {
                    println!("{} : {}", key, val);
                }
            },
            Command::Add(None)                     => {
                println!("The \"add\" command must take the form \"add EMPLOYEE_NAME DEPARTMENT_NAME\"");
            },
            Command::Add(Some((name, department))) => {
                if database.contains_key(&name) {
                    println!("That individual was listed as employed at: {}", database[&name]);
                    println!("Their entry has been updated");
                    database.insert(name, department);
                } else {
                    println!("New employee added");
                    database.insert(name, department);
                }
            },
        }
    }

    fn parse_add(line: &str) -> Option<(String, String)> {
        let args: Vec<&str> = line.split_whitespace().collect();
        
        if args.len() != 2 {
            None
        } else {
            Some((args[0].to_string(), args[1].to_string()))
        }
    }
}

fn main() {
    let mut map: HashMap<String, String> = HashMap::new();
    println!("Type \"add EMPLOYEE_NAME DEPARTMENT_NAME\" to add employees");
    println!("Type \"list\" to list the current contents of the database");
    println!("Type \"quit\" to quit");    
    
    loop {
        let mut line = String::new();

        io::stdin().read_line(&mut line)
            .expect("Failed to read line");

        let input = match &line[0..4].trim().to_lowercase().as_ref() {
             &"quit" => Command::Quit,
             &"list" => Command::List,
             &"add"  => Command::Add(Command::parse_add(&line[4..line.len()-1])),
             _       => continue,
        };

        input.process(&mut map);
    }

}
