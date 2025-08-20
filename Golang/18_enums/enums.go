package main

import "fmt"

//enumerated types
type OrderStatus int

// type OrderStatus string

const (
	Received OrderStatus = iota
	Confirmed
	Prepared
	Delivered
	// Received OrderStatus = "recived"
	// Confirmed ="confirm"
	// Prepared = "prepared"
	// Delivered = "deliverd"
)

func changeOrderStatus(status OrderStatus) {
	fmt.Println("Changing order status to", status)
}

func main() {
	changeOrderStatus(Delivered)
}
