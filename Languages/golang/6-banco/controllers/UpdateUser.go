package controllers

import (
	"crud/db"
	"encoding/json"
	"fmt"
	"io/ioutil"
	"net/http"
	"strconv"

	"github.com/gorilla/mux"
)

func UpdateUser(w http.ResponseWriter, r *http.Request) {
	params := mux.Vars(r)

	userId := params["id"]

	id, err := strconv.ParseUint(userId, 10, 32)

	if err != nil {
		w.WriteHeader(http.StatusBadRequest)
		w.Write([]byte("Invalid user id"))
		return
	}

	body, err := ioutil.ReadAll(r.Body)
	if err != nil {
		w.WriteHeader(http.StatusBadRequest)
		w.Write([]byte("Error reading request body"))
		return
	}

	var user User
	if err = json.Unmarshal(body, &user); err != nil {
		w.WriteHeader(http.StatusBadRequest)
		w.Write([]byte("Error unmarshalling request body"))
		return
	}

	db, err := db.Connection()

	if err != nil {
		w.WriteHeader(http.StatusBadRequest)
		w.Write([]byte("Error connecting to database"))
		return
	}

	defer db.Close()

	statement, err := db.Prepare("UPDATE users SET name = ?, email = ?, password = ? WHERE id = ?")

	if err != nil {
		w.WriteHeader(http.StatusBadRequest)
		w.Write([]byte("Error updating user:" + err.Error()))
		return
	}

	defer statement.Close()

	_, err = statement.Exec(user.Name, user.Email, user.Password, id)

	if err != nil {
		w.WriteHeader(http.StatusBadRequest)
		w.Write([]byte("Error updating user:" + err.Error()))
		return
	}

	w.WriteHeader(http.StatusNoContent)
	w.Write([]byte(fmt.Sprintf("User %d updated", id)))
}
