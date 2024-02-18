
```md
- cmd/
  - todo/
    - main.go
- internal/
  - app/
    - core_logic/
      - usecase/
        - user_usecase.go
        - other_usecase.go
      - repository/
        - user_repository.go
        - other_repository.go
      - models/
        - user.go
        - other_models.go
    - interfaces/
      - adapters/
        - database/
          - user_repository_db.go
          - other_repository_db.go
        - http/
          - user_handler.go
          - other_handler.go
        - logging/
          - logger.go
        - ...
    - config/
      - config.go
      - database.go
    - di/
      - container.go
```

- cmd/yourapp/main.go: Entry point of your application.
- internal/app/core_logic/usecase/: Contains use cases that represent the core business logic of the application.
- internal/app/core_logic/repository/: Houses interfaces and implementations for interacting with data storage.
- internal/app/core_logic/models/: Defines domain models used within the core logic.
- internal/app/interfaces/adapters/: Contains implementations for different adapters (database, HTTP, logging, etc.).
- internal/app/config/: Manages configuration files, such as database configurations.
- internal/app/di/: Handles dependency injection.

---

## Ports and Adapters

- Ports: Define interfaces (ports) for the core logic. These interfaces will be implemented later.
- Adapters: Create separate packages for adapters, such as database adapters, HTTP handlers, and other external systems. Adapters implement the ports/interfaces defined in the core logic.

## Core Logic

- Usecases: Implement the business use cases in the core/usecase package. These should use the interfaces defined in the ports.

- Repositories: Create repository interfaces in the core/repository package for data storage operations. Implement these interfaces in adapter packages.

- Models: Define models that represent your domain entities in the core/models package.


## Adapters

- Database Adapter: Create a package for interacting with your database. Implement the repository interfaces defined in the core logic.

- HTTP Adapter: Develop an HTTP adapter to handle incoming requests. Translate HTTP input/output to and from the core logic interfaces.

## Dependency Injection

Use dependency injection to connect the core logic with the adapters. This allows you to swap implementations easily for testing or changing external systems.

## Testing

Write tests for the core logic independently from the adapters. Mock the adapters' behavior in these tests.

## References

- [Clean](https://github.com/eminetto/clean-architecture-go-v2)
