Bureaucrat::GradeTooLowException();

is it a static fucntion in Bureaurcrat class?
:: it means this is belong to Bureaucrat class.

Bureaucrat::GradeTooLowException() --> GradeToolLowException default constructor called

Use throw() or noexcept only when you are 100% sure that no errors will occur.

함수선언뒤 noexcept : 
    - 이 함수는 예외를 던지지 않습니다. 
    - 만약 던지면 프로그램이 비정상 종료됩니다.
std::exception::what() : 여기에도 noexcept 가 붙어있다, 억지로라도 똑같이 달아주지 않으면 컴파일 조차 안됨.

throw() : Exception Specificatoin. 발생!
try 탈출 -> catch로 배송완료!

'''test
About noexcept after a function declaration
This function does not throw exceptions.
If it does throw, the program will terminate abnormally.
'''

'''test
About std::exception::what():

It is also declared with noexcept.
You must declare it the same way when overriding it, otherwise it will not compile.
'''

'''test
About throw() (Exception Specification):

It specifies which exceptions can be thrown (deprecated in modern C++).
When an exception occurs, control leaves the try block and go to the catch block.
'''
