#ifndef MULTISET_H
#define MULTISET_H
#include <iostream>
#include <exception>
#include <assert.h>
using namespace std;

/*
TODO
- cavare i previuos
*/

template <typename T>
class multiset {
public:
	typedef unsigned int size_type; ///< Tipo custom per la size.

private:
	struct node {
		T object;
		size_type amount;
		node *prev;
		node *next;

		/**
		 * Costruttore default.
		 */
		node() : amount(0), next(0), prev(0) { }

		/**
		 * Costruttore Primario.
		 */
		node(const T obj, size_type amou, node *p, node *n) : object(obj), amount(amou), prev(p), next(n) { }

		/**
		 * Costruttore Primario overload.
		 */
		node(const T obj, size_type amou, node *p) : object(obj), amount(amou), prev(p), next(0) { }

		/**
		* Costruttore Primario overload.
		*/
		node(const T obj, size_type amou) : object(obj), amount(amou), prev(0), next(0) { }

		/**
		* Costruttore Primario overload.
		*/
		node(const T obj) : object(obj), amount(1), prev(0), next(0) { }

		/**
		* Costruttore Primario overload.
		*/
		node(const T obj, node *n) : object(obj), amount(1), prev(0), next(n) { }


		/**
		 * Copy constructor.
		 */
		node(const node &other) : object(other.object), amount(other.amount), prev(other.prev), next(other.next) { }

		/**
		 * Distruttore.
		 */
		~node() { }

		/**
		 * Operatore assegnamento.
		 */
		node &operator=(const node &other) {
			if (this != &other) {
				object = other.object;
				amount = other.amount;
				prev = other.prev;
				next = other.next;
			}
			return *this;
		}
	};
	node *head;
	size_type nodes_amount;
	size_type single_nodes_amount;

public:

	/**
	 * Costruttore di default.
	 */
	multiset(void) : head(0), nodes_amount(0), single_nodes_amount(0) {
		#ifndef NDEBUG
		cout << "# multiset<T>::multiset(void)" << endl;
		#endif
	}

	/*try {

	} catch (bad_alloc &e) {
		cout << e.what() << endl;
		throw;
	} catch (...) {
		cout << e.what() << endl:
		throw;
	}*/

	/**
	 * Distruttore.
	 * Passo in rassegna nodo per nodo e lo elimino.
	 */
	~multiset() {
		clear();
	}

	void clear() {
		node *t1 = head;
		node *t2 = 0;

		while (t1 != 0) {
			t2 = t1->next;
			delete t1;
			t1 = t2;
		}
	}

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
	 * Add.
	 * Operazione di aggiunta elemento.
	 */
	void add(const T &obj) {
		node *t = head;
		bool found = false;
		while (t != 0) {
			if (t->object == obj) {
				//se l'oggetto è già presente allora aumenta
				found = true;
				t->amount++;
				t = 0;
			} else {
				t = t->next;
			}

		}
		if (!found) {
			//altrimenti aggiungi nodo
			if (head == 0) {
				head = new node(obj);
			} else {
				node *tmp = head;
				head = new node(obj, tmp);
				tmp->prev = head;
			}
			single_nodes_amount++;
		}
		nodes_amount++;
	}

	/**
	 * Remove.
	 */
	bool remove(const T &obj) {
		bool removed = false;
		node *tmp = head;
		while (tmp != 0) {
			if (tmp->object == obj) {
				if (tmp->amount > 1) {
					tmp->amount--;
				} else {
					node *n = tmp->next;
					node *p = tmp->prev;
					if (n != 0) {
						n.prev = p;
					}
					if (p != 0) {
						p.next = n;
					}
					delete tmp;
					single_nodes_amount--;
				}
				nodes_amount--;
				removed = true;
				tmp = 0;
			} else {
				tmp = tmp->next;
			}
		}
		return removed;
	}

	/**
	 * Print.
	 */
	void print() {
		node *tmp = head;
		while (tmp != 0) {
			cout << "--------------------------" << endl;
			cout << "-- object : " << tmp->object << "--" << endl;
			cout << "-- amount : " << tmp->amount << "--" << endl;
			cout << "--------------------------" << endl;
			tmp = tmp->next;
		}
	}

};
#endif
