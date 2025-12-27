#include "unity.h"
#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>
#include "../../examples/autotest-validate/autotest-validate.h"
#include "../../assignment-autotest/test/assignment1/username-from-conf-file.h"

/**
* This function should:
*   1) Call the my_username() function in Test_assignment_validate.c to get your hard coded username.
*   2) Obtain the value returned from function malloc_username_from_conf_file() in username-from-conf-file.h within
*       the assignment autotest submodule at assignment-autotest/test/assignment1/
*   3) Use unity assertion TEST_ASSERT_EQUAL_STRING_MESSAGE the two strings are equal.  See
*       the [unity assertion reference](https://github.com/ThrowTheSwitch/Unity/blob/master/docs/UnityAssertionsReference.md)
*/
void test_validate_my_username()
{
    // Read from configuration file into buffer
    char* buffer = malloc_username_from_conf_file();

    // Exit if buffer is null
    if(!buffer) {
        fprintf(stderr, "Could not allocate buffer to read configuration file. Exiting.");
        exit(1);
    }   
    
    // Compare usernames
    TEST_ASSERT_EQUAL_STRING_MESSAGE(my_username(), buffer, "Usernames do not match.");

    // Return buffer to heap
    free(buffer);
}
