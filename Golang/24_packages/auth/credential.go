package auth

import "fmt"

//if want to export you have to main the word Firstword capital letter
func LoginWithCredential(username string, password string) {
	fmt.Println("login user using ", username, password)
}
