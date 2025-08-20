package main

import "fmt"

func add(a, b int) int {
	return a + b
}

func getLanguages() (string, string, string) {
	return "golang", "python", "java"
}

// func processIt(fn func(a int) int) {
// 	fn(1)
// }

func processIt() func(a int) int {
	return func(a int) int {
		return 4
	}
}

func main() {
	result := add(3, 5)
	fmt.Println(result)

	lang1, lang2, lang3 := getLanguages()
	fmt.Println(lang1, lang2, lang3)

	// fn := func(a int) int {
	// 	return 2
	// }
	// fn := processIt()
	// fn(6)

}
