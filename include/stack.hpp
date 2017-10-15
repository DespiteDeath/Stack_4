#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;

template <typename T>
class Stack
{
    size_t array_size_; 
    size_t count_ = 0; 
    T* array_; 

public:

    Stack() : array_size_{100}, array_{new T[array_size_]} {}
    
    Stack(size_t n) : array_size_{n}, array_{new T[n]} {}
    
    // copy
    Stack(const Stack& S) : array_size_{S.array_size_}, count_{S.count_}, array_ {new T[array_size_]}
    {
        copy(S.array_, S.array_ + array_size_, array_);
    }
    
    // move
    Stack(Stack&& S) : array_size_{S.array_size_}, count_{S.count_}, array_{S.array_}
    {
        S.array_ = nullptr;
        S.array_size_ = 0;
        S.count_ = 0;
    }
    
    Stack(size_t size_, size_t count_, T* arr) : array_size_{size_ }, count_{ count_ }, array_{arr} {}
    
    //task
    Stack(initializer_list<T> l) : array_size_ {l.size()}, count_{l.size()}, array_{new T[array_size_]}
    {
        copy(l.begin(), l.end(), array_);
    }
    
    size_t count() const noexcept{ 
        return count_;
    }
    
    void push(T const &value) noexcept{ 
        reinitializeMemory();
        array_[count_] = value;
        ++count_;
    }
    
    void reinitializeMemory() noexcept{
            if (count_ == array_size_){
                T* new_array_ = new T[2*array_size_]; 
            
            for (size_t i = 0; i != array_size_; i++){
                new_array_[i] = array_[i]; 
            }
            delete[] array_; 
            array_ = new_array_; 
        }
    }
    
    void pop() noexcept{
        if (count_ == 0){
            throw runtime_error("Error: epmty stack!");
        }
        --count_;
    }
   
    T top() noexcept{
        if (count_ == 0){
            throw runtime_error("Error: epmty stack!");
        }
        size_t c = count_ - 1;
        return array_[c];
    }
    
    bool empty() noexcept{
        return count_ == 0; //In stack 0 elements, return true, else false
    }
    
    void swap(Stack& S){
        swap(this->array_size_, S.array_size_);
        swap(this->count_, S.count_);
        swap(this->array_, S.array_);
    }
    
    Stack operator = (const Stack& S){
        if(this != &S){
            Stack{S}.swap(*this);
        }
        return *this;
    }
    
    Stack operator = (Stack&& S){
        if(this != &S){
            Stack{ std::move(S) }.swap(*this);
        }
        return *this;
    }
    
    friend auto operator << (ostream& out, const Stack& S) -> ostream& {
        if (S.array_ == nullptr) { out << "Epmty stack"; } 
        else {
            out << "{";
            for (size_t i = 0; i < S.count_; ++i) {
                out <<  " " <<  S.array_[i];
            }
            out << " " << "}";
        }
        return out;
    }
    
    ~Stack<T>(){
        delete[] array_; 
    }
};

#endif /* STACK_HPP */
