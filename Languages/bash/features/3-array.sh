array=("a" "b" "c")

# Print all elements
echo ${array[@]}

# Print length of array
echo ${#array[@]}

# Associative array
declare -A arr
arr["key1"]="value1"
arr["key2"]="value2"
echo ${arr["key1"]}

echo -e "\n"

declare -A fruits_value
fruits_value=([apple]='100 dollars' [orange]='150 dollars')

echo "Apple costs ${fruits_value[apple]}"
echo ${!fruits_value[@]} # Print all keys
echo ${#fruits_value[@]} # Print number of elements