// C Program to illustrate 2d array
#include "DynamicArray.h"

void dynamicArrays() {
	int* b = new int[ 4 ] { 2, 3, 4, 5 };
	std::vector<int> c = { 3, 4, 5, 6, 7 };
	DynamicArray aa({ 1, 2, 3, 4 });
	DynamicArray bb(b, 4);
	DynamicArray cc(c);
	DynamicArray dd(4);
	aa.print();
	bb.print();
	cc.print();
	dd.print();
	DynamicArray ee(aa);
	ee.print();
	DynamicArray ff(std::move(bb));
	ff.print();
}

int main()
{
	dynamicArrays();
	// declaring and initializing 2d array
	int arr[][2][2] = { 10, 20, 30, 40, 50, 60 };



	return 0;
}
