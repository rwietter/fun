package controllers

import (
	"crud/db"
	"encoding/json"
	"net/http"
)

type UserResponse struct {
	Id    uint32 `json:"id"`
	Name  string `json:"name"`
	Email string `json:"email"`
}

func GetUsers(w http.ResponseWriter, r *http.Request) {
	db, error := db.Connection()

	if error != nil {
		w.WriteHeader(http.StatusBadRequest)
		w.Write([]byte("Error connecting to database"))
		return
	}

	// defer db.Close()

	rows, error := db.Query("SELECT * FROM users")

	if error != nil {
		w.WriteHeader(http.StatusBadRequest)
		w.Write([]byte("Error fetching users"))
		return
	}

	defer rows.Close()

	var users []User

	for rows.Next() {
		var user User

		if error = rows.Scan(&user.Id, &user.Name, &user.Email, &user.Password); error != nil {
			w.WriteHeader(http.StatusBadRequest)
			w.Write([]byte("Error fetching users"))
			return
		}

		users = append(users, user)
	}

	var response []UserResponse

	for _, user := range users {
		response = append(response, UserResponse{
			Id:    user.Id,
			Name:  user.Name,
			Email: user.Email,
		})
	}

	w.WriteHeader(http.StatusOK)
	if err := json.NewEncoder(w).Encode(response); err != nil {
		w.WriteHeader(http.StatusBadRequest)
		w.Write([]byte("Error fetching users"))
		return
	}

}
