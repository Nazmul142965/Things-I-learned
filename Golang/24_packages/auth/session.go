package auth

func extractSession() string {
	return "loggein"
}

// func GetSession() string {
// 	return "loggedin"
// }

func GetSession() string {
	return extractSession()
}
