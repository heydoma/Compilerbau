for file in "testInputs"/**/*; do
    if [ -f "$file" ]; then
        echo "Running TestCPP on $file..."
	output=$(./TestCPP "$file")
	echo "$output" | grep -i -E "$file|error at"
    fi
done
