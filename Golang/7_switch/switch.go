package main

import (
	"fmt"
)

func main() {
	// simple switch statement
	// i := 2
	// switch i {
	// case 1:
	// 	fmt.Println("one")
	// case 2:
	// 	fmt.Println("two")
	// case 3:
	// 	fmt.Println("three")
	// default:
	// 	fmt.Println("other")
	// }

	//multiple condistion switch

	// 	switch time.Now().Weekday() {
	// 	case time.Saturday, time.Sunday:
	// 		fmt.Println("It's the weekend!")
	// 	default:
	// 		fmt.Println("It's a weekday.")
	// 	}

	//type switch

	whoAmI := func(i interface{}) {
		switch i.(type) {
		case int:
			fmt.Println("I am an int")
		case string:
			fmt.Println("I am a string")
		case bool:
			fmt.Println("I am a bool")
		default:
			fmt.Println("I don't know what I am")
		}
	}

	whoAmI(42)
	whoAmI("hello")
	whoAmI(true)

}
