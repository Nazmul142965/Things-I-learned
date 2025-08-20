package main

import (
	"fmt"
	"maps"
)

// maps-> hash, object, dict
func main() {
	//creating map

	m := make(map[string]string)
	//settng an element
	m["name"] = "golang"
	m["area"] = "backend"
	//getting a an element
	fmt.Println(m["name"], m["area"])
	fmt.Println(len(m))
	fmt.Println(m)

	//deleting an element
	delete(m, "area")
	fmt.Println(m)

	clear(m)
	fmt.Println(m)

	n := map[string]int{"price": 40, "phone": 30}
	fmt.Println(n)

	k, ok := n["phone"]
	fmt.Println(k)
	if ok {
		fmt.Println("name exists in map")
	} else {
		fmt.Println("name does not exist in map")
	}

	//cross checking
	c1 := map[string]int{"price": 40, "phone": 30}
	c2 := map[string]int{"price": 40, "phone": 30}

	fmt.Println(maps.Equal(c1, c2))
}
