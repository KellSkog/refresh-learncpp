template<typename T>
T& getRef(T *t) {
    
    return t;
}

// Explicit instantiation
template int& getRef<int>(int *t);