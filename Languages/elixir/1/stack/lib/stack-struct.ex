defmodule StackStruct do
  alias __MODULE__, as: T
  defstruct list: []

  @opaque t :: T.t()

  @spec new :: t
  def new(), do: %T{list: []}

  @spec push(t, integer) :: t
  def push(stack, value) do
    %T{list: [value | stack.list]}
  end

  @doc """
  Alternatively uses Pattern Matching
  """
  @spec is_empty(t) :: boolean
  def is_empty(stack) do
    Enum.empty?(stack.list)
  end

  @spec pop(t) :: {:ok, t} | {:error, String.t()}
  def pop(stack) do
    if is_empty(stack) do
      {:error, "Stack is empty"}
    else
      %T{list: [_ | tail]} = stack
      {:ok, %T{list: tail}}
    end
  end

  def pop(_stack) do
    {:error, "Stack is empty"}
  end

  def show(stack) do
    Enum.each(stack.list, &IO.puts/1)
  end
end

defmodule Main do
  def main do
    alias StackStruct, as: Stack
    stack = Stack.new()
    stack = Stack.push(stack, 1) |> IO.inspect()
    stack = Stack.push(stack, 2) |> IO.inspect()
    stack = Stack.push(stack, 3) |> IO.inspect()

    case Stack.pop(stack) do
      {:ok, stack} -> IO.inspect(stack)
      {:error, result} -> IO.puts(result)
    end

    Stack.is_empty(stack) |> IO.puts()
    Stack.show(stack)
  end
end

Main.main()
