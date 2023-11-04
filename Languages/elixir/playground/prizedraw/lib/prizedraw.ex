defmodule Prizedraw do
  def read_file(filename) do
    filename
    |> File.read()
    |> handle_file_read()
    |> String.replace(~r/\n$/, "")
    |> String.split("\n")
    |> tl()
    |> Enum.map(&create_col_map/1)
    |> Enum.uniq_by(&[&1.email, &1.discord, &1.twitch])
    |> Enum.random()
    |> winner()
  end

  defp handle_file_read({:ok, contents}), do: contents
  defp handle_file_read({:error, reason}), do: {:error, "File not found. Reason: #{reason}"}

  defp create_col_map(col) do
    [_, email, name, discord, twitch] = String.split(col, ",")

    %{
      :name => name,
      :email => email,
      :discord => discord,
      :twitch => twitch
    }
  end

  defp winner(%{:email => email, :name => name}) do
    IO.puts(
      "Happy holidays #{name}! You won the prize! We'll be in touch with you shortly at #{email}."
    )
  end
end

defmodule Main do
  def main() do
    Prizedraw.read_file(~c"users.csv")
  end
end

# Enum.uniq_by(fn x -> x[:email] end)
