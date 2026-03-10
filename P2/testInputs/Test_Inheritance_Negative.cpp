struct Base {
	int x;
	int y;
};

struct Derived : Base {
	int z;
};

int main() {
	Base base;
	Derived derived;
	base.x = 1;// expected to work
	derived.x = 1; // expected to work
	derived.z = 1; // expected to work
	base.z = 1; // expected to fail
	return 0;
}
