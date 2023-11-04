package controllers

import (
	"crud/db"
	"encoding/json"
	"fmt"
	"net/http"
	"strconv"

	"github.com/gorilla/mux"
)

func GetUser(w http.ResponseWriter, r *http.Request) {
	params := mux.Vars(r)

	userId := params["id"]

	id, err := strconv.ParseUint(userId, 10, 32)

	if err != nil {
		w.WriteHeader(http.StatusBadRequest)
		w.Write([]byte("Invalid user id"))
		return
	}

	db, err := db.Connection()

	if err != nil {
		w.WriteHeader(http.StatusBadRequest)
		w.Write([]byte("Error connecting to database"))
		return
	}

	defer db.Close()

	rows, err := db.Query("SELECT * FROM users WHERE id = ?", id)

	if err != nil {
		w.WriteHeader(http.StatusBadRequest)
		w.Write([]byte("Error fetching user"))
		return
	}

	defer rows.Close()

	var user User
	if rows.Next() {
		if err = rows.Scan(&user.Id, &user.Name, &user.Email, &user.Password); err != nil {
			w.WriteHeader(http.StatusBadRequest)
			w.Write([]byte("Error fetching user"))
			return
		}
	}

	var response UserResponse = UserResponse{
		Id:    user.Id,
		Name:  user.Name,
		Email: user.Email,
	}

	w.WriteHeader(http.StatusOK)
	if err := json.NewEncoder(w).Encode(response); err != nil {
		fmt.Println(err)
	}
}
