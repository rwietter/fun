defmodule StackStructTest do
  use ExUnit.Case, async: true
  alias StackStruct, as: T
  doctest StackStruct

  test "new should create a SatckStruct instance" do
    stack = T.new()
    assert stack.list == []
  end

  test "push/2 should add an element to the stack" do
    stack = T.new()
    stack = T.push(stack, 1)
    assert stack == %T{list: [1]}
  end

  test "pop/1 should return error because struct is empty" do
    stack = T.new()
    {:error, msg} = T.pop(stack)
    assert msg == "Stack is empty"
  end

  test "pop/1 should return the stack without the last element" do
    stack = T.new()
    stack = T.push(stack, 1)
    stack = T.push(stack, 2)
    stack = T.push(stack, 3)
    {:ok, stack} = T.pop(stack)
    assert stack == %T{list: [2, 1]}
  end

  test "is_empty/1 should return true if the stack is empty" do
    stack = T.new()
    assert T.is_empty(stack) == true
  end
end
