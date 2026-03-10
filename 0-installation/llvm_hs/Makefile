all: toy

toy:
	stack build;

clean:
	stack clean --full

test: toy
	echo "def foo(x y) x+foo(y, 4.0);" | stack exec toy