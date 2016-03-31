#include "multiset.h"
#include <stdlib.h>
int main() {
	multiset<int> m1 = multiset<int>();
	m1.add(2);
	m1.add(2);
	m1.add(2);
	m1.add(199);
	m1.remove(2);
	m1.add(3);
	m1.remove(199);
	m1.print();
	system("pause");
	return 0;
}