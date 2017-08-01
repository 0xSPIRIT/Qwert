#pragma once

template <typename T>
struct List {
	void add(const T& t) {
		if (head->value == nullptr) {
			// then that means that this is the first addition to the list.
			head->value = &t;
		} else {
			temp = new NODE;
			temp->value = &t;
			curr->next = temp;
		}
	}
	T& get(int index) {
		if (head->next == nullptr) {
			return *head->value;
		} else {
			temp = nullptr;

			for (int i = 0; i < index; i++) {
				if (temp == nullptr) {
					temp = head;
				} else {
					temp = temp->next;
				}
			}
			return *temp->value;
		}
	}
	int size() {
		int size = 0;
		temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
			size++;
		}
		return size;
	}
private:
	struct NODE {
		T* value;
		NODE* next = nullptr;
	};
	NODE* head = new NODE;
	NODE* curr = head;
	NODE* temp = nullptr;
};