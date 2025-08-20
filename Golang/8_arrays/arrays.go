package main

import "fmt"

//number sequence of specific length
func main() {
	var nums [4]int

	nums[0] = 1

	fmt.Println(nums[0])
	//values na thakle zero assign koira dey
	fmt.Println(nums)
	//array length
	// fmt.Println(len(nums))

	//boolean er khetre false assign koira dey
	var vals [4]bool
	vals[2] = true
	fmt.Println(vals)

	//string er khetre empty string assign koira dey
	var name [3]string
	name[0] = "Alice"
	fmt.Println(name)

	//to declare in a single line
	nums2 := [4]int{1, 2, 3, 4}
	fmt.Println(nums2)

	//2d array
	nums3 := [2][2]int{{2, 3}, {5, 6}}
	fmt.Println(nums3)

	//- fixed size , that is predicatable
	// - Memory optimization
	// - Constant time access

}
