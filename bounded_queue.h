#ifndef CPPUTIL_CPP_UTIL_BOUNDEDQUEUE_H
#define CPPUTIL_CPP_UTIL_BOUNDEDQUEUE_H

#include <vector>

using namespace std;
namespace Util {

template<typename T>
class BoundedQueue {
public:
    BoundedQueue(size_t capacity);
    virtual ~BoundedQueue();

public:
    void Clear();
    bool Empty();
    bool Full();
    size_t Size();
    size_t Capacity();
    void Push();
    T Pop();

private:
    size_t mHead;
    size_t mTail;
    size_t mSize;
    const size_t mCapacity;
    vector<T> mCircularBuf;
};

} //end Util namespace
#endif //CPPUTIL_CPP_UTIL_BOUNDEDQUEUE_H
