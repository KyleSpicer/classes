#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../src/program_funcs.h" // library with function to be tested

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


Suite *check_program_suite(void)
{
    Suite *suite;
	TCase *tc_core;

	suite = suite_create("program_functions_test");

	tc_core = tcase_create("Core");
	tcase_add_test(tc_core, test_add_500);

	suite_add_tcase(suite, tc_core);

	return suite;
}

int main(void)
{
	Suite *suite = check_program_suite();
	SRunner *runner = srunner_create(suite);

	srunner_set_fork_status(runner, CK_NOFORK);

	srunner_run_all(runner, CK_VERBOSE);

	int no_failed = srunner_ntests_failed(runner);
	srunner_free(runner);

	return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}