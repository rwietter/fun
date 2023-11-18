package main

/*
	import with _ to not use the package directly, use it's in another packages
*/
import (
	"crud/controllers"
	"log"
	"net/http"

	_ "github.com/go-sql-driver/mysql"
	"github.com/gorilla/mux"
)

func main() {
	router := mux.NewRouter()

	router.HandleFunc("/api/users", controllers.CreateUser).Methods("POST")
	router.HandleFunc("/api/users", controllers.GetUsers).Methods("GET")
	router.HandleFunc(("/api/users/{id}"), controllers.GetUser).Methods("GET")
	router.HandleFunc("/api/users/{id}", controllers.UpdateUser).Methods("PUT")
	router.HandleFunc("/api/users/{id}", controllers.DeleteUser).Methods("DELETE")

	println("Server running on port 5000")
	log.Fatal(http.ListenAndServe(":5000", router))
}
