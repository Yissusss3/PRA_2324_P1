#include <ostream>
#include "List.h"
#include "Node.h"
using namespace std;

template <typename T>
class ListLinked : public List<T> {
    private:
        Node<T>* first;
        int n;

    public:
        ListLinked() : first(nullptr), n(0) {}
        ~ListLinked() {
            Node<T>* aux = first->next;
            while (aux != nullptr) {
                Node<T>* temp = aux;
                aux = aux->next;
                delete temp;
            }
        }
        T operator[] (int pos) {
            if (pos < 0 || pos > n - 1) {
                throw out_of_range("Posición fuera de rango");
            }
            Node<T>* aux = first;
            for (int i = 0; i < pos; i++) {
                aux = aux->next;
            }
            return aux->data;
        }
        friend ostream& operator<<(ostream &out, const ListLinked<T> &list) {
            out << "[";
            Node<T>* aux = list.first;
            for (int i = 0; i < list.n; i++) {
                out << aux->data;
                if (i < list.n - 1) {
                    out << ", ";
                }
                aux = aux->next;
            }
            out << "]";
            return out;
        }
};
