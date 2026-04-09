Bureaucrat::GradeTooLowException();
:: it means this is belong to Bureaucrat class.

Bureaucrat::GradeTooLowException() --> GradeToolLowException default constructor called

Use throw() or noexcept only when you are 100% sure that no errors will occur.

```text
About noexcept after a function declaration

-This function does not throw exceptions.
-If it does throw, the program will terminate abnormally.
```

```text
About std::exception::what()

-It is also declared with noexcept.
-You must declare it the same way when overriding it, otherwise it will not compile.
```

```text
About throw() (Exception Specification):

-It specifies which exceptions can be thrown.
-When an exception occurs, control leaves the try block and go to the catch block.
```

```text
-thorw
   0x00007ffff7cae490 <+0>:     endbr64 
   0x00007ffff7cae494 <+4>:     push   %r12
   0x00007ffff7cae496 <+6>:     mov    %rdx,%r12
   0x00007ffff7cae499 <+9>:     push   %rbp
   0x00007ffff7cae49a <+10>:    mov    %rsi,%rbp
   0x00007ffff7cae49d <+13>:    push   %rbx
   0x00007ffff7cae49e <+14>:    mov    %rdi,%rbx
   0x00007ffff7cae4a1 <+17>:    nop
   0x00007ffff7cae4a2 <+18>:    call   0x7ffff7ca0d30 <__cxa_get_globals@plt>
   0x00007ffff7cae4a7 <+23>:    mov    %r12,%rdx
   0x00007ffff7cae4aa <+26>:    mov    %rbp,%rsi
   0x00007ffff7cae4ad <+29>:    mov    %rbx,%rdi
   0x00007ffff7cae4b0 <+32>:    addl   $0x1,0x8(%rax)
   0x00007ffff7cae4b4 <+36>:    call   0x7ffff7ca0da0 <__cxa_init_primary_exception@plt>
   0x00007ffff7cae4b9 <+41>:    movl   $0x1,(%rax)
   0x00007ffff7cae4bf <+47>:    lea    0x60(%rax),%rbx
   0x00007ffff7cae4c3 <+51>:    mov    %rbx,%rdi
   0x00007ffff7cae4c6 <+54>:    call   0x7ffff7c9fd60 <_Unwind_RaiseException@plt>
   0x00007ffff7cae4cb <+59>:    mov    %rbx,%rdi
   0x00007ffff7cae4ce <+62>:    call   0x7ffff7c9e830 <__cxa_begin_catch@plt>
   0x00007ffff7cae4d3 <+67>:    call   0x7ffff7c9e2e0 <_ZSt9terminatev@plt>
```