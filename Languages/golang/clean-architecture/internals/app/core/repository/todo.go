package repository

import "hexagon/internals/app/core/models"

type TodoRepository interface {
	Create(todo models.Todo) error
	// Add other methods like Update, Delete, GetByID, etc.
}
