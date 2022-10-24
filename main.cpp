#include <iostream>
#include<bits/stdc++.h>


using namespace std;


template <class T>
class smart_array {
    T *arr;
    int minimum = 5;
    int doubles = 2;
    int size{};

public:
    /// constructor
    smart_array() {
        arr = new T[minimum];
        size = 0;
    }
    smart_array(const smart_array &ob);
    ~smart_array();


    /// push back
    void append(T element) {
        if(size == minimum) {
            resize();
        }
        arr[size] = element;
        size++;

    }

    void deleteAt(int pos) {
        if((pos > size) || (pos < 0)) {
            cout << "enter valid index";
            return;
        }

        for(int i = pos; i <= size; i++) {
            arr[i] = arr[i+1];
        }
        size--;
    }

    void insertAt(int element, int pos) {
        if((pos > size) || (pos < 0)) {
            cout << "enter valid index";
            return;
        }

        if(size == minimum) {
            resize();
        }

        size++;

        for(int i = size - 1; i >= pos; i--) {
            if(i == pos) {
                arr[i] = element;
            } else {
                arr[i] = arr[i-1];
            }
        }
    }

    void insertAt_string(string element, int pos) {
        if((pos > size) || (pos < 0)) {
            cout << "enter valid index";
            return;
        }

        if(size == minimum) {
            resize();
        }

        size++;

        for(int i = size - 1; i >= pos; i--) {
            if(i == pos) {
                arr[i] = element;
            } else {
                arr[i] = arr[i-1];
            }
        }
    }


    int length() {
        return size;
    }

    /// doublicate capacity if it has to and deletes reference to current arr.
    void resize() {
        minimum *= doubles;
        T *temp = new T[minimum];
        copy(temp);
        delete [] arr;
        arr = temp;

    }

    /// copy origin array into temp
    void copy(T temp[]) {
        for(int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }
    }

     T& operator[]( int index)
     {
        return arr[index];
    }

};

template<class T>

///copy constructor
smart_array<T>::smart_array (const smart_array &ob) //obj1 = obj2 , smart_array obj2(obj1)
{
    arr = ob.arr;
    size = ob.size;
}

///Destructor
template<class T>
smart_array<T>::~smart_array(){}


int main() {
    smart_array<int> play;
    play.append(3);
    play.append(4);
    play.append(5);
    play.append(4);
    play.append(33);
    play.append(3);
    play.append(18);
    play.append(165);
    play.deleteAt(4);
    play.insertAt(555,4);
    cout<<"the value in this index = "<<play.operator[](4)<<endl;
    cout<<"The current size in array  = "<<play.length()<<endl;
    cout<<endl;

    /*
    smart_array<int> ply;
    ply = play;
    cout<< "Copy constructor "<<ply.operator[](4)<<endl;
    cout << "copy constructor size = "<<ply.length() <<endl;

    cout<<endl;
     */
    smart_array<char> play2;

    play2.append('a');
    play2.append('b');
    play2.append('c');
    play2.append('d');
    play2.append('e');
    play2.deleteAt(4);
    play2.insertAt('m',4);
    cout<< "the character  in this index =  "<<play2[4]<<endl;
    cout<<"the current size in array = "<<play2.length()<<endl;
    cout << endl;

    /*
    smart_array<char> play22(play2);
    cout << " copy constructor " << play22.operator[](4)<<endl;
    cout<<"the current size in array = "<<play22.length()<<endl;
    cout<<endl;
     */


    smart_array<string> play3;
    play3.append("abn");
    play3.append("bvbnm");

    play3.deleteAt(1);

    play3.insertAt_string("maria",1);

    cout<<"the string in this index = "<<play3.operator[](1)<<endl;
    cout<<"the current size in array =  "<<play3.length()<<endl;
    cout<<endl;

    return 0;
}
