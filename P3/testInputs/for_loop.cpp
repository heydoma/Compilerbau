int i;
int i2;
int main() {
    i = 2;
    i2 = 2;
    for(i = 1; i <= 5; i++) {
        i2 = i * i2;
    }
    return i2;
}