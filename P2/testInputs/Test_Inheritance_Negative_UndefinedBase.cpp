struct Base {
	int x;
	int y;
};

struct Derived : Imaginary {
	int z;
};

int main() {
	Base base;
	Derived derived;
	base.x = 1;// expected to work
	derived.y = 1; // expected to work
	derived.z = 1; // expected to work
	return 0;
}
