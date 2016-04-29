#ifndef CPPUTIL_CPP_UTIL_LOCALVECTOR_H
#define CPPUTIL_CPP_UTIL_LOCALVECTOR_H

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;
namespace Util {

const size_t MIN_BUFFER_SIZE = 16;

template <typename T>
class LocalVector {
public:
    typedef const T* const_iterator;
    typedef T* iterator;

public:
    LocalVector();
    LocalVector(const LocalVector<T>& vec);
    LocalVector(const_iterator begin, const_iterator end);
    LocalVector(size_t size, const T& t);
    virtual ~LocalVector();

public:
    void operator=(const LocalVector<T>& vec);

private:
    bool Init();

public:
    T& operator[](size_t i);
    const T& operator[] (size_t i) const;
    void push_back(const T& t);
    void resize(size_t size);
    bool empty() const ;
    size_t size() const;
    size_t capacity() const;
    void clear();

public:
    const_iterator begin() const {
        return mPtr;
    }

    const_iterator end() const {
        return mPtr+mSize;
    }

    iterator begin() {
        return mPtr;
    }

    iterator end() {
        return mPtr+mSize;
    }

private:
    T* mPtr;
    size_t mSize;
    size_t mCapacity;
};

template <typename T>
LocalVector<T>::LocalVector() {
    assert(Init());
}

template <typename T>
LocalVector<T>::LocalVector(const LocalVector<T>& vec) {
    assert(Init());
    // call operator= function
    *this = vec;
}

template <typename T>
LocalVector<T>::LocalVector(const_iterator begin, const_iterator end) {
    assert(Init());
    while(begin != end) {
        push_back(*begin++);
    }
}

template <typename T>
LocalVector<T>::LocalVector(size_t size, const T& t) {
    assert(Init());
    while(size--) {
        push_back(t);
    }
}

template <typename T>
LocalVector<T>::~LocalVector() {
    free(mPtr);
    mPtr = NULL;
}

template <typename T>
void LocalVector<T>::operator=(const LocalVector<T>& vec) {
    mSize = vec.size();
    mCapacity = vec.capacity();
    // copy vec ptr to this ptr
    memcpy(mPtr, vec.mPtr, sizeof(T)*mSize);
}

template <typename T>
bool LocalVector<T>::Init() {
   // first Init capacity equal min_buffer_size
   mPtr = (T*)malloc(sizeof(T)*MIN_BUFFER_SIZE);
   assert(mPtr);
   mSize = 0;
   mCapacity = MIN_BUFFER_SIZE;
   return true;
}

template <typename T>
T& LocalVector<T>::operator[](size_t i) {
   return mPtr[i];
}

template <typename T>
const T& LocalVector<T>::operator[] (size_t i) const {
    return mPtr[i];
}
    
template <typename T>
void LocalVector<T>::push_back(const T& t) {
    // when buffer has full, resize double size
    if(mSize == mCapacity) {
        resize(mCapacity*2);
    }
    mPtr[mSize++] = t;
}

template <typename T>
void LocalVector<T>::resize(size_t size) {
    if(size <= mCapacity) {
        return;
    }
    // new ptr
    T* newPtr = (T*)malloc(sizeof(T)*size);
    assert(newPtr);
    // copy old data to new ptr
    memcpy(newPtr, mPtr, sizeof(T)*mCapacity);
    // delete old ptr, reset new ptr and capacity
    free(mPtr);
    mPtr = newPtr;
    mCapacity = size;
}

template <typename T>
bool LocalVector<T>::empty() const {
    return mSize == 0;
}

template <typename T>
size_t LocalVector<T>::size() const {
    return mSize;
}

template <typename T>
size_t LocalVector<T>::capacity() const {
    return mCapacity;
}

template <typename T>
void LocalVector<T>::clear() {
    free(mPtr);
    mPtr = NULL;
    assert(Init());
}

template <typename T>
ostream& operator<<(ostream& os, const LocalVector<T>& vec) {
    if(vec.empty()) {
        return os << "[]";
    }
    os << "[\"" << vec[0];
    size_t vecSize = vec.size();
    for(size_t i = 1; i < vecSize; i++) {
        os << "\", \"" << vec[i];
    }
    os << "\"]";
    return os;
}

} //end namespace Util
#endif //CPPUTIL_CPP_UTIL_LOCALVECTOR_H
