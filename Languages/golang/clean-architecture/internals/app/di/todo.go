package di

import (
	"hexagon/internals/app/core/usecase"
	"hexagon/internals/app/interfaces/adapters/database"
)

func SetupDependencies() *usecase.TodoUsecase {
	// Initialize database adapter
	todoRepoDB := database.NewTodoRepositoryDB()

	// Initialize use cases and inject dependencies
	todoUsecase := usecase.NewTodoUsecase(todoRepoDB)

	// Return these instances or store them in a global context for use within your application
	return todoUsecase
}
