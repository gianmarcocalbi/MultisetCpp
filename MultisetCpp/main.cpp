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
	m3.add(6);
	m3.add(6);
	m3.add(6);
	m3.remove(3);
	//m2.print();

	//cout << (m1 == m2) << endl;
	
	multiset<int>::const_iterator it1 = m3.begin();

	for (; it1 != m3.end(); ++it1) {
		std::cout << *it1 << std::endl;
	}
	std::cout << m3 << std::endl;
	
	multiset<multiset<int>> mm;
	mm.add(m1);
	mm.add(m2);
	mm.add(m3);
	//mm.remove(m2);
	//mm.remove(m2);

	multiset<multiset<int>> mm2(mm);
	multiset<multiset<int>> mm3 = mm2;
	//mm3 = mm;

	multiset<int>::const_iterator it2 = m3.begin();

	for (; it2 != m3.end(); ++it2) {
		std::cout << *it2 << std::endl;
	}

	std::cout << mm << std::endl;
	std::cout << mm2 << std::endl;
	std::cout << mm3 << std::endl;

	multiset<std::string> mss;
	mss.add("hi");
	mss.add("ciao");
	mss.add("hello");
	
	multiset<int> m5;
	m5.add(1);
	multiset<int> m6;
	m6 = m5;
	std::cout << (m6 == m5) << std::endl;
	std::cout << (m6 != m5) << std::endl;
	//m6 = m5;

	//std::cout << mss;

	system("pause");
	return 0;
}