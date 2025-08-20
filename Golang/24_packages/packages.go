package main

import (
	"fmt"

	"github.com/codersgyan/podcast/GOLANG/24_packages/auth"
)

func main() {

	auth.LoginWithCredential("codersgeyan", "secret")

	session := auth.GetSession()
	fmt.Println("session", session)

	auth.GetSession()

	// user := user.User{
	// 	// Email: "user@email.com",
	// 	Name: "John doe",
	// }
	// fmt.Println("user", user.Email, user.Name)

	// color.Red(user.Name)
}
