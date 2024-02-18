package main

import (
	"log"
	"net/http"
)

func home(w http.ResponseWriter, r *http.Request) {
	host := r.Host
	w.Write([]byte(host))
}

func main() {

	http.HandleFunc("/", home)

	log.Fatal(http.ListenAndServe(":8080", nil))
	// log.Fatal(http.ListenAndServe(":8080", http.FileServer(http.Dir("."))))
}
