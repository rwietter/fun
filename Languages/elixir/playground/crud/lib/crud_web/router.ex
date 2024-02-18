defmodule CrudWeb.Router do
  use CrudWeb, :router

  # Define um pipeline para o browser, ou seja, o tratamento de requisições para o browser
  pipeline :browser do
    plug(:accepts, ["html"])
    plug(:fetch_session)
    plug(:fetch_live_flash)
    plug(:put_root_layout, html: {CrudWeb.Layouts, :root})
    plug(:protect_from_forgery)
    plug(:put_secure_browser_headers)
  end

  # Define um pipeline para a API, ou seja, o tratamento de requisições para a API
  pipeline :api do
    plug(:accepts, ["json"])
  end

  scope "/", CrudWeb do
    pipe_through(:browser)

    get("/", PageController, :home)
  end

  # Scope define o prefixo da rota 'http://localhost:4000/hello/'
  scope "/hello", CrudWeb do
    # pipe_through define o pipeline que será usado para as rotas. Ou seja, vai rodar o pipeline :browser
    pipe_through(:browser)
    # Get define o método HTTP e o caminho da rota 'http://localhost:4000/hello/world'
    # HelloController é o nome do controller
    # :word é o nome da função no controller
    get("/world", HelloController, :world)
    get("/:name", HelloController, :name)
  end

  # GET     /user      CrudWeb.UserController :index
  # GET     /user/new  CrudWeb.UserController :new
  # PATCH   /user/:id  CrudWeb.UserController :update
  # PUT     /user/:id  CrudWeb.UserController :update
  # DELETE  /user/:id  CrudWeb.UserController :delete
  scope "/user", CrudWeb do
    pipe_through(:browser)
    resources("/", UserController, only: [:new, :index, :update, :delete])
  end

  # Enable LiveDashboard and Swoosh mailbox preview in development
  if Application.compile_env(:crud, :dev_routes) do
    # If you want to use the LiveDashboard in production, you should put
    # it behind authentication and allow only admins to access it.
    # If your application does not have an admins-only section yet,
    # you can use Plug.BasicAuth to set up some basic authentication
    # as long as you are also using SSL (which you should anyway).
    import Phoenix.LiveDashboard.Router

    scope "/dev" do
      pipe_through(:browser)

      live_dashboard("/dashboard", metrics: CrudWeb.Telemetry)
      forward("/mailbox", Plug.Swoosh.MailboxPreview)
    end
  end
end
