#include <ostream>
#include <stdexcept>
#include "List.h"
using namespace std;

template <typename T> 
class ListArray : public List<T> {

    private:
        // miembros privados
        T* arr;
        int max;
        int n;
        static const int MINSIZE = 2;
        void resize (int newSize) {
            T* newArr = new T[newSize];
            for (int i = 0; i < n; i++) {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
            max = newSize;
        }
    public:
        // miembros públicos, incluidos los heredados de List<T>
        ListArray () {
            arr = new T[MINSIZE];
            n = 0;
            max = MINSIZE;
        }
        
        ~ListArray () {
            delete[] arr;
        }

        T operator[] (int pos) {
            if (pos < 0 || pos >= n) {
                throw out_of_range("Posición fuera de rango");
            }
            return arr[pos];
        }

        friend ostream& operator<<(ostream &out, const ListArray<T> &list) {
            out << "[";
            for (int i = 0; i < list.n; i++) {
                out << list.arr[i];
                if (i < list.n - 1) {
                    out << ", ";
                }
            }
            out << "]";
            return out;
        }

        void insert (int pos, T val) override {
            if (pos < 0 || pos > n) {
                throw out_of_range("Posición fuera de rango");
            }
            if (n == max) {
                resize(max * 2);
            }
            for (int i = n; i > pos; i--) {
                arr[i] = arr[i - 1];
            }
            arr[pos] = val;
            n++;
        }

        void append (T e) override {
            if (n == max) {
                resize(max * 2);
            }
            arr[n] = e;
            n++;
        }

        void prepend (T e) override {
            if (n == max) {
                resize(max * 2);
            }
            for (int i = n; i > 0; i--) {
                arr[i] = arr[i - 1];
            }
            arr[0] = e;
            n++;
        }

        T remove (int pos) override {
            if (pos < 0 || pos >= n) {
                throw out_of_range("Posición fuera de rango");
            }
            T removedElement = arr[pos];
            for (int i = pos; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }
            n--;
            return removedElement;
        }

        T get (int pos) const {
            if (pos < 0 || pos >= n) {
                throw out_of_range("Posición fuera de rango");
            }
            return arr[pos];
        }

        int search (T e) const {
            for (int i = 0; i < n; i++) {
                if (arr[i] == e) {
                    return i;
                }
            }
            return -1;
        }

        bool empty () const {
            return n == 0;
        }

        int size () const {
            return n;
        }   
};
