package main

import "fmt"

const age = 30

func main() {
	const (
		port int    = 8080
		name string = "Hello World"
	)

	fmt.Println(port, name, age)

}
