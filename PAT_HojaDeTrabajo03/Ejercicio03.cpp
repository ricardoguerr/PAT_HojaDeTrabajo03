#include "Ejercicio03.h"

Node<int>* Ejercicio03::copyList(Node<int>* head)
{
    if (head == nullptr) {
        return nullptr;
    }

    Node<int>* original = head;
    while (original != nullptr) {
        Node<int>* copy = new Node<int>{ original->value, nullptr, nullptr };
        copy->next = original->next;
        original->next = copy;
        original = copy->next;
    }

    original = head;
    while (original != nullptr) {
        if (original->random != nullptr) {
            original->next->random = original->random->next;
        }
        original = original->next->next;
    }

    Node<int>* copyHead = head->next;
    original = head;
    while (original != nullptr) {
        Node<int>* copy = original->next;
        original->next = copy->next;
        original = original->next;
        if (original != nullptr) {
            copy->next = original->next;
        }
    }

    return copyHead;
}
