package main

import "fmt"

/* ------------ CUSTOM ERRORS ------------ */
type NotFoundError struct {
	EntityName string
}

func (e *NotFoundError) Error() string {
	return fmt.Sprintf("%s not found", e.EntityName)
}

type PermissionError struct {
	OperationName string
}

func (e *PermissionError) Error() string {
	return fmt.Sprintf("permission denied for %s", e.OperationName)
}

/* --------- USING CUSTOM ERRORS ---------- */
func findUser(username string) (string, error) {
	if len(username) < 3 {
		return "", &NotFoundError{"user"}
	}
	return "John Doe", nil
}

func main() {
	_, err := findUser("jo")
	if err != nil {
		switch e := err.(type) {
		case *NotFoundError:
			fmt.Println("Handle not found:", e.Error())
		case *PermissionError:
			fmt.Println("Handle permission error:", e.Error())
		default:
			fmt.Println("Handle general error:", e.Error())
		}
	}
}
