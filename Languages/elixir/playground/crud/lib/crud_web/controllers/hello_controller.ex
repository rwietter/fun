defmodule CrudWeb.HelloController do
  use CrudWeb, :controller

  def world(conn, _) do
    text(conn, "Hello World")
    # render(conn, "world.html")
  end

  def name(conn, %{"name" => name}) do
    text(conn, "Hello #{name}")
  end
end
