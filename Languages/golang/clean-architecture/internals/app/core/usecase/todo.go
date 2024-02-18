package usecase

import (
	"hexagon/internals/app/core/models"
	"hexagon/internals/app/core/repository"
)

type TodoUsecase struct {
	TodoRepository repository.TodoRepository
}

func NewTodoUsecase(repo repository.TodoRepository) *TodoUsecase {
	return &TodoUsecase{TodoRepository: repo}
}

func (uc *TodoUsecase) CreateTodo(todo models.Todo) error {
	// Perform any business logic validation if needed

	// Call the repository to create the todo
	return uc.TodoRepository.Create(todo)
}
