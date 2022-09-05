#include <cppBook6>
#include <iostream>

using namespace std;

int main()
{
    cout << "Chapter is only a read only introduction" << endl;
    cout << "Unit Testing" << endl;

    /*
    Expressive and descriptive naming of unit test is very important.
    The test could be name after the class which is the subject of the test with the result expected.
    For example:
    void InvoiceTest::invoiceIsReadyForAccounting_getInvoiceDate_returnsToday();

    void ChessEngineTest::aCastlingIsNotAllowedIfInvolvedKingHasBeenMovedBefore();

    Single Responsibility applied to unit tests, they must test one bit of the software and be completely independent from other unit tests.

    ************************************************************************
    One Assertion per Test
    ************************************************************************
    Unit Test Independence
    ************************************************************************

    void MoneyTest::givenTwoMoneyObjectsWithDifferentBalance_theInequalityComparison_Works() {
        const Money m1(-4000.0);
        const Money m2(2000.0);
        ASSERT_TRUE(m1 != m2);
        }

    ************************************************************************
    Independent Initialization of Unit Test Environments
    ************************************************************************
    Exclude Getters & Settes (Unless they hide complex mecanics)
    ************************************************************************
    Exclude Thir-Party Code (Because it is supposed to be already tested)
    ************************************************************************
    Exclude External Systems (Because it is not your responsibility)
    ************************************************************************
    What Do We Do with Databases:
    When there is any way to test without a database, test without database.
    ************************************************************************
    Never mix Test Code With Production Code
    ************************************************************************

    */

    return 0;
}
