
Absolutely, here's how you can format this in markdown for a README.md file:

markdown
Copy code
# Unit Testing in C: Using Check

## Table of Contents
1. [Introduction](#introduction)
2. [Installing Check](#installing-check)
3. [Compiling check_program.c](#compiling-check-programc)
4. [Building a Template](#building-a-template)
    1. [Creating main() for check_program.c](#creating-main-for-check-programc)
    2. [Creating the Test Suite Runner](#creating-the-test-suite-runner)
    3. [Building a Sample Unit Test](#building-a-sample-unit-test)
5. [Running Unit Test](#running-unit-test)  
    1. [About First Test](#about-first-test)
6. [References](#references)

<a name="introduction"></a>
## Introduction

Welcome to the class on installing and building a test suite using the `check.h` library! As software developers, we strive to create reliable and bug-free code. A crucial part of achieving this goal is through thorough testing. Unit testing, in particular, allows us to verify the individual components of our code and ensure their proper functionality.

Throughout the course, we will cover the installation and setup of the `check.h` library, ensuring that you have the necessary tools and dependencies to build and run your tests. We will guide you through the process of creating a test suite from scratch, discussing essential concepts such as test fixtures, test cases, and assertions.

By the end of this class, you will have a comprehensive understanding of how to install and build a test suite using the `check.h` library effectively. You will be equipped with a reusable template that you can adapt and expand upon for future projects, enabling you to incorporate robust testing practices into your software development workflow.

<a name="installing-check"></a>
## Installing Check

The following link has complete instructions (with examples) for installing `check.h` on your system:

[Check Installation Guide](https://libcheck.github.io/check/web/install.html)

<a name="compiling-check-programc"></a>
## Compiling check_program.c

First and foremost, the `check_program.c` (our unit test source file) file needs to be compiled independently from the `main.c` program. This is because the test suite defined in `check_program.c` requires access to the internal structures and functions of the program being tested. By compiling `check_program.c` separately, we ensure that the necessary dependencies and test-specific logic are isolated and handled correctly.

Separate compilation allows us to focus on testing the specific functionality of our program without introducing unintended side effects. It ensures that the test environment remains independent of the main program's execution flow, variables, and state. This separation enables us to pinpoint and isolate issues in the individual components being tested, making the debugging process more manageable.

<a name="building-a-template"></a>
## Building a Template

Create a new C file named `check_program.c`. Then, add the standard headers and create a `main()` function as usual. At the top of our `check_program.c`, we need to add the following include:

```c
#include <check.h>
```
<a name="creating-main-for-check-programc"></a>
# Creating main() for check_program.c

```c
int main(void)
{
	Suite *suite = check_my_program_suite();

	SRunner *runner = srunner_create(suite);

	srunner_set_fork_status(runner, CK_NOFORK);

	srunner_run_all(runner, CK_VERBOSE);

	int no_failed = srunner_ntests_failed(runner);

	srunner_free(runner);

	return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
```

## main() explained:

Suite *suite = check_my_program_suite(); // ex: test_calculator_suite
- This line creates a pointer to a Suite structure. check_my_program_suite() is a function that you would define somewhere else in your code, and this function should create a suite of tests. In this suite, you add all the test cases you want to run for your program.

SRunner *runner = srunner_create(suite);
- This line creates a test suite runner, i.e., a structure that will manage the execution of the suite and all the included test cases. The suite we created in the previous step is passed as an argument.

srunner_set_fork_status(runner, CK_NOFORK);
- Check supports two ways of running tests: forking mode and no-forking mode. In the forking mode, each test case is run in a separate process, so if it crashes or gets stuck, the rest of the suite can still continue. However, debugging is easier in no-forking mode because you can run the tests and the code being tested in the same process. This line sets the runner to use the no-forking mode.

srunner_run_all(runner, CK_VERBOSE);
- This line runs all the test cases in the suite. The CK_VERBOSE argument means that Check will print detailed information about each test case, including the names of all test cases and whether they passed or failed.

int no_failed = srunner_ntests_failed(runner);
- This line gets the number of test cases that failed. srunner_ntests_failed() is a function that returns this count.

srunner_free(runner);
- This line frees all memory associated with the runner. After calling this function, the runner should not be used again.

return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
- Finally, the main() function returns a success status if all test cases passed (i.e., no_failed == 0), and a failure status if any test cases failed.

<a name="creating-the-test-suite-runner"></a>
# Creating the Test Suite Runner

```c
Suite *check_program_suite(void)
{
    Suite *suite;
	TCase *tc_core;

	suite = suite_create("my_program_test");

	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, test_func_1);
	tcase_add_test(tc_core, test_func_2);
	suite_add_tcase(suite, tc_core);

	return suite;
}
```
## Test Suite Runner Explained:
Suite *suite;
TCase *tc_core;
- These lines declare a pointer to a Suite structure and a pointer to a TCase structure. A Suite is a collection of multiple test cases (TCase).

suite = suite_create("my_program_test");
- This line creates a new test suite named "my_program_test".

tc_core = tcase_create("Core");
- This line creates a new test case named "Core"

tcase_add_test(tc_core, test_func_1);
tcase_add_test(tc_core, test_func_2);
- These lines add test functions test_func_1 and test_func_2 to the test case tc_core. These test functions should be void functions that take no arguments, and they should use Check's assertion macros to verify the behavior of your code.

suite_add_tcase(suite, tc_core);
- This line adds the test case tc_core (which includes test_func_1 and test_func_2) to the suite suite.

return suite;
- Finally, this line returns the suite, which includes all of the test cases you've added. This returned suite can be used in the main function of your test program to run all of the tests.

<a name="building-a-sample-unit-test"></a>
# Building a sample unit test

```c
START_TEST(test_add_500)
{
    int my_num = 0; // set variable to zero

	my_num = add_500(my_num);
	ck_assert_int_eq(500, my_num); // assert the variable is equal to 500

	my_num = add_500(my_num);
	ck_assert_int_eq(1000, my_num); // assert the variable is equal to 1000

	my_num = add_500(my_num);
	ck_assert_int_eq(1500, my_num); // // assert the variable is equal to 1500

}END_TEST
```

<a name="running-unit-test"></a>
# Running Unit Test
In this class folder, I created a small project to demonstrate using a unit test with an actual library.

The project is located in the folder named **my_program**

There is a Makefile, source folder (src), and test folder (test)

### `Makefile`
**Compiling Sample Program:** 
- To compile the sample program from the top-level of the directory, enter `make run`

- This will compile the program and execute the binary.

```
[my_program] ❱❱❱ (main) $ make run
gcc-9 -std=c18 -Wall -Wextra -Wpedantic -Wwrite-strings -Waggregate-return -Wvla -Wfloat-equal -D_GNU_SOURCE -c src/program.c -o obj/program.o -lm
gcc-9 -std=c18 -Wall -Wextra -Wpedantic -Wwrite-strings -Waggregate-return -Wvla -Wfloat-equal -D_GNU_SOURCE -c src/program_funcs.c -o obj/program_funcs.o -lm
gcc-9 -std=c18 -Wall -Wextra -Wpedantic -Wwrite-strings -Waggregate-return -Wvla -Wfloat-equal -D_GNU_SOURCE obj/program.o obj/program_funcs.o -o program -lm
./program
Result: 1000
```

- To clean up the obj files and binary created from compiling, enter `make clean` to restore the repository to its orginal state.

**Executing Unit Test:** 
- To run the unit test, enter `make check` and you will see the following:

```
[my_program] ❱❱❱ (main) $ make check
gcc-9 -std=c18 -Wall -Wextra -Wpedantic -Wwrite-strings -Waggregate-return -Wvla -Wfloat-equal -D_GNU_SOURCE -c src/program_funcs.c -o obj/program_funcs.o -lm
gcc-9 -std=c18 -Wall -Wextra -Wpedantic -Wwrite-strings -Waggregate-return -Wvla -Wfloat-equal -D_GNU_SOURCE -c test/check_program.c -o obj/check_program.o -lm
gcc-9 -std=c18 -Wall -Wextra -Wpedantic -Wwrite-strings -Waggregate-return -Wvla -Wfloat-equal -D_GNU_SOURCE obj/program_funcs.o obj/check_program.o -o program_check -lcheck -lm -pthread -lrt -lsubunit
./program_check
Running suite(s): program_functions_test
100%: Checks: 1, Failures: 0, Errors: 0
test/check_program.c:18:P:Core:test_add_500:0: Passed
```

- To clean up the obj files and binary created from compiling, enter `make clean` to restore the repository to its orginal state.

### `src folder`
The source folder has a sample program with a small library containing a simple function to test with our unit test.

```
[my_program] ❱❱❱ (main) $ ls src/
program.c  program_funcs.c  program_funcs.h
```


### `test folder`
The test folder is the designated directory where the check_program.c file is located. During the compilation process, the Makefile filters out the main.c source file to prevent any duplication of the main function. This ensures that there are no conflicts arising from multiple main functions within the project
```
[my_program] ❱❱❱ (main) $ ls test/
check_program.c
```

<a name="about-first-test"></a>
## About First Test
The first test we have in `check_program.c` is named `test_add_500`

We have a function in `program_funcs.h` that accepts a number, and returns the number plus 500.

The unit test below calls the function three times and check the value of the variable.

```
START_TEST(test_add_500)
{
    int my_num = 0;

	my_num = add_500(my_num);
	ck_assert_int_eq(500, my_num);

	my_num = add_500(my_num);
	ck_assert_int_eq(1000, my_num);

	my_num = add_500(my_num);
	ck_assert_int_eq(1500, my_num);

}END_TEST
```

<a name="references"></a>
# References
- Installation of check.h : https://libcheck.github.io/check/web/install.html
- Libcheck Reference : https://libcheck.github.io/check/doc/check_html/check_4.html
- Additional Check.h Reference Page : https://libcheck.github.io/check/doc/doxygen/html/check_8h.html