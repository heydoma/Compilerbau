all: toy

toy:
	clang++-9 -g toy.cpp `llvm-config-9 --cxxflags --ldflags --system-libs --libs core mcjit native` -O3 -o toy

clean:
	rm -f toy

test: toy
	echo "def foo(x y) x+foo(y, 4.0);" | ./toy
