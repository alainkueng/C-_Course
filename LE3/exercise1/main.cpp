#include <iostream>
#include "vector"

using namespace std;

/*
Implement a dumb_pointer.  Use the operator* and operator->
operators to implement a class that simulates a pointer.
 - Implement another class that works like the dumb_pointer but is called smart_pointer and uses reference counting.
 - No, using any of the C++ auto_ptr, unique_ptr, shared_ptr, weak_ptr classes is not an implementation option
*/

template<typename T>
struct dump_pointer {
private:
    T *obj;
public:
    dump_pointer(T *d) { obj = d; }

    ~dump_pointer() { delete obj; }

    //structure dereference (member b of object pointed to by a)
    //why do we return a pointer?
    T *operator->() { return obj; }

    //TODO: clarify operator naming
    //indirection/dereference?, (object pointed to)
    T &operator*() { return *obj; }
};

class ReferenceCounter {
private:
    int count;

public:
    void add() {
        count++;
    }

    // Decrement and release reference count
    int release() {
        return --count;
    }

    int get_count() {
        return count;
    }
};


template<typename T>
struct smart_pointer {
private:
    T *obj;
    ReferenceCounter *ref;

public:
    smart_pointer() : obj(0), ref(0) {
        ref = new ReferenceCounter();
        ref->add();
    }

    smart_pointer(T *o) : obj(o), ref(0) {
        ref = new ReferenceCounter();
        ref->add();
    }

    // Copy constructor
    // e.g.  smart_pointer<vector<int>> sp2(sp1); where sp1 is already a smartpointer
    smart_pointer(const smart_pointer<T> &ptr) : obj(ptr.obj), ref(ptr.ref) {
        // Copy the data and reference pointer
        // and increment the reference count
        ref->add();
    }

    ~smart_pointer() {
        // Only when ref. count reaches 0 delete data
        if (ref->release() == 0) {
            delete obj;
            delete ref;
        }
    }



    T *operator->() { return obj; }

    // e.g. q = r, where q an r are smartpointers
    smart_pointer<T> &operator=(const smart_pointer<T> &ptr) {
        // Assignment operator
        if (this != &ptr) // Avoid self assignment
        {
            // Decrement the old reference count
            // if reference become zero delete the old data
            // example: q pointing x, check if only one, then delete its object
            // say smrt ptr u also points to x, decreasing will not result to 0, x does not get deleted but
            // reference count to x still needs to be decremented
            if (ref->release() == 0) {
                delete obj;
                delete ref;
            }

            // Copy the data and reference pointer
            // and increment the reference count
            obj = ptr.obj;
            ref = ptr.ref;
            ref->add();
        }
        return *this;
    }

    int count() {
        return ref->get_count();
    }
};


int main() {
    vector<int> *o1 = new vector<int>();
    o1->push_back(1);
    o1->push_back(2);
    dump_pointer<vector<int>> dp1(o1);
    cout << dp1->size() << endl;
    auto pnt1 = *dp1;

    //heap allocation
    vector<int> *s1 = new vector<int>();
    s1->push_back(1);
    s1->push_back(2);

    smart_pointer<vector<int>> sp1(s1);
    cout << "sp1: " << sp1.count() << endl;
    smart_pointer<vector<int>> sp2(sp1);
    cout << "sp2: " << sp2.count() << endl;

    vector<int> *s2 = new vector<int>();
    s2->push_back(1);
    smart_pointer<vector<int>> sp3(s2);
    cout << "sp3: " << sp3.count() << endl;
    sp3 = sp2;

    cout << "sp1: " << sp2.count() << endl;
    cout << "sp2: " << sp2.count() << endl;
    cout << "sp3: " << sp3.count() << endl;

    cout << sp1->size() << " " << sp2->size() << " " << sp3->size() << " " << endl;

    return 0;
}
