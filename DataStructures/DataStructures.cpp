// C Program to illustrate 2d array
#include "DynamicArray.h"

void dynamicIntegerArrays() {
	int* b = new int[ 4 ] { 2, 3, 4, 5 };
	std::vector<int> c = { 3, 4, 5, 6, 7 };
	DynamicArray<int> aa({ 1, 2, 3, 4 });
	DynamicArray<int> bb(b, 4);
	DynamicArray<int> cc(c);
	DynamicArray<int> dd(4);
	aa.print();
	bb.print();
	cc.print();
	dd.print();
	DynamicArray<int> ee(aa);
	ee.print();
	DynamicArray<int> ff(std::move(bb));
	ff.print();
}

void dynamicCharacterArrays() {
	char* b = new char[5];
	strcpy_s(b, 5, "abcd");
	std::vector<char> c = { 'b', 'c', 'd', 'e' };
	DynamicArray<char> aa({ 'c', 'd', 'e', 'f' });
	DynamicArray<char> bb(b, 4);
	DynamicArray<char> cc(c);
	DynamicArray<char> dd(4);
	aa.print();
	bb.print();
	cc.print();
	dd.print();
	DynamicArray<char> ee(aa);
	ee.print();
	DynamicArray<char> ff(std::move(bb));
	ff.print();
}

void dynamicPowered() {
	//DynamicArray<DynamicArray<std::string>> aa({ {"Hi!", "My name", "is Levko"}, {"And", "what is", "yours?"} });
	//aa.print();
}

int main()
{
	dynamicIntegerArrays();
	dynamicCharacterArrays();


	return 0;
}
