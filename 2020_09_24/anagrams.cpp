#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

template<class U>
class Node {
	private:
		U val;

};

template<int T, class U>
class HashChain {
	private:
		vector<Node<U> *> hashChain = vector<Node<U> *>(T, nullptr);

		HashChain(HashChain const &) = delete;
		HashChain(HashChain const &&) = delete;

		void operator=(HashChain const &) = delete;
		void operator=(HashChain const &&) = delete;

		bool operator==(HashChain const &) const = delete;
		bool operator==(HashChain const &&) const = delete;
		bool operator!=(HashChain const &) const = delete;
		bool operator!=(HashChain const &&) const = delete;

	public:
		HashChain() {}
		~HashChain() {}

		void insert(U val, int (*indexer)(U const &)) {
			if (!indexer) return;

			int index((*indexer)(val));
			index = index % T;
			Node<U> * & src(hashChain[index]);

			Node<U> * n = new Node<U>(val);
			n->next = src;
			src = n;

			return;
		}

		void remove(U val, int (*indexer)(U const &), bool (*equals)(U const &, U const &)) {
			if (!indexer || !equals) return;

			int index((*indexer)(val));
			index = index % T;

			Node<U> * prev(nullptr);
			Node<U> * itr(hashChain[index]);

			while (itr) {
				if ((*equals)(val,itr->val)) {
					if (prev) {
						prev->next = itr->next;
						delete itr;
						itr = prev->next;
					} else {
						prev = itr;
						itr = itr->next;
						delete prev;
						prev = nullptr;
					}
				} else {
					prev = itr;
					itr = itr->next;
				}
			}

			return;
		}
};

int main() {
	// areAnagrams(string("asdf"), string(""));
	return 0;
}