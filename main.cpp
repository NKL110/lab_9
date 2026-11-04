#include <iostream>
#include <memory> //?
#include "student.h"
#include "studentPtr.h"

int main() {
    // 네임스페이스 지정
    using namespace LeeNaKyung2593202;

    std::cout << "=== [1] 클래스1Ptr 객체 생성 및 복사/이동 테스트 ==\n";

    // 1. 원하는 값으로 studentPtr형 객체1 생성, 출력
    studentPtr sp1(new student("Kim", 1234567, 95));
    std::cout << "sp1: ";
    sp1.print();

    // 2. studentPtr형 객체1 값으로 studentPtr형 객체2 생성(복사 생성자), 출력
    studentPtr sp2(sp1);
    std::cout << "sp2 (copied from sp1): ";
    sp2.print();
    std::cout << "sp1 after copy: ";
    sp1.print(); // sp1이 유지되는지 확인

    // 3. studentPtr형 객체2를 이동시켜 studentPtr형 객체3 생성(이동 생성자), 객체2와 객체3 출력
    studentPtr sp3(std::move(sp2));
    std::cout << "sp2 (after move): ";
    sp2.print(); // nullptr 상태 출력 확인
    std::cout << "sp3 (moved from sp2): ";
    sp3.print();

    // 4. studentPtr형 객체2에 studentPtr형 객체3을 이동시켜 할당(이동 대입 연산자)
    sp2 = std::move(sp3);
    std::cout << "sp2 (after move assignment from sp3): ";
    sp2.print();
    std::cout << "sp3 (after move assignment): ";
    sp3.print(); // nullptr 상태 출력 확인

    // 5. studentPtr형 객체3에 객체2를 복사할당(복사 대입 연산자)
    sp3 = sp2;
    std::cout << "sp3 (after copy assignment from sp2): ";
    sp3.print();
    std::cout << "sp2 (source of copy assignment): ";
    sp2.print();

    std::cout << "\n=== [2] 스마트 포인터 (unique_ptr) 테스트 ==\n";
    {
        // studentPtr형을 가리키는 unique_ptr 객체1 선언
        std::unique_ptr<studentPtr> uPtr1;

        // studentPtr형을 가리키는 unique_ptr 객체2를 선언하면서 원하는 값으로 초기화 (make_unique 사용)
        auto uPtr2 = std::make_unique<studentPtr>(new student("Lee", 2345678, 85));

        // unique_ptr 객체1에 unique_ptr 객체2를 이동
        uPtr1 = std::move(uPtr2);

        // unique_ptr 객체1이 가리키는 값을 출력
        std::cout << "uPtr1 points to -> ";
        if (uPtr1) {
            uPtr1->print();
        }
    }

    std::cout << "\n=== [3] 스마트 포인터 (shared_ptr & weak_ptr) 테스트 ==\n";

    // 1. studentPtr형을 가리키는 shared_ptr 객체1을 선언하면서, 원하는 값으로 초기화
    auto sPtr1 = std::make_shared<studentPtr>(new student("Park", 3456789, 75));

    // 2. studentPtr형을 가리키는 shared_ptr 객체2를 선언하면서 shared_ptr 객체1로 초기화
    auto sPtr2 = sPtr1;

    // 3. shared_ptr 객체1, 2에서 use_count 멤버함수 호출한 값 출력
    std::cout << "After sPtr2 initialization:\n";
    std::cout << "sPtr1 use_count: " << sPtr1.use_count() << "\n";
    std::cout << "sPtr2 use_count: " << sPtr2.use_count() << "\n";

    // 4. studentPtr형을 가리키는 weak_ptr 객체1을 선언하면서 shared_ptr 객체1로 초기화
    std::weak_ptr<studentPtr> wPtr1 = sPtr1;

    // 5. shared_ptr 객체1, 2에서 use_count 호출한 값 출력
    std::cout << "After weak_ptr creation:\n";
    std::cout << "sPtr1 use_count: " << sPtr1.use_count() << "\n";
    std::cout << "sPtr2 use_count: " << sPtr2.use_count() << "\n";

    // 6. shared_ptr 객체1에서 reset 멤버함수를 호출한 후
    sPtr1.reset();
    std::cout << "After sPtr1.reset():\n";
    // 7. shared_ptr 객체1, 2에서 use_count 호출한 값 출력
    std::cout << "sPtr1 use_count: " << sPtr1.use_count() << "\n";
    std::cout << "sPtr2 use_count: " << sPtr2.use_count() << "\n";

    // 8. weak_ptr 객체1에서 expired 멤버함수를 호출하여 expired가 아니면(메모리가 있으면)
    if (!wPtr1.expired()) {
        // weak_ptr 객체1에서 lock 멤버함수를 호출한 값을 shared_ptr 객체1에 할당 후
        sPtr1 = wPtr1.lock();
        std::cout << "weak_ptr is not expired, locked back to sPtr1.\n";
    } else {
        std::cout << "weak_ptr is expired.\n";
    }

    // 9. shared_ptr 객체1, 2에서 use_count 호출한 값 출력
    std::cout << "Final use_counts:\n";
    std::cout << "sPtr1 use_count: " << sPtr1.use_count() << "\n";
    std::cout << "sPtr2 use_count: " << sPtr2.use_count() << "\n";
    
    std::cout << "\n=== Test Completed Successfully ==\n";
    return 0;
}