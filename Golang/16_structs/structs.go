package main

import (
	"fmt"
	"time"
)

//order struct

type customer struct {
	name  string
	phone string
}

// composition
type order struct {
	id        string
	amount    float32
	status    string
	createdAt time.Time // nenosecond  precision
	customer            // embedded struct
}

// constractor
func newOrder(id string, amount float32, status string) *order {
	//initializing struct with values
	myOrder3 := order{
		id:     id,
		amount: amount,
		status: status,
	}
	return &myOrder3
}

// reciver type
func (o *order) changeStatus(status string) {
	o.status = status
}

func (o order) getAmount() float32 {
	return o.amount
}

// main function
func main() {
	// newCustomer := customer{
	// 	name:  "John Doe",
	// 	phone: "123-456-7890",
	// }
	newOrder4 := order{
		id:     "4",
		amount: 150.75,
		status: "new",
		customer: customer{
			name:  "Jane Smith",
			phone: "987-654-3210",
		}, // embedding customer struct

	}

	fmt.Println("Order struct", newOrder4)

	//if you want to create to use it one time
	language := struct {
		name   string
		isGood bool
	}{"golang", true}
	fmt.Println("Language struct", language)

	//if you don't set any field, default value is zero value
	//int => 0, string => "", float => 0.0, bool => false, time.Time => zero time
	myOrder := order{
		id:     "1",
		amount: 100.50,
		status: "pending",
	}

	myOrder.changeStatus("completed")
	myOrder.getAmount() // call method to get amount

	myOrder.createdAt = time.Now() // set the current time
	fmt.Println("Order struct", myOrder)

	myOrder2 := order{
		id:        "2",
		amount:    200.75,
		status:    "completed",
		createdAt: time.Now(),
	}

	myOrder2.status = "shipped" // update status

	fmt.Println("Order struct", myOrder2)

	myOrder3 := newOrder("3", 300.00, "processing") // using constructor
	fmt.Println("Order struct", myOrder3)
	myOrder3.changeStatus("delivered") // change status using method

}
