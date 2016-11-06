#include <check.h>
#include <stdlib.h>

#include "CheckSuites.h"

int main() {
    Suite *suite = notation_conversion();
    SRunner *srunner = srunner_create(suite);

    srunner_run_all(srunner, CK_NORMAL);
    int num_failed = srunner_ntests_failed(srunner);
    srunner_free(srunner);

    return (num_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
