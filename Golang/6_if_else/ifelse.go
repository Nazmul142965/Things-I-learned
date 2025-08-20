package main

import "fmt"

func main() {
	age := 8

	if age < 18 {
		fmt.Println("You are a minor.")
	} else if age >= 18 && age < 60 {
		fmt.Println("You are a senior citizen.")
	} else {
		fmt.Println("You are a child.")
	}

	var role = "Admin"
	var hasPermission = true
	if role == "Admin" && hasPermission {
		fmt.Println("You have admin access.")
	}

	//we can  declare a variable inside if statement
	if age := 18; age >= 18 {
		fmt.Println("You are an adult.", age)
	} else if age >= 12 {
		fmt.Println("You are not an adult.", age)
	}

}
