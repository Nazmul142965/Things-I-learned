package main

import "fmt"

// func changeNum(num int) {
// 	num = 5
// 	fmt.Println("In changeNum", num)
// }

//by reference
func changeNum(num *int) {
	*num = 5
	fmt.Println("In changeNum", *num)
}
func main() {
	num := 1

	changeNum(&num)
	fmt.Println("Memeor address", &num)
	fmt.Println("In main", num) // Output: 1
}
