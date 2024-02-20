#include "DynamicArray.h"

void dynamicIntegerArrays() {
	int* b = new int[ 4 ] { 2, 3, 4, 5 };
	std::vector<int> c = { 3, 4, 5, 6, 7 };
	DynamicArray<int> aa({ 1, 2, 3, 4 });
	DynamicArray<int> bb(b, 4);
	DynamicArray<int> cc(c);
	DynamicArray<int> dd(4);
	std::cout << aa;
	std::cout << bb;
	std::cout << cc;
	std::cout << dd;
	DynamicArray<int> ee(aa);
	std::cout << ee;
	DynamicArray<int> ff(std::move(bb));
	std::cout << ff;
}

void dynamicCharacterArrays() {
	char* b = new char[5];
	strcpy_s(b, 5, "abcd");
	std::vector<char> c = { 'b', 'c', 'd', 'e' };
	DynamicArray<char> aa({ 'c', 'd', 'e', 'f' });
	DynamicArray<char> bb(b, 4);
	DynamicArray<char> cc(c);
	DynamicArray<char> dd(4);
	std::cout << aa;
	std::cout << bb;
	std::cout << cc;
	std::cout << dd;
	DynamicArray<char> ee(aa);
	std::cout << ee;
	DynamicArray<char> ff(std::move(bb));
	std::cout << ff;
}

void dynamicPowered() {
	DynamicArray<DynamicArray<std::string>> aa({ {"Hi!", "My name", "is Levko"}, {"And", "what is", "yours?"} });
	std::cout << aa;
}

int main()
{
	dynamicIntegerArrays();
	dynamicCharacterArrays();
	dynamicPowered();

	return 0;
}
