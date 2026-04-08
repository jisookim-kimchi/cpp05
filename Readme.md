Bureaucrat::GradeTooLowException();

is it a static fucntion in Bureaurcrat class?
:: it means this is belong to Bureaucrat class.

Bureaucrat::GradeTooLowException() it means

Bureaucrat 클래스 안방에 존재하는 GradeTooLowException 클래스의 객체를 지금 당장 기본 생성자 () 로 하나 찍어내라.

throw() or noexcept를 사용할때 : 무조건 에러가 있는 곳! 

함수선언뒤 noexcept : 
    - 이 함수는 예외를 던지지 않습니다. 
    - 만약 던지면 프로그램이 비정상 종료됩니다.
std::exception::what() : 여기에도 noexcept 가 붙어있다, 억지로라도 똑같이 달아주지 않으면 컴파일 조차 안됨.

throw() : Exception Specificatoin. 발생!
try 탈출 -> catch로 배송완료!
