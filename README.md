# lab_9
[중간고사]

다음은 실습시간에 다룬 student 클래스입니다. 

class student {

	std::string name{};

	int id{};

	int score{};

	char grade{};	

	void testId(){

		if (id < 1000000 || id > 9999999)

			std::cout << "Invalid ID\n";

			std::exit(1);

	}

	void testScore(){

		if (score < 0 || score > 100)

			std::cout << "Invalid score\n";

			std::exit(1);

	}

	void testGrade(){

		if (grade < 'A' || grade > 'F')

			std::cout << "Invalid grade\n";

			std::exit(1);

	}

public:

	student(const std::string& n = "no name yet", int d = 1234567, int s = 0, char g = 'F') : name{n}, id{d}, score{s}, grade{g}{

		testId(); testScore(); testGrade();

	}

	void input(){

		std::cout << "Enter name: "; std::getline(std::cin >> std::ws, name);

		std::cout << "Enter id: ";   std::cin >> id; testId();

		std::cout << "Enter score: ";std::cin >> score; testScore();

		std::cout << "Enter grade: ";std::cin >> grade; testGrade();

	}

	friend std::istream& operator>>(std::istream& is, student& s){

		std::cout << "Enter name: "; std::getline(is >> std::ws, s.name);

		std::cout << "Enter id: ";	 is >> s.id; s.testId();

		std::cout << "Enter score: ";is >> s.score; s.testScore();

		std::cout << "Enter grade: ";is >> s.grade; s.testGrade();

		return is;

	}

	void setName(const std::string& n){name = n;}

	void setId(int d){id = d; testId();}

	void setScore(int s){score = s; testScore();}

	void setGrade(char g){grade = g; testGrade();}

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

	student operator++(){ return student{name, id, ++score, grade}; }

	student operator++(int){ return student{name, id, score++, grade}; }

	friend bool operator==(const student& s1, const student& s2) { return s1.id == s2.id;}

	friend int operator+(const student& s1, const student& s2) { return s1.score + s2.score;}

};



1. student.h파일에 student class를 인라인으로 구현하려고 합니다. 다음을 확인하여 위 코드를 변경하여 student.h파일을 완성해보세요. 

1-1. 헤더가드, 전처리지시자를 넣으세요.

1-2. 본인이름학번의 네임스페이스안에 student class를 정의하세요.

1-3. testId와 testScore 함수에서 잘못된 부분이 있으면 수정해보세요. 

1-4. testGrade 함수정의를 없애고 calGrade 함수를 private 멤버함수로 구현합니다. calGrade함수는 score값에따라 grade를 할당: 90점이상이면 'A', 80점이상이면 'B", 70점 이상이면 'C', 60점 이상이면 'D', 그 외는 'F' 

1-5. 생성자의 매개변수를 3개로 변경하고, grade에 값을 초기화시키는 부분을 삭제, testGrade 함수 호출 대신 calGrade함수를 호출합니다. 

1-6. input함수에서 grade를 입력하는 부분을 삭제하고 calGrade함수를 호출합니다. 

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



[커밋 및 푸시]

-🖱🔀[소스제어]에 가서 변경 내용을 적고 커밋 및 푸시하세요.

(변경 내용을 적지 않으면 커밋이 되지 않으니 꼭 변경 내용을 적으세요!)

(📸 Commit: 현재 전체 상태를 기록, ⬆️ Push: 서버에 올리기)

-⌨️git 명령어를 이용한 커밋 및 푸시 방법

📟터미널에서 git add . && git commit -m "message" && git push

"message"는 커밋 내용 (예: ✅과제완료, 🐛수정내용, ✨추가, 🔥삭제, 🚀제출 등등)

-📦github에서 직접 커밋하는 방법]🟩[Codespaces]에서 ✅[Commit & Push]가 안 될 경우, 직접 📦github repository의 main.cpp에서 코드를 ✏️편집한 후 🟩[Commit changes...]하세요.

-💥 github repository에서 codespace를 만들어서 로컬에서 작업 후, 커밋&푸시하지 않은 상태에서 github repository에서 직접 commit하여 브랜치가 갈라질 경우 (diverged)

git add . && git commit -m "local changes": 로컬 변경 사항 커밋

git pull --rebase: 원격 커밋 위에 로컬 커밋

git add . && git rebase --continue: 충돌 발생 시 재배치

git push



************************************************

* 실습실 컴퓨터 이용시 실습 종료 후 github 로그아웃! *

************************************************





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
