package main

import (
	"fmt"
)

type paymenter interface {
	pay(amount float32)
	refund(amount float32, accountNumber string)
}

type payment struct {
	// gateway stripe
	// gateway razorpay
	gateway paymenter
}

// open close principle
func (p payment) makepayment(amount float32) {
	// razorpayPaymentGw := razorpay{}
	// razorpayPaymentGw.pay(amount)
	// stripePaymentGw := stripe{}
	// stripePaymentGw.pay(amount)
	p.gateway.pay(amount)
}

type razorpay struct{}

func (r razorpay) pay(amount float32) {
	//logic to make paymnet
	fmt.Println("making payment using razorpay", amount)
}

type stripe struct{}

func (s stripe) pay(amount float32) {
	fmt.Println("making payment using stripe", amount)
}

type fakepayment struct{}

func (f fakepayment) pay(amount float32) {
	fmt.Println("making payment using gateway for testing prupose")
}

type paypal struct{}

func (p paypal) pay(amount float32) {
	fmt.Println("Making payment using paypal", amount)
}

func (p paypal) refund(amount float32, accountNumber string) {}

func main() {
	// stripePaymentGw := stripe{}
	// razorpayPaymentGw := razorpay{}
	// fakeGw := fakepayment{}
	paypalGw := paypal{}

	newPayment := payment{
		// gateway: stripePaymentGw,
		// gateway: razorpayPaymentGw,
		// gateway: fakeGw,
		gateway: paypalGw,
	}
	newPayment.makepayment(100)

}
