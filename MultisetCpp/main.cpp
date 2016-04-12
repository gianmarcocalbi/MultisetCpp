#include "multiset.h"
#include <stdlib.h>
#include <string>

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

	///< Test tipi complessi (stringhe).
	multiset<std::string> m_string_1;
	multiset<std::string> m_string_2;
	m_string_1.add("luca");
	m_string_1.add("luca");
	m_string_1.add("matteo");
	m_string_1.add("luca");
	m_string_1.add("giovanni");
	m_string_1.add("giovanni");
	m_string_1.add("giovanni");

	///< Test confronto multiset complessi.
	std::cout << "m_string_1 != m_string_2 : true -> " << (m_string_1 != m_string_2) << std::endl;

	multiset<std::string> m_string_3(m_string_1);

	std::cout << "m_string_1 == m_string_3(m_string_1) : true -> " << (m_string_1 == m_string_3) << std::endl;

	std::cout << m_string_3 << std::endl;

	std::cout << "m_string_1.get_objects_amount() : 7 -> " << m_string_1.get_objects_amount() << std::endl;
	std::cout << "m_string_1.object_count(giovanni) : 3 -> " << m_string_1.object_count("giovanni") << std::endl;
	std::cout << "m_string_1.object_count(marco) : 0 -> " << m_string_1.object_count("marco") << std::endl;
	std::cout << "m_string_1.contains(luca) : true -> " << m_string_1.contains("luca") << std::endl;
	std::cout << "m_string_1.contains(marco) : false -> " << m_string_1.contains("marco") << std::endl;

	m_string_3.remove("luca");
	m_string_3.remove("luca");
	m_string_3.remove("luca");
	m_string_3.remove("luca");
	m_string_3.remove("luca");
	m_string_3.remove("luca");
	m_string_3.remove("luca");
	m_string_3.remove("luca");
	m_string_3.remove("luca");
	m_string_3.remove("luca");

	std::cout << "m_string_3.get_objects_amount() : 4 -> " << m_string_3.get_objects_amount() << std::endl;

	m_string_2 = m_string_1;

	///< Test iteratori multiset complessi.
	multiset<std::string>::const_iterator m_string_2_it1 = m_string_2.begin();
	multiset<std::string>::const_iterator m_string_2_it2(m_string_2_it1);
	multiset<std::string>::const_iterator m_string_2_it3 = m_string_2_it2;
	std::cout << "Iteratore1 di m_string_2 : {";
	for (; m_string_2_it1 != m_string_2.end(); ++m_string_2_it1) {
		std::cout << " " << *m_string_2_it1 << " ";
	}
	std::cout << "}" << std::endl;
	std::cout << "Iteratore2 di m_string_2 : {";
	for (; m_string_2_it2 != m_string_2.end(); m_string_2_it2++) {
		std::cout << " " << *m_string_2_it2 << " ";
	}
	std::cout << "}" << std::endl;
	std::cout << "Iteratore3 di m_string_2 : {";
	for (; m_string_2_it3 != m_string_2.end(); ++m_string_2_it3) {
		std::cout << " " << *m_string_2_it3 << " ";
	}
	std::cout << "}" << std::endl << m_string_2 << std::endl;

	///< Test multiset di multiset
	multiset<multiset<std::string> > mm_string;
	mm_string.add(m_string_3);
	mm_string.add(m_string_3);
	mm_string.add(m_string_2);
	mm_string.add(m_string_2);
	mm_string.add(m_string_1);
	mm_string.add(m_string_1);

	std::cout << mm_string << std::endl;

	return 0;
}

