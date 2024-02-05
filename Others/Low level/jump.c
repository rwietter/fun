void func3(void) { printf("three\n"); }
void func2(void) { printf("two\n"); }
void func1(void) { printf("one\n"); }

int main()
{
    int index = 2;
    void (*jumpTable[])(void) = {&&Case1, &&Case2, &&Case3};
    goto *jumpTable[index];

Case1:
    func1();
    return 0;

Case2:
    func2();
    return 0;

Case3:
    func3();
    return 0;
}