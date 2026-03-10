int main() {
    int result = 10 * (a + b) / c % d << 2 >> 1 < 5 > 3 >= 2 <= 8 <=> 0 == 7 != 9 && true || false ? x++ : --y += 5;
    int result = myArray[myFunction(x, y)] + myStruct.field1 * myStructPtr->field2;
    int result = (a ? (b ? c : d) : (e ? f : g)) ? h : i;
    bool result = (x == y) != (z > 0) >= (a < b);
}