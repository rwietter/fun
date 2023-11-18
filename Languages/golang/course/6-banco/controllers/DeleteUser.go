package controllers

import (
	"crud/db"
	"net/http"
	"strconv"

	"github.com/gorilla/mux"
)

func DeleteUser(w http.ResponseWriter, r *http.Request) {
	params := mux.Vars(r)

	userId := params["id"]

	id, err := strconv.ParseUint(userId, 10, 32)

	if err != nil {
		w.WriteHeader(http.StatusBadRequest)
		w.Write([]byte("Invalid user id! Check your request and try again."))
		return
	}

	db, err := db.Connection()

	if err != nil {
		w.WriteHeader(http.StatusBadRequest)
		w.Write([]byte("Error connecting to database!"))
		return
	}

	defer db.Close()

	statement, err := db.Prepare("DELETE FROM users WHERE id = ?")

	if err != nil {
		w.WriteHeader(http.StatusBadRequest)
		w.Write([]byte("Error deleting user:" + err.Error()))
		return
	}

	defer statement.Close()

	if _, err = statement.Exec(id); err != nil {
		w.WriteHeader(http.StatusBadRequest)
		w.Write([]byte("Error deleting user:" + err.Error()))
		return
	}

	w.WriteHeader(http.StatusOK)
	w.Write([]byte("User deleted successfully!"))
}
