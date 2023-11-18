package controllers

import (
	"crud/db"
	"encoding/json"
	"fmt"
	"io/ioutil"
	"net/http"
)

type User struct {
	Id       uint32 `json:"id"`
	Name     string `json:"name"`
	Email    string `json:"email"`
	Password string `json:"password,omitempty"`
}

func CreateUser(w http.ResponseWriter, r *http.Request) {
	body, error := ioutil.ReadAll(r.Body)

	if error != nil {
		w.Write([]byte("Body is required"))
		return
	}

	var user User

	error = json.Unmarshal(body, &user)

	if error != nil {
		w.WriteHeader(http.StatusBadRequest)
		w.Write([]byte("Invalid body"))
		return
	}

	db, error := db.Connection()

	if error != nil {
		w.WriteHeader(http.StatusBadRequest)
		w.Write([]byte("Error connecting to database"))
		return
	}

	defer db.Close()

	statement, error := db.Prepare("insert into users (name, email, password) values (?, ?, ?)")

	if error != nil {
		w.WriteHeader(http.StatusBadRequest)
		w.Write([]byte("Error creating statement"))
		return
	}

	defer statement.Close()

	insert, error := statement.Exec(user.Name, user.Email, user.Password)

	if error != nil {
		w.WriteHeader(http.StatusBadRequest)
		w.Write([]byte("Error creating user"))
		return
	}

	userId, error := insert.LastInsertId()

	if error != nil {
		w.WriteHeader(http.StatusBadRequest)
		w.Write([]byte("Error getting last user id"))
		return
	}

	w.WriteHeader(http.StatusCreated)
	w.Write([]byte(fmt.Sprintf("User created with id %d", userId)))

	return
}
