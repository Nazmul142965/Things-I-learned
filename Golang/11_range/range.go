package main

import "fmt"

//iterating over data structres
func main() {
	nums := []int{6, 7, 8}

	for i := 0; i < len(nums); i++ {
		fmt.Println(nums[i])
	}

	sum := 0
	for i, v := range nums {

		fmt.Println(v, i)
		sum = sum + v
	}

	fmt.Println("Sum:", sum)

	//map
	m := map[string]string{"frame": "john", "lname": " wick"}
	for k, v := range m {
		fmt.Println(k, v)
	}

	//unicode code point rune
	//starting bytes of rune
	//255-> 1 byte, 2 bytes
	for i, c := range "Golang" {
		// fmt.Println(i, c)
		fmt.Println(i, string(c)) // converting rune to string
	}

}
