3. 클래스1Ptr.h: 클래스1Ptr 클래스 정의

1의 본인이름학번의 네임스페이스 안에 클래스를 정의하고 멤버함수들도 모두 인라인으로 구현합니다. 

private 멤버변수 선언: 클래스1형을 가리키는 포인터

public 멤버함수 정의

-생성자, 소멸자, 복사생성자, 복사=연산자, 이동생성자, 이동=연산자

-print: 멤버변수가 가리키는 데이터가 있을 경우 표준스트림으로 출력, 없으면 no data (nullptr) 출력

#include <iostream>
#include "student.h"

namespace LeeNaKyung2593202 {

class studentPtr { 
    private:
    student* ptr;


    public: 

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



}}
