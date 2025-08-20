package main

import (
	"fmt"
	"time"
)

//send
// func processNum(numChan chan int) {

// 	for num := range numChan {
// 		fmt.Println("processing number ", num)
// 		time.Sleep(time.Second)
// 	}
// 	// fmt.Println("processing number ", <-numChan)
// }

//sun
// func sum(result chan int, num1 int, num2 int) {
// 	numResult := num1 + num2
// 	result <- numResult
// }

//goroutinee syncronizer

// func task(done chan bool) {
// 	defer func() { done <- true }()
// 	fmt.Println("Processing...")
// }

// queue system
func emailSender(emailChan chan string, done chan<- bool) {
	defer func() { done <- true }()

	for email := range emailChan {
		fmt.Println("sending email to", email)
		time.Sleep(time.Second)
	}
}

func main() {
	chan1 := make(chan int)
	chan2 := make(chan string)

	go func() {
		chan1 <- 10
	}()

	go func() {
		chan2 <- "pong"
	}()

	for i := 0; i < 2; i++ {
		select {
		case chan1Val := <-chan1:
			fmt.Println("recived data from chan1", chan1Val)

		case chan2Val := <-chan2:
			fmt.Println("received data from chan2", chan2Val)

		}
	}

	// //buffer channel, queue
	// emailChan := make(chan string, 100)
	// done := make(chan bool)

	// go emailSender(emailChan, done)

	// for i := 0; i < 100; i++ {
	// 	emailChan <- fmt.Sprintf("%d@gmail.com", i)
	// }

	// fmt.Println("done sending")

	// // this is important
	// close(emailChan)
	// <-done
	// emailChan <- "1@gmail.com"
	// emailChan <- "2@gamil.com"

	// fmt.Println(<-emailChan)
	// fmt.Println(<-emailChan)

	// done := make(chan bool)
	// go task(done)

	// <-done // block

	//sum
	// result := make(chan int)
	// go sum(result, 4, 5)
	// res := <-result
	// fmt.Println(res)

	// numChan := make(chan int)
	// go processNum(numChan)
	// for {
	// 	numChan <- rand.Intn(100)
	// }
	// time.Sleep(time.Second * 2)

	// messageChan := make(chan string)
	// messageChan <- "ping" //blocking
	// msg := <-messageChan
	// fmt.Println(msg)

}
