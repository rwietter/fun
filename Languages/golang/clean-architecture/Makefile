# Define colors based on tput
BOLD := $(shell tput bold)
RED := $(shell tput -Txterm setaf 1)
GREEN := $(shell tput -Txterm setaf 2)
BLUE := $(shell tput -Txterm setaf 6)
RESET := $(shell tput -Txterm sgr0)

.PHONY: run

help: ## Shows help for Makefile commands.
	@echo ""
	@echo "$(BOLD)$(BLUE)Available commands:$(RESET)"
	@echo ""
	@awk 'BEGIN {FS = ":.*?## "} /^[a-zA-Z0-9 -]+:.*?## / {printf "$(BOLD)$(GREEN)%-30s$(RESET)%s\n", $$1, $$2}' $(MAKEFILE_LIST)
	@echo ""

run: # Start Docker Compose services in the background
	@echo "$(BOLD)$(BLUE)Run go app.. $(RESET)"
	@go run ./app/main.go
