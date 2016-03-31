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
	//m1.print();

	multiset<int> m2 = multiset<int>();
	m2.add(2);
	m2.add(2);
	m2.add(2);
	m2.add(199);
	m2.remove(2);
	m2.add(3);
	m2.remove(199);
	//m2.print();

	multiset<int> m3 = multiset<int>();
	m3.add(3);
	m3.add(3);
	m3.add(3);
	m3.add(4);
	m3.add(5);
	m3.add(5);
	m3.add(6);
	//m2.print();

	//cout << (m1 == m2) << endl;
	
	multiset<int>::const_iterator it1 = m3.begin();

	for (; it1 != m3.end(); ++it1) {
		std::cout << *it1 << std::endl;
	}
	

	system("pause");
	return 0;
}