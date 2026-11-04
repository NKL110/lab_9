# lab_9


[실습9]

1. 본인이름학번의 네임스페이스

-본인이름학번 네임스페이스 예: 이름이 김프로이고 학번이 3727500일 경우 KimPro3727500

using 지시자는 cpp파일에서는 영역 { block } 안에서 사용, 헤더파일엔 using 지시자는 사용하지 않고 네임스페이스 지정자를 사용합니다.

-using 지시자 예: { using namespace std; cout << "Enter your id: "; }

-네임스페이스 지정자 예: std::cout << "Enter your id: ";



2. 클래스1.h: 지난 과제에서 만든 클래스1 사용



3. 클래스1Ptr.h: 클래스1Ptr 클래스 정의

1의 본인이름학번의 네임스페이스 안에 클래스를 정의하고 멤버함수들도 모두 인라인으로 구현합니다. 

private 멤버변수 선언: 클래스1형을 가리키는 포인터

public 멤버함수 정의

-생성자, 소멸자, 복사생성자, 복사=연산자, 이동생성자, 이동=연산자

-print: 멤버변수가 가리키는 데이터가 있을 경우 표준스트림으로 출력, 없으면 no data (nullptr) 출력



4. main.cpp: 테스트

원하는 값으로 클래스1Ptr형 객체1 생성, 출력

클래스1Ptr형 객체1 값으로 클래스1Ptr형 객체2 생성, 출력 

클래스1Ptr형 객체2를 이동시켜 클래스1Ptr형 객체3 생성, 객체2와 객체3 출력

클래스1Ptr형 객체2에 클래스1Ptr형 객체3을 이동시켜 할당

클래스1Ptr형 객체3에 객체2를 복사할당



클래스1Ptr형을 가리키는 unique_ptr 객체1을 선언

클래스1Ptr형을 가리키는 unique_ptr 객체2를 선언하면서 원하는 값으로 초기화 (make_unique 사용)

unique_ptr 객체1에 unique_ptr 객체2를 이동, unique_ptr 객체1이 가리키는 값을 출력



클래스1Ptr형을 가리키는 shared_ptr 객체1을 선언하면서, 원하는 값으로 초기화

클래스1Ptr형을 가리키는 shared_ptr 객체2를 선언하면서 shared_ptr 객체1로 초기화

shared_ptr 객체1에서 use_count 멤버함수 호출한 값을 출력

shared_ptr 객체2에서 use_count 멤버함수 호출한 값을 출력

클래스1Ptr형을 가리키는 weak_ptr 객체1을 선언하면서 shared_ptr 객체1로 초기화

shared_ptr 객체1에서 use_count 멤버함수 호출한 값을 출력

shared_ptr 객체2에서 use_count 멤버함수 호출한 값을 출력

shared_ptr 객체1에서 reset 멤버함수를 호출한 후

shared_ptr 객체1에서 use_count 멤버함수 호출한 값을 출력

shared_ptr 객체2에서 use_count 멤버함수 호출한 값을 출력

weak_ptr 객체1에서 expired 멤버함수를 호출하여 expired가 아니면 (메모리가 있으면)

weak_ptr 객체1에서 lock 멤버함수를 호출한 값을 shared_ptr 객체1에 할당 후 

shared_ptr 객체1에서 use_count 멤버함수 호출한 값을 출력

shared_ptr 객체2에서 use_count 멤버함수 호출한 값을 출력
