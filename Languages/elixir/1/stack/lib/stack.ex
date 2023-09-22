defmodule Stack do

  @doc """
  Pushes a value to the stack.
  """
  @spec push(list, integer) :: list
  def push(stack, value) when is_list(stack) do
    [value | stack]
  end

  @doc """
  Pops a value from the stack.
  """
  @spec pop(list) :: {:ok, integer, list} | {:error, String.t}
  def pop(list) do
    if is_empty(list) do
      {:error, "The stack is empty"}
    else
      {:ok, hd(list), tl(list)}
    end
  end

  @doc """
  Checks if the stack is empty.
  """
  @spec is_empty(list) :: boolean
  def is_empty([]), do: true
  def is_empty(_), do: false

  @doc """
  Shows the stack.
  """
  @spec show(list) :: :ok
  def show(list) do
    list
    |> Enum.each(fn value -> IO.write("#{value} -> ") end)
    IO.puts ""
  end
end
