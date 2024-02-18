package http

import (
	"hexagon/internals/app/core/models"
	"hexagon/internals/app/core/usecase"
	"hexagon/internals/app/di"
	"net/http"
)

type UserHandler struct {
	TodoUsecase *usecase.TodoUsecase
}

func NewUserHandler(todoUsecase *usecase.TodoUsecase) *UserHandler {
	return &UserHandler{TodoUsecase: todoUsecase}
}

func (h *UserHandler) HandleTodoCreation(userID string, todoData map[string]interface{}) error {
	// Parse todoData and create a Todo object
	newTodo := models.Todo{
		UserID: userID,
		Title:  todoData["title"].(string),
		// set other fields...
	}

	// Create Todo using the TodoUsecase
	err := h.TodoUsecase.CreateTodo(newTodo)
	if err != nil {
		return err
	}

	// Handle successful creation
	return nil
}

func Request() {
	http.HandleFunc("/user/todo", func(w http.ResponseWriter, r *http.Request) {
		// Extract userID from request or context
		userID := "123" // Extract or get userID from request (this is just an example)

		// Handle Todo creation request
		// Example: Parse request body and call UserHandler's method
		// userHandler.HandleTodoCreation(userID, parsedTodoData)
		parsedTodoData := map[string]interface{}{
			"title": "My first todo",
		}

		user := di.SetupDependencies()
		userHandler := NewUserHandler(user)
		userHandler.HandleTodoCreation(userID, parsedTodoData)

		// Send response back
		w.WriteHeader(http.StatusCreated)
		w.Write([]byte("Todo created successfully"))
	})
}
