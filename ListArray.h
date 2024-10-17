#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
        T* arr;
	int max;
	int n;
	static const int MINSIZE = 2;
	void resize(int new_size){
		if (new_size < MINSIZE) {
           		new_size = MINSIZE;
       		}

        // Crear un nuevo array dinámico de tamaño 'new_size'
        	T* new_arr = new T[new_size];

        // Copiar los elementos actuales del array antiguo al nuevo
        	for (int i = 0; i < n; ++i) {
            		new_arr[i] = arr[i];
        	}
        	delete[] arr;
        	arr = new_arr;
        	max = new_size;
	}

    public:
        ListArray(){
		max = MINSIZE;
		n = 0;
		arr = new T[max];	
	}
	~ListArray(){
		delete[] arr;

	}	
	T operator[](int pos){
		if (pos < 0 || pos >= n) {
           		 throw std::out_of_range("Posición fuera de rango");
       		 }

		return arr[pos];
	}
	friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){

		out << "[";
       		for (int i = 0; i < list.n; ++i) {
            		out << list.arr[i];
            		if (i < list.n - 1) {
                		out << ", "; // Separador entre elementos
            		}
        	}
        	out << "]";
        	return out;
    	}

	void insert(int pos, T e) override {
        	if (pos < 0 || pos > size()) {
            		throw std::out_of_range("Posición inválida para inserción");
        	}
        	arr.insert(arr.begin() + pos, e);
	 }

    
    void append(T e) override {
        arr.push_back(e);
    }

   
    void prepend(T e) override {
        arr.insert(data.begin(), e);
    }

   
    T remove(int pos) override {
        if (pos < 0 || pos >= size()) {
            throw std::out_of_range("Posición inválida para eliminación");
        }
        T removedElement = arr[pos];
        arr.erase(arr.begin() + pos);
        return removedElement;
    }

    
    T get(int pos) override {
        if (pos < 0 || pos >= size()) {
            throw std::out_of_range("Posición inválida");
        }
        return arr[pos];
    }

   
    int search(T e) override {
        for (int i = 0; i < size(); ++i) {
            if (arr[i] == e) {
                return i;
            }
        }
        return -1; 
    }


    bool empty() override {
        return arr.empty();
    }
    
 
    int size() override {
        return arr.size();
    }
};
