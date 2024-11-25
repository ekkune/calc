#include <check.h>
#include <string.h>

#include "calc.h"

START_TEST(test_1) {
  char str[255] = "1+2-3*4";
  double answer = 0.;
  int err = getAnswer(str, &answer, 0);
  double correct_answer = 1 + 2 - 3 * 4;
  ck_assert_double_eq_tol(answer, correct_answer, 1e-07);
  ck_assert_int_eq(err, 0);
}
END_TEST

START_TEST(test_2) {
  char str[255] = "-1*cos(1)";
  double answer = 0.;
  int err = getAnswer(str, &answer, 0);
  double correct_answer = -1 * cos(1);
  ck_assert_double_eq_tol(answer, correct_answer, 1e-07);
  ck_assert_int_eq(err, 0);
}
END_TEST

START_TEST(test_3) {
  char str[255] = "+sqrt(4)^3-log(2)/ln(4)";
  double answer = 0.;
  int err = getAnswer(str, &answer, 0);
  double correct_answer = pow(sqrt(4), 3) - log10(2) / log(4);
  ck_assert_double_eq_tol(answer, correct_answer, 1e-07);
  ck_assert_int_eq(err, 0);
}
END_TEST

START_TEST(test_4) {
  char str[255] = "sin(1)*asin(1)*atan(2)*tan(1)";
  double answer = 0.;
  int err = getAnswer(str, &answer, 0);
  double correct_answer = sin(1) * asin(1) * atan(2) * tan(1);
  ck_assert_double_eq_tol(answer, correct_answer, 1e-07);
  ck_assert_int_eq(err, 0);
}
END_TEST

START_TEST(test_5) {
  char str[255] = "1.8";
  double answer = 0.;
  int err = getAnswer(str, &answer, 0);
  double correct_answer = 1.8;
  ck_assert_double_eq_tol(answer, correct_answer, 1e-07);
  ck_assert_int_eq(err, 0);
}
END_TEST

START_TEST(test_6) {
  char str[255] = "sin(5)%2 + acos(1)";
  double answer = 0.;
  int err = getAnswer(str, &answer, 0);
  double correct_answer = fmod(sin(5), 2) + acos(1);
  ck_assert_double_eq_tol(answer, correct_answer, 1e-07);
  ck_assert_int_eq(err, 0);
}
END_TEST

int main(void) {
  Suite *s = suite_create("suite_polish_tests");
  TCase *tc = tcase_create("polish_tests");

  tcase_add_test(tc, test_1);
  tcase_add_test(tc, test_2);
  tcase_add_test(tc, test_3);
  tcase_add_test(tc, test_4);
  tcase_add_test(tc, test_5);
  tcase_add_test(tc, test_6);

  suite_add_tcase(s, tc);

  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
  return 0;
}