#include <ctest.h>
#include <functional.h>

CTEST(quadratic_equation_suite, discriminant_all_coefficients_equal_to_zero) {
	// Given
	const float a = 0;
	const float b = 0;
	const float c = 0;

	// When
	float x1, x2, discr;
	int nroots;
	nroots = worx(a, b, c, &discr, &x1, &x2);

	// Then
	const int expected_nroots = 0;
	ASSERT_EQUAL(expected_nroots, nroots);
}

CTEST(quadratic_equation_suite, discriminant_less_than_zero) {
	// Given
	const float a = 4;
	const float b = 2;
	const float c = 8;

	// When
	float x1, x2, discr;
	int nroots;
	nroots = worx(a, b, c, &discr, &x1, &x2);

	// Then
	const int expected_nroots = 0;
	const float expected_discr = -124;
	ASSERT_DBL_NEAR(expected_discr, discr);
	ASSERT_EQUAL(expected_nroots, nroots);
}

CTEST(quadratic_equation_suite, discriminant_is_equal_to_zero) {
	//Given
	const float a = 1;
	const float b = 2;
	const float c = 1;

	// When
	float x1, x2, discr;
	int nroots;
	nroots = worx(a, b, c, &discr, &x1, &x2);

	// Then
	const float expected_x1 = -1;
	const float expected_discr = 0;
	const int expected_nroots = 1;

	ASSERT_DBL_NEAR(expected_x1, x1);
	ASSERT_DBL_NEAR(expected_discr, discr);
	ASSERT_EQUAL(expected_nroots, nroots);
}

CTEST(quadratic_equation_suite, discriminant_is_greater_than_zero) {
	// Given
	const float a = 2;
	const float b = 5;
	const float c = 2;

	// When
	float x1, x2, discr;
	int nroots;
	nroots = worx(a, b, c, &discr, &x1, &x2);

	// Then
	const float expected_x1 = -2;
	const float expected_x2 = -0.5;
	const float expected_discr = 9;
	const int expected_nroots = 2;

	ASSERT_DBL_NEAR(expected_x1, x1);
	ASSERT_DBL_NEAR(expected_x2, x2);
	ASSERT_DBL_NEAR(expected_discr, discr);
	ASSERT_EQUAL(expected_nroots, nroots);
}