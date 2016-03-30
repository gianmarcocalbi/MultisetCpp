#ifndef MULTISET_H
#define MULTISET_H
#include <iostream>
#include <exception>
#include <assert.h>
using namespace std;

template <typename T>
class multiset {
public:
	typedef unsigned int size_type; ///< Tipo custom per la size.

private:
	struct element {
		T object;
		size_type amount;
	};
	element *ptr;
	size_type elements_amount;
	size_type size;

public:
	multiset(void) : ptr(0), elements_amount(0), size(0) {
		#ifndef NDEBUG
		cout << "# multiset<T>::multiset(void)" << endl;
		#endif
	}


	explicit multiset(size_type sz) : elements_amount(0), size(sz) {
		#ifndef NDEBUG
		cout << "# multiset<T>::multiset(size_type sz)" << endl;
		#endif
		try {
			ptr = new ptr[size];
		} catch (bad_alloc &e) {
			cout << e.what() << endl;
			throw;
		} catch (...) {
			cout << e.what() << endl:
			throw;
		}
	}

	/**
	* Costruttore con inizializzazione.
	*/
	//(!) explicit multiset(size_type sz, const T &init) : elements_amount(0), size(sz)

	/**
	* Copy Constructor.
	*/

	/**
	* Operatore Assegnamento.
	*/

	/**
	* Operatore Assegnamento Templato.
	*/

	/**
	* Distruttore.
	*/
	~multiset() {

	}
};
#endif
