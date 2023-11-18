package db

import (
	"database/sql"

	_ "github.com/go-sql-driver/mysql" // Driver
)

func Connection() (*sql.DB, error) {
	DB_URL := "devbook:123456@/devbook?charset=utf8&parseTime=True&loc=Local"
	db, err := sql.Open("mysql", DB_URL)

	if err != nil {
		return nil, err
	}

	if err = db.Ping(); err != nil {
		return nil, err
	}

	return db, err
}
