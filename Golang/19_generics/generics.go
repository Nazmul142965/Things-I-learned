package main

import "fmt"

// unc printSlice[T comparable](items []T, name v)//we can use multythings
// unc printSlice[T comparable](items []T) //using this to camapre automately, and decides it self
//func printSlice[T int | string](items []T)
//func printSlice[T interface](items []T)
func printSlice[T any](items []T) { //any is bad practice
	for _, item := range items {
		// fmt.Println(item, name)
		fmt.Println(item)
	}
}

// type Stack struct {
// 	elements []int
// }

type stack[T any] struct {
	elements []T
}

// func printStringSlice(items []string) {
// 	for _, item := range items {
// 		fmt.Println(item)
// 	}
// }

func main() {

	myStack := stack[string]{
		elements: []string{"Golang", "java"},
	}
	fmt.Println(myStack)

	// myStack := Stack{
	// 	elements: []int{1, 2, 3},
	// }

	// fmt.Println(myStack)

	printSlice([]int{1, 2, 3})
	// printStringSlice([]string{"golang", "tyepScript"})
	names := []string{"golang", "typeScript"}
	printSlice(names)
}
