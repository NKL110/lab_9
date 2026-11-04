
#ifndef STUDENT_PTR_H
#define STUDENT_PTR_H //??


#include <iostream>
#include "student.h"

namespace LeeNaKyung2593202 {

class studentPtr { 
    private:
    student* ptr;


    public: 
inline studentPtr() : ptr(nullptr) {} // 1. 기본 생성자
// 포인터를 인자로 받는 생성자 (객체 생성 편의용)
    inline explicit studentPtr(student* p) : ptr(p) {}

    // 2. 소멸자
    inline ~studentPtr() {
        delete ptr;
        ptr = nullptr;
    }
// 3. 복사 생성자 (깊은 복사)
    inline studentPtr(const studentPtr& copy) {
        if (copy.ptr != nullptr) {
            ptr = new student(*(copy.ptr)); // student의 복사 생성자 호출
        } else {
            ptr = nullptr;
        }
    }

studentPtr& operator= (const studentPtr& copy) {
    if (this == &copy) {
        return *this;
    }
    delete ptr; 
    ptr = nullptr;

    if (copy.ptr != nullptr) {
        ptr = new student(*(copy.ptr)); // student의 복사 생성자 호출
    } 
    else {
        ptr = nullptr;
    }

    return *this;
}
inline studentPtr(studentPtr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr; // 소유권 이전
    }

    // 6. 이동 대입 연산자
    inline studentPtr& operator=(studentPtr&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        delete ptr;
        ptr = other.ptr;
        other.ptr = nullptr; // 소유권 이전
        return *this;
    }
// 7. print 멤버 함수
    inline void print() const {
        if (ptr != nullptr) {
            std::cout << *ptr; // student 클래스의 operator<< 활용
        } else {
            std::cout << "no data (nullptr)\n";
        }
    }

}; }
#endif

