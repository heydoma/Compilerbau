# usage: debug.sh <path to testcase cpp2 file>
# output: Console output of return value of executable testfile
make
./compiler $1 > testcase.ll
clang++-9 testcase.ll -o testcase
./testcase
echo $?
rm testcase testcase.ll
