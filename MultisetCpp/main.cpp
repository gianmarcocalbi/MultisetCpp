#include "multiset.h"
#include <stdlib.h>

int main() {
	
	multiset<int> m_int_1;///< Test Costruttore tipo base.
	
	m_int_1.add(2);///< Test Add nuovo elemento di tipo semplice.
	m_int_1.add(2);///< Test Add elemento già esistente di tipo semplice.
	m_int_1.add(2);
	m_int_1.add(199);
	m_int_1.remove(2);///< Test remove elemento presente nel multiset.
	m_int_1.add(3);///< Test remove elemento non presente nel multiset.
	m_int_1.remove(199);///< Test rimozione completa elemento.

	multiset<int> m_int_1_copy(m_int_1);///<Test copy constructor tipo base.

	std::cout << m_int_1 << std::endl << m_int_1_copy << std::endl;

	///< Test operatore di confronto == tra multiset tipo base.
	std::cout << "m_int_1 == m_int_1_copy(m_int_1) : true -> " << (m_int_1 == m_int_1_copy) << std::endl;
	std::cout << "m_int_1 != m_int_1_copy(m_int_1) : false -> " << (m_int_1 != m_int_1_copy) << std::endl;

	multiset<int> m_int_2 = m_int_1_copy; ///< Test operatore assegnamento.
	m_int_2.remove(2); ///< Test rimozione elemento da multiset vuoto.

	m_int_1_copy.remove(2);
	std::cout << m_int_1 << std::endl << m_int_1_copy << std::endl;

	///< Test operatore di confronto != tra multiset di tipo base.
	std::cout << "m_int_1 != m_int_1_copy(m_int_1) : true -> " << (m_int_1 != m_int_1_copy) << std::endl;
	
	///< Test costruttore tipo base char.
	multiset<char> m_char_1;
	m_char_1.add('?');
	m_char_1.add('a');
	m_char_1.add('?');
	m_char_1.add('m');
	m_char_1.add('a');

	///< Test operatore << di multiset di tipo base.
	std::cout << m_char_1 << std::endl;

	std::cout << "m_char_1.contains('?') : true -> " << m_char_1.contains('?') << std::endl;
	std::cout << "m_char_1.object_count('a') : 2 -> " << m_char_1.object_count('a') << std::endl;

	m_char_1.remove('?');
	m_char_1.remove('a');
	m_char_1.remove('?');
	m_char_1.remove('m');
	m_char_1.remove('a');
	m_char_1.remove('?');
	m_char_1.remove('a');
	m_char_1.remove('?');
	m_char_1.remove('m');
	m_char_1.remove('a');

	multiset<char> m_char_2;

	///< Test confronto multiset vuoti di tipo base.
	std::cout << "m_char_2 == m_char_1 : true -> " << (m_char_2 == m_char_1) << std::endl;

	m_char_2.remove('a');

	std::cout << "m_int_1.get_objects_amount() : 3 -> " << m_int_1.get_objects_amount() << std::endl;
	std::cout << "m_int_1.object_count(2) : 2 -> " << m_int_1.object_count(2) << std::endl;
	std::cout << "m_int_1.object_count(999) : 0 -> " << m_int_1.object_count(999) << std::endl;
	std::cout << "m_int_2.contains(3) : true -> " << m_int_2.contains(3) << std::endl;
	std::cout << "m_char_2.contains('0') : false -> " << m_char_2.contains('0') << std::endl;
	std::cout << "m_char_2.object_count('d') : 0 -> " << m_char_2.contains('d') << std::endl;
	
	multiset<double> m_double_1;
	multiset<double> m_double_2;

	multiset<int> m_int_3;
	///< Altri test su operatori di confronto.
	std::cout << "m_double_1 == m_double_2 : true -> " << (m_double_1 == m_double_2) << std::endl;
	std::cout << "m_double_1 != m_double_2 : false -> " << (m_double_1 != m_double_2) << std::endl;
	std::cout << "m_double_1 == m_double_1 : true -> " << (m_double_1 == m_double_1) << std::endl;
	std::cout << "m_double_1 != m_double_1 : false -> " << (m_double_1 != m_double_1) << std::endl;
	std::cout << "m_int_1 == m_int_3 : false -> " << (m_int_1 == m_int_3) << std::endl;

	m_char_1.add('a');
	m_char_1.add('?');
	m_char_1.add('#');
	m_char_1.add('#');
	m_char_1.add('#');
	m_char_1.add('#');
	m_char_1.add('?');
	m_char_1.add('#');
	m_char_1.add('?');
	m_char_1.add('#');

	///< Test su iteratori per multiset di tipo base.
	multiset<int>::const_iterator m_int_1_it1 = m_int_1.begin(); ///< Test costruttore iteratore.
	multiset<int>::const_iterator m_int_1_it2(m_int_1.begin()); ///< Test copy constructor iteratore.
	std::cout << "m_int_1_it1 == m_int_1_it2 : true -> " << (m_int_1_it1 == m_int_1_it2) << std::endl; ///< Test 1 confronto di uguaglianza tra iteratori.
	m_int_1_it1++;
	std::cout << "m_int_1_it1 == m_int_1_it2 : false -> " << (m_int_1_it1 == m_int_1_it2) << std::endl; ///< Test 2 confronto di uguaglianza tra iteratori.
	m_int_1_it2++;
	std::cout << "m_int_1_it1 == m_int_1_it2 : true -> " << (m_int_1_it1 == m_int_1_it2) << std::endl; ///< Test 3 confronto di uguaglianza tra iteratori.
	m_int_1_it1 = m_int_1.begin();
	///< Test stampa con iteratore.
	std::cout << "Iteratore di m_int_1 : {";
	for (; m_int_1_it1 != m_int_1.end(); ++m_int_1_it1) {
		std::cout << " " << *m_int_1_it1 << " ";
	}
	std::cout << "}" << std::endl;

	multiset<char>::const_iterator m_char_1_it1 = m_char_1.begin();
	multiset<char>::const_iterator m_char_1_it2 = m_char_1_it1; ///< Test copia per assegnamento.
	std::cout << "Iteratore1 di m_char_1 : {";
	for (; m_char_1_it1 != m_char_1.end(); ++m_char_1_it1) {
		std::cout << " " << *m_char_1_it1 << " ";
	}
	std::cout << "}" << std::endl;
	std::cout << "Iteratore2 copia di m_char_1 : {";
	for (; m_char_1_it2 != m_char_1.end(); m_char_1_it2++) {
		std::cout << " " << *m_char_1_it2 << " ";
	}
	std::cout << "}" << std::endl << m_char_1 << std::endl;

	///< Test tipi complessi.
	/*multiset<char[]> m_array_char_1;
	multiset<char[]> m_array_char_2;

	multiset<char[]> m_array_char_3(m_array_char_1);*/





	/*
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
	*/
	system("pause");
	return 0;
}

/*
	#Test

	Costruttore
	Copy Constructor
	Creazione per Assegnamento
	Add
	Remove
	Remove elementi non esistenti
	Remove multiset vuoto
	object_count elemento esistente
	object_count elemento non esistente
	object_count multiset vuoto
	contains x3 (== object_count)
	operatore == {
	ms == ms
	ms vuoto == ms
	ms == ms vuoto
	ms vuoto == ms vuoto
	}
	operatore != x4
	iteratori {
	costruttore
	copy constructor
	operatore assegnaemento
	*
	->
	++(int)
	++
	==
	!=
	iterazioni
	}
	operazione <<
*/

