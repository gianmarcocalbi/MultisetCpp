#ifndef MULTISET_H
#define MULTISET_H
#include <iostream>
#include <exception>
#include <assert.h>
using namespace std;

/*
TODO
- cavare i *prev
- implementare operator<<
- Elementi devono essere immutabili

- test vari
- commenti e doc
- relazione
- test valgrind
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
	size_type objects_amount;
	size_type nodes_amount;

public:

	/**
	 * Costruttore di default.
	 */
	multiset(void) : head(0), objects_amount(0), nodes_amount(0) {
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
	multiset(const multiset &other) : head(0), objects_amount(0), nodes_amount(0) {
		node *tmp = other.head;
		try {
			while (tmp != 0) {
				add(tmp->object, tmp->amount);
				tmp = tmp->next;
			}
		} catch (...) {
			clear();
			throw;
		}
	}

	/**
	 * Operatore Assegnamento.
	 */
	multiset &operator=(const multiset &other) {
		if (this != other) {
			multiset tmp(other);
			std::swap(this->head, temp.head);
			std::swap(this->objects_amount, objects_amount);
			std::swap(this->nodes_amount, nodes_amount);
		}
		return *this;
	}

	/**
	 * //(!)Operatore Assegnamento Templato.
	 */
	/*template<typename Q>
	multiset &operator=(const multiset<Q> &other) {
		multiset<T> ms;
		try {
			node *tmp = other.get_head();
			while (tmp != 0) {
				ms.add(static_cast<T>(tmp->object), tmp->amount);
				tmp->next;
			}
		} catch (...) {
			cout << "ERRORE: static_cast fallito." << endl;
			throw;
		}
		return *this;
	}*/

	/**
	 * Add.
	 * Operazione di aggiunta elemento.
	 */
	void add(const T &obj) {
		add(obj, 1);
	}

private:

	/**
	* Add overload.
	* Operazione di aggiunta elemento multiplo privata.
	*/
	void add(const T &obj, size_type n) {
		node *t = head;
		bool found = false;
		while (t != 0) {
			if (t->object == obj) {
				//se l'oggetto è già presente allora aumentane la quantità di n
				found = true;
				t->amount += n;
				t = 0;
			} else {
				t = t->next;
			}
		}
		if (!found) {
			//altrimenti aggiungi nodo
			if (head == 0) {
				head = new node(obj);
				head->amount = n;
			} else {
				node *tmp = head;
				head = new node(obj, tmp);
				head->amount = n;
				tmp->prev = head;
			}
			nodes_amount++;
		}
		objects_amount += n;
	}

public:

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
						n->prev = p;
					}
					if (p != 0) {
						p->next = n;
					}
					delete tmp;
					nodes_amount--;
				}
				objects_amount--;
				removed = true;
				tmp = 0;
			} else {
				tmp = tmp->next;
			}
		}
		return removed;
	}

	/**
	* Numero elementi del multiset (contando i duplicati).
	*/
	size_type get_objects_amount() {
		return objects_amount;
	}

	/**
	* Numero elementi del multiset (contando i duplicati).
	*/
	size_type get_objects_amount() const {
		return objects_amount;
	}

	/**
	* Numero nodi nel multiset (numero di oggetti senza contare duplicati).
	*/
	size_type get_nodes_amount() {
		return nodes_amount;
	}

	/**
	* Numero nodi nel multiset (numero di oggetti senza contare duplicati).
	*/
	size_type get_nodes_amount() const {
		return nodes_amount;
	}

	/**
	* Conta numero di occorrenze di un oggetto nel multiset.
	*/
	size_type object_count(T &obj) {
		node *tmp = head;
		size_type count = 0;
		while (tmp != 0) {
			if (obj == tmp->object) {
				count = tmp->amount;
				tmp = 0;
			} else {
				tmp = tmp->next;
			}
		}
		return count;
	}

	/**
	* Conta numero di occorrenze di un oggetto nel multiset.
	*/
	size_type object_count(T &obj) const {
		node *tmp = head;
		size_type count = 0;
		while (tmp != 0) {
			if (obj == tmp->object) {
				count = tmp->amount;
				tmp = 0;
			} else {
				tmp = tmp->next;
			}
		}
		return count;
	}

	/**
	* Conta numero di occorrenze di un oggetto nel multiset.
	*/
	size_type object_count(const T &obj) {
		node *tmp = head;
		size_type count = 0;
		while (tmp != 0) {
			if (obj == tmp->object) {
				count = tmp->amount;
				tmp = 0;
			} else {
				tmp = tmp->next;
			}
		}
		return count;
	}

	/**
	* Conta numero di occorrenze di un oggetto nel multiset.
	*/
	size_type object_count(const T &obj) const {
		node *tmp = head;
		size_type count = 0;
		while (tmp != 0) {
			if (obj == tmp->object) {
				count = tmp->amount;
				tmp = 0;
			} else {
				tmp = tmp->next;
			}
		}
		return count;
	}

	/**
	 * Contains.
	 *
	 */
	bool contains(T &obj) {
		/*node *tmp = head;
		bool found = false;
		while (tmp != 0) {
			if (obj == tmp->object) {
				found = true;
				tmp = 0;
			} else {
				tmp = tmp->next;
			}
		}
		return found;*/
		return object_count(obj) > 0;
	}

	/**
	* Operatore ==.
	*
	*/
	bool &operator== (const multiset &other) {
		bool equals = true;
		if (objects_amount == other.get_objects_amount() && nodes_amount == other.get_nodes_amount()) {
			node *tmp = head;
			while (tmp != 0) {
				if (object_count(tmp->object) != other.object_count(tmp->object)) {
					equals = false;
					tmp = 0;
				} else {
					tmp = tmp->next;
				}
			}
		} else {
			equals = false;
		}
		return equals;
	}

	/**
	* Operatore ==.
	*
	*/
	bool &operator== (const multiset &other) const {
		bool equals = true;
		if (objects_amount == other.get_objects_amount() && nodes_amount == other.get_nodes_amount()) {
			node *tmp = head;
			while (tmp != 0) {
				if (object_count(tmp->object) != other.object_count(tmp->object)) {
					equals = false;
					tmp = 0;
				} else {
					tmp = tmp->next;
				}
			}
		} else {
			equals = false;
		}
		return equals;
	}

	//Forward Iterators Const
	/**
	 * Forward Iterator di sola lettura
	 */
	class const_iterator;

	class const_iterator {
	private:
		friend class multiset<T>;
		const node *curr;
		size_type n;

		const_iterator(const node *ptr) {
			curr = ptr;
			n = 0;
		}

	public:

		/**
		 * Costruttore di default.
		 */
		const_iterator() : curr(0), n(0) { }

		/**
		* Copy Constructor.
		*/
		const_iterator(const const_iterator &other) : curr(other.curr), n(other.n) { }

		/**
		* Operatore Assegnamento.
		*/
		const_iterator& operator= (const const_iterator &other) {
			curr = other.curr;
			n = other.n;
			return *this;
		}

		/**
		* Distruttore.
		*/
		~const_iterator() { }

		/**
		* Dereferenziamento per reference.
		*/
		const T &operator*() const {
			return curr->object;
		}

		/**
		* Dereferenziamento per puntatore.
		*/
		const T * operator->() const {
			return &(curr->object);
		}

		/**
		 * Post-incremento
		 * @return l'iteratore alla pair precedente
		 */
		const_iterator operator++(int) {
			const_iterator tmp(*this);
			if (n == curr->amount - 1) {
				curr = curr->next;
				n = 0;
			} else {
				n++;
			}
			return tmp;
		}

		/**
		 * Pre-incremento
		 * @return l'iteratore alla pair successiva
		 */
		const_iterator& operator++() {
			if (n == curr->amount - 1) {
				curr = curr->next;
				n = 0;
			} else {
				n++;
			}
			return *this;
		}

		/**
		Confronto (uguaglianza)
		@other iteratore da confrontare
		@return true se i due iteratori puntano alla stessa posizione
		*/
		bool operator==(const const_iterator &other) const {
			return curr == other.curr && n == n.other;
		}

		/**
		Confronto (diversita')
		@other iteratore da confrontare
		@return false se i due iteratori puntano alla stessa posizione
		*/
		bool operator!=(const const_iterator &other) const {
			return curr != other.curr || n != other.n;
		}
	};

	/**
	* Iteratore di inizio sequenza
	* @return l'iteratore di inizio sequenza
	*/
	const_iterator begin() const {
		return const_iterator(head);
	}

	/**
	* Iteratore di fine sequenza
	* @return l'iteratore di fine sequenza
	*/
	const_iterator end() const {
		return const_iterator(0);
	}



	//DEBUG
	/**
	 * Print.
	 */
	void print() {
		node *tmp = head;
		while (tmp != 0) {
			cout << "--------------------------" << endl;
			cout << "-- object : " << tmp->object << " --" << endl;
			cout << "-- amount : " << tmp->amount << " --" << endl;
			cout << "--------------------------" << endl;
			tmp = tmp->next;
		}
	}

};

template <typename T>
std::ostream & operator<<(std::ostream &os, const multiset<T> &ms) {
	multiset<T>::const_iterator it = ms.begin();
	const T *curr = 0;
	unsigned int x = 1;
	os << "{";
	for (; it != ms.end(); ++it) {
		if (curr != &(*it)) {
			os << "<" << *it << ", " << ms.object_count(*it) << ">";
			if (x < ms.get_nodes_amount()) {
				os << ", ";
			}
			++x;
		}
		curr = &(*it);
	}
	os << "}";
	return os;
}
#endif
