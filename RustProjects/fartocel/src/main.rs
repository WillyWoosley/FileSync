use std::io;

fn main() {
    loop {
        let mut temp = String::new();
        let mut system = String::new();

        println!("Please input the temperature you wish to convert");
        io::stdin().read_line(&mut temp)
            .expect("Couldn't read line");

        let temp: i32 = match temp.trim().parse() {
            Ok(num) => num,
            Err(_)  => {
                println!("Please input a valid temeprature");
                continue
            },
        };


        println!("Is this measurement in celsius or farneheit? [cel/far]");
        io::stdin().read_line(&mut system)
            .expect("Couldn't read line");

        let cel;

        match system.trim().as_ref() {
            "far" => cel = false,
            "cel" => cel = true,
            _     => { 
                println!("Please enter either cel or far");
                continue 
            },
        }


        if cel {
            println!("Temperature in farenheit: {}", celtofar(temp));
            break;
        } else {
            println!("Temeprature in celsius: {}", fartocel(temp));
            break;
        }

        

    }
}

fn celtofar(cel: i32) -> f32 {
    (cel as f32) * 1.8 + 32.0
}

fn fartocel(far: i32) -> f32 {
    ((far - 32) as f32) * 0.5556
}
