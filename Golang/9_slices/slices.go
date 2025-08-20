package main

import (
	"fmt"
	"slices"
)

// slices -> dynamic
//most used construct in go
// + userful methods

func main() {
	// uninsitialized slice is nil

	var nams []int
	fmt.Println(nams)

	fmt.Println(nams == nil)

	fmt.Println(len(nams))

	var nums = make([]int, 0, 5)
	fmt.Println(nums)
	fmt.Println(nums == nil)
	//capacity -> maximum numbers of elements can fit
	fmt.Println(cap(nums))

	//add elements
	nums = append(nums, 1)
	nums = append(nums, 2)
	nums = append(nums, 3)
	nums = append(nums, 4)
	nums = append(nums, 5)
	nums = append(nums, 6)
	nums = append(nums, 7)
	nums = append(nums, 8)
	nums = append(nums, 9)
	nums = append(nums, 10)

	fmt.Println(nums)
	fmt.Println(cap(nums))

	nums2 := []int{}
	nums2 = append(nums2, 1, 2, 3, 4, 5)
	fmt.Println(nums2)
	fmt.Println(cap(nums2))
	fmt.Println(len(nums2))

	//copy function
	var nums3 = make([]int, 0, 5)
	nums3 = append(nums3, 3)
	var nums4 = make([]int, len(nums3))

	copy(nums4, nums3)

	fmt.Println(nums3, nums4)

	//slice operator
	var nums5 = []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	fmt.Println(nums5[2:5]) // from index 2 to 4

	//slice pacakge
	var nums6 = []int{1, 2, 3}
	var nums7 = []int{1, 2, 4}

	fmt.Println(slices.Equal(nums6, nums7))

	//2d slices
	var nums8 = [][]int{{1, 2, 3}, {4, 5, 6}}
	fmt.Println(nums8)

}
