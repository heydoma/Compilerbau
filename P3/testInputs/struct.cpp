struct A {
    bool q;
    bool w;
    int a;
};

struct B {
    int c;
    A b;
};

struct C {
  B y;
};

C p;
C p1;
int main() {
  //t.b = u;
   p.y.b.a = 1;
   p1 = p;
   p1.y.b.a = 3;
   return p.y.b.a;
}