defmodule StackTest do
  use ExUnit.Case
  doctest Stack

  test "push/2 should add an element to the stack" do
    stack = [1, 2, 3]
    assert Stack.push(stack, 4) == [4 | stack]
  end

  test "pop/1 should remove the last element from the stack" do
    stack = [1, 2, 3]
    {:ok, element, stack} = Stack.pop(stack)
    assert element == 1
    assert stack == [2, 3]
  end

  test "pop/1 should return an error if the stack is empty" do
    {:error, message} = Stack.pop([])
    assert message == "The stack is empty"
  end

  test "is_empty/1 should return true if the stack is empty" do
    is_empty = Stack.is_empty([])
    assert is_empty == true
  end
end
