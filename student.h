#pragma once
#include <string>
// #include <cstdlib>
#include <iostream>

namespace LeeNaKyung2593202{

class student {

	std::string name{};

	int id{};
	int score{};
	char grade{};	

	void testId(){
		if (id < 1000000 || id > 9999999)
			{std::cout << "Invalid ID\n";
			std::exit(1);}
        }
	void testScore(){
		if (score < 0 || score > 100){
			std::cout << "Invalid score\n";
			std::exit(1);}
	    }

	void calGrade(){
        if (score>= 90) grade='A';
        else if (score>=80) grade= 'B';
        else if (score>=70) grade= 'C';
        else if (score>=60) grade= 'D';
        else grade= 'F';
    }

public:

	student(const std::string& n = "no name yet", int d = 1234567, int s = 0) 
    : name{n}, id{d}, score{s} {
		testId(); testScore(); calGrade();
	}

	void input(){
		std::cout << "Enter name: "; std::getline(std::cin >> std::ws, name);
		std::cout << "Enter id: ";   std::cin >> id; testId();
		std::cout << "Enter score: ";std::cin >> score; testScore();
        calGrade();
	}

	friend std::istream& operator>>(std::istream& is, student& s){
		std::cout << "Enter name: "; std::getline(is >> std::ws, s.name);
		std::cout << "Enter id: ";	 is >> s.id; s.testId();
		std::cout << "Enter score: ";is >> s.score; s.testScore();
		s.calGrade();
		return is;
	}
	void setName(const std::string& n){name = n;}
	void setId(int d){id = d; testId();}
	void setScore(int s){score = s; testScore();}
    void setGrade(char g){grade=g;}
	
	void print() const {
		std::cout << name << "(" << id << "):" << score << "(" << grade << ")\n";
	}

	friend std::ostream& operator<<(std::ostream& os, const student& s) {
		os << s.name << "(" << s.id << "):" << s.score << "(" << s.grade << ")\n";
		return os;
	}

	const std::string& getName() const {return name;}

	int getId() const {return id;}
	int getScore() const {return score;}
	char getGrade() const{return grade;}
    student& operator +=(int s) {
        score + = s;  if (score>100) score =100;
        calGrade ();
        return *this;
    }

	student& operator++(){ ++score; calGrade(); return *this; }
	student operator++(int){ 
        student temp(*this);
        ++(*this); 
        return temp;
    }

	friend bool operator==(const student& s1, const student& s2) { return s1.id == s2.id;}
	friend int operator+(const student& s1, const student& s2) { return s1.score + s2.score;}

};
}






1-7. 입력연산자오버로딩에서도 grade를 입력하는 부분을 삭제하고 calGrade함수를 호출합니다. 

1-8. setGrade 함수에 testGrade함수 호출을 삭제합니다. 

1-9. 전위증가연산자, 후위증가연산자를 this를 이용해서 구현하세요. 리턴형식도 참조가 필요하면 참조로 리턴하게 변경하세요. calGrade함수도 필요하면 호출하세요.

1-10. 복합할당연산자 +=를 구현하세요. 매개변수는 int, this를 이용하세요. score에 매개변수를 더하고 score가 100보다 커지면 score에 100을 할당하세요. 변경된 score값에 따라 grade도 변경하세요. 



2. studentRoster.h파일에 studentRoster class를 인라인으로 구현하려고 합니다. 다음을 확인하여 studentRoster.h파일을 완성해보세요. 파일명 명시하고 코드를 작성하세요. 

2-1. 헤더가드, 전처리지시자를 넣으세요.

2-2. 상수 max(maxStudent)를 30으로 선언합니다. 

2-3. 본인이름학번의 네임스페이스안에 studentRoster class를 정의하세요.

2-4. 멤버변수는 3개: std::string형의 courseName, student형의 max개의 std::array형 studentArray, int형의 n(numOfStudent)

2-5. 생성자: 매개변수 1개, courseName 초기화, n(numOfStudent)은 0으로 초기화

2-6. addStudent멤버함수(매개변수는 const student&형): n(numOfStudent)이 max(maxStudent)보다 크거나 같으면 프로그램종료, studentArray의 n(numOfStudent)인덱스변수에 매개변수 할당, n(numOfStudent)값은 +1

2-7. print멤버함수: 표준스트림으로 courseName와 studentArray를 출력, 이때 studentArray는 student형 n(numOfStudent)개 출력해야 합니다.

2-8. getCourseName, setCourseName 함수를 참조를 이용하여 정의하세요.  

2-9. const 멤버함수가 필요한 경우 const 멤버함수로 정의하세요. 



3. main.cpp파일에 테스트 코드를 작성합니다. 다음을 확인하여 테스트 코드를 완성해보세요. 파일명 명시하고 코드를 작성하세요. 

3-1. 전처리지시자를 넣으세요. 

3-2. main을 작성합니다. 

3-2-1. student형 객체3개를 선언하고 원하는 값으로 초기화합니다. 

3-2-2. studentRoster형을 가리키는 포인터변수를 선언하고 원하는 값으로 초기화하여 동적으로 할당합니다.  

3-2-3. studentRoster형을 가리키는 포인터변수에서 addStudent멤버함수를 호출하는데 인자를 3-2-1에서 선언한 객체를 넣습니다. 즉, addStudent멤버함수를 3번 호출합니다. 

3-2-4. studentRoster형을 가리키는 포인터변수에서 print멤버함수를 호출합니다. 

3-2-5. studentRoster형을 가리키는 포인터변수에서 동적으로 할당한 메모리를 해제합니다. 



4. 컴파일한 후 실행했을 때 예상되는 터미널창을 작성하세요. 