#include <iostream>

using namespace std;

template <class T> class SmartPointer {

public:
  T* ref;
  unsigned int* ref_count;

  SmartPointer(T* ptr) {
    ref = ptr;
    ref_count = new unsigned int(1);
  }

  SmartPointer(SmartPointer<T>& sptr) {
    ref = sptr.ref;
    ref_count = sptr.ref_count;
    ++(*ref_count);
  }

  SmartPointer<T>& operator=(SmartPointer<T>& sptr) {
    if (this == &sptr) return *this;

    if (*ref_count > 0) remove();

    ref = sptr.ref;
    ref_count = sptr.ref_count;
    ++(*ref_count);
    return *this;
  }

  ~SmartPointer() {
    remove();
  }

  T getValue() {
    return *ref;
  }

protected:
  void remove() {
    --(*ref_count);
    if (*ref_count == 0) {
      cout << "deleting pointer to " << getValue() << endl;
      delete ref;
      delete ref_count;
      ref = NULL;
      ref_count = NULL;
    }
  }

};


int main() {
  int* a = new int(1);
  SmartPointer<int> aptr(a);
  int* b = new int(2);
  SmartPointer<int> bptr(b);
  cout << "a: " << aptr.getValue() << endl;
  cout << "b: " << bptr.getValue() << endl;
  cout << "assign b = a" << endl;
  bptr = aptr;
  cout << "b: " << bptr.getValue() << endl;
  
}
