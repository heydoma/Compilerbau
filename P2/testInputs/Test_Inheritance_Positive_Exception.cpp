struct Derived : exception {
	int z;
};

struct Derived2: Derived {
  int x;
};

int main() {
  try
  {
  } catch (Derived2 e)
  {
  }
	return 0;
}
