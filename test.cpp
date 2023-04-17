// Uncomment the next line to use precompiled headers
#include "pch.h"
// uncomment the next line if you do not use precompiled headers
//#include "gtest/gtest.h"
//
// the global test environment setup and tear down
// you should not need to change anything here
class Environment : public ::testing::Environment
{
public:
    ~Environment() override {}

    // Override this to define how to set up the environment.
    void SetUp() override
    {
        //  initialize random seed
        srand(time(nullptr));
    }

    // Override this to define how to tear down the environment.
    void TearDown() override {}
};

// create our test class to house shared data between tests
// you should not need to change anything here
class CollectionTest : public ::testing::Test
{
protected:
    // create a smart point to hold our collection
    std::unique_ptr<std::vector<int>> collection;

    void SetUp() override
    { // create a new collection to be used in the test
        collection.reset(new std::vector<int>);
    }

    void TearDown() override
    { //  erase all elements in the collection, if any remain
        collection->clear();
        // free the pointer
        collection.reset(nullptr);
    }

    // helper function to add random values from 0 to 99 count times to the collection
    void add_entries(int count)
    {
        assert(count > 0);
        for (auto i = 0; i < count; ++i)
            collection->push_back(rand() % 100);
    }
};

// When should you use the EXPECT_xxx or ASSERT_xxx macros?
// Use ASSERT when failure should terminate processing, such as the reason for the test case.
// Use EXPECT when failure should notify, but processing should continue

// Test that a collection is empty when created.
// Prior to calling this (and all other TEST_F defined methods),
//  CollectionTest::StartUp is called.
// Following this method (and all other TEST_F defined methods),
//  CollectionTest::TearDown is called
TEST_F(CollectionTest, CollectionSmartPointerIsNotNull)
{
    // is the collection created
    ASSERT_TRUE(collection);

    // if empty, the size must be 0
    ASSERT_NE(collection.get(), nullptr);
}

// Test that a collection is empty when created.
TEST_F(CollectionTest, IsEmptyOnCreate)
{
    // is the collection empty?
    ASSERT_TRUE(collection->empty());

    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);
}

/* Comment this test out to prevent the test from running
 * Uncomment this test to see a failure in the test explorer */
/*TEST_F(CollectionTest, AlwaysFail)
{
    FAIL();
}*/

// TODO: Create a test to verify adding a single value to an empty collection
TEST_F(CollectionTest, CanAddToEmptyVector)
{
    // is the collection empty?
    // if empty, the size must be 0

    add_entries(1);

    // is the collection still empty?
    // if not empty, what must the size be?
}

// TODO: Create a test to verify adding five values to collection
TEST_F(CollectionTest, CanAddFiveValuesToVector)
{
    add_entries(5);
}

// TODO: Create a test to verify that max size is greater than or equal to size for 0, 1, 5, 10 entries
// Completed test for max size
TEST_F(CollectionTest, MaxGreaterOrEqual) {
    add_entries(15);
    //Test greater than or equal to 0
    ASSERT_TRUE(collection->max_size() >= 0);
    //Test greater than or equal to 1
    ASSERT_TRUE(collection->max_size() >= 1);
    //Test greater than or equal to 5
    ASSERT_TRUE(collection->max_size() >= 5);
    //Test greater than or equal to 10
    ASSERT_TRUE(collection->max_size() >= 10);
}

// TODO: Create a test to verify that capacity is greater than or equal to size for 0, 1, 5, 10 entries
// Completed test for capacity
TEST_F(CollectionTest, CapacityGreaterOrEqual) {
    add_entries(15);
    //Test capacity greater than or equal to 0
    ASSERT_TRUE(collection->capacity() >= 0);
    //Test capacity greater than or equal to 1
    ASSERT_TRUE(collection->capacity() >= 1);
    //Test capacity greater than or equal to 5
    ASSERT_TRUE(collection->capacity() >= 5);
    //Test capacity greater than or equal to 10
    ASSERT_TRUE(collection->capacity() >= 10);
}

// TODO: Create a test to verify resizing increases the collection
// Completed test for resize increase
TEST_F(CollectionTest, ResizeIncrease) {
    add_entries(1);
    //initial collection size
    int startSize = collection->size();
    //resize collection
    collection->resize(15);
    //test for resizing
    ASSERT_TRUE(collection->size() > startSize);
}

// TODO: Create a test to verify resizing decreases the collection
// Completed test for resize decrease
TEST_F(CollectionTest, ResizeDecrease) {
    add_entries(15);
    //initial collection size
    int startSize = collection->size();
    //resize collection
    collection->resize(1);
    //test for resizing
    ASSERT_TRUE(collection->size() < startSize);
}

// TODO: Create a test to verify resizing decreases the collection to zero
// Completed test resizing collection to zero
TEST_F(CollectionTest, ResizeToZero) {
    add_entries(15);
    //initialize collection size
    int startSize = collection->size();
    //resize collection
    collection->resize(0);
    //test for resizing
    ASSERT_TRUE(collection->size() == 0);
}

// TODO: Create a test to verify clear erases the collection
// Completed test to verify clear
TEST_F(CollectionTest, VerifyClear) {
    add_entries(15);
    //clear collection
    collection->clear();
    //test for clearing
    ASSERT_TRUE(collection->size() == 0);
}

// TODO: Create a test to verify erase(begin,end) erases the collection
// Completed test to verify erase
TEST_F(CollectionTest, VerifyErase) {
    add_entries(15);
    //erase collection
    collection->erase(collection->begin(), collection->end());
    //test for erasing
    ASSERT_TRUE(collection->size() == 0);
}

// TODO: Create a test to verify reserve increases the capacity but not the size of the collection
//Completed test to verify reserve increases capacity but not size
TEST_F(CollectionTest, IncreaseCapacityNotSize) {
    add_entries(15);
    int startCapacity = collection->capacity();
    int startSize = collection->size();
    //reserve request
    collection->reserve(20);
    //test for increasing capacity but not size
    ASSERT_TRUE(collection->capacity() > startCapacity);
    ASSERT_TRUE(collection->size() == startSize);
}

// TODO: Create a test to verify the std::out_of_range exception is thrown when calling at() with an index out of bounds
// NOTE: This is a negative test
//Compelted test to verify the out of range exception
TEST_F(CollectionTest, OutOfRangeException) {
    add_entries(15);
    //test for exception
    EXPECT_THROW(collection->at(20), std::out_of_range);
}

// TODO: Create 2 unit tests of your own to test something on the collection - do 1 positive & 1 negative
// Completed one positive test
TEST_F(CollectionTest, AddOne) {
    add_entries(15);
    collection->push_back(1);
    ASSERT_TRUE(collection->size() > 15);
}

// Completed one negative test
TEST_F(CollectionTest, RemoveOne) {
    add_entries(15);
    // remove one entry
    collection->pop_back();
    // test for collection size
    ASSERT_TRUE(collection->size() < 15);
}