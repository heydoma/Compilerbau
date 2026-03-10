#!/bin/bash

# color constants for colorful output
RED="\033[0;31m"
GREEN="\033[0;32m"
YELLOW="\033[1;33m"
NC='\033[0m'
for file in testInputs/*.cpp2 testInputs/**/*.cpp2; do
    first_line=$(head -n 1 "$file")
    expected_return_code=$(echo "$first_line" | grep -oP '//\K\d+')
    returncode_known=true

    if [ -z "$expected_return_code" ]; then
        echo -e "${YELLOW}Warning${NC}: Could not find expected return code in $file, only the returncode of the program will be printed:"
        returncode_known=false
    fi

    ./compiler $file > testcase.ll
    if [ $? -ne 0 ]; then
        echo -e "${RED}The compiler produced errors on $file${NC} with code $?"
        rm testcase.ll
        continue
    fi
    clang++-9 testcase.ll -o testcase 2>&-

    # check that the compilation step is successful
    if [ $? -ne 0 ]; then
        echo -e "${RED}The llvm code produced by the compiler on $file is incorrect${NC}"
        rm testcase.ll
        continue
    fi

    # cleanup
    rm testcase.ll
    ./testcase
    actual_return_code=$?
    if [ "$returncode_known" = true ] ; then
        if [ "$actual_return_code" -eq "$expected_return_code" ]; then
            echo -e "${GREEN}Success${NC}: $file returned the expected return code $expected_return_code"
        else
            echo -e "${RED}Failure${NC}: $file returned $actual_return_code, expected $expected_return_code"
        fi
    else
        echo -e "${YELLOW} $actual_return_code ${NC}"
    fi
    # cleanup
    rm testcase
done