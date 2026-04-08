Bureaucrat::GradeTooLowException();
:: it means this is belong to Bureaucrat class.

Bureaucrat::GradeTooLowException() --> GradeToolLowException default constructor called

Use throw() or noexcept only when you are 100% sure that no errors will occur.

```test
About noexcept after a function declaration

-This function does not throw exceptions.
-If it does throw, the program will terminate abnormally.
```

```test
About std::exception::what()

-It is also declared with noexcept.
-You must declare it the same way when overriding it, otherwise it will not compile.
```

```test
About throw() (Exception Specification):

-It specifies which exceptions can be thrown.
-When an exception occurs, control leaves the try block and go to the catch block.
```
