for file in "testInputs"/*; do
    if [ -f "$file" ]; then
        echo "Running TypeChecker on $file..."
	output=$(./compiler "$file")
	echo "$output" | grep -i -E "$file|TYPE ERROR"
    fi
done
