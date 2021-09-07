#include "unity.h"
#include "reserve.h"
#include"assert.h"

void setUp(){}
void tearDown(){}
void test_cancellation()
{
     char passport[6]="1234";
     
    TEST_ASSERT_EQUAL_STRING("1234", passport);
   
}
void test_reservation()
{
      int seatnumber=1;
      char matrix[100]={"4561,vai,vai.com,chennai"};
      TEST_ASSERT_EQUAL(1,seatnumber);
      TEST_ASSERT_EQUAL_STRING("4561,vai,vai.com,chennai",matrix);

}


int main(void)
{
UNITY_BEGIN();
RUN_TEST(test_cancellation);
RUN_TEST(test_reservation);

return UNITY_END();
}