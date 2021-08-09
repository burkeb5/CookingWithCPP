#include "pch.h"
#include ".\gtest\gtest.h"
#include ".\gmock\gmock.h"

#include "..\MockRestaurantOwner\MockRestaurantOwner.h"

//class MockTest {
//public:
//    MOCK_METHOD(void, SomeMethod, ());
//};

TEST(MockRestaurantOwner, TestBasicMethods) {
    MockRestaurantOwner owner;
    Customer c = Customer();
    EXPECT_CALL(owner, sell_asparagus(c)).Times(2);
    EXPECT_CALL(owner, sell_cake(c)).Times(3);
    EXPECT_CALL(owner, sell_meatloaf(c)).Times(1);
    EXPECT_CALL(owner, cleanup_tables()).Times(3);

    // All return void
    owner.sell_asparagus(c);
    owner.sell_cake(c);
    owner.sell_meatloaf(c);
    owner.cleanup_tables();

    owner.sell_asparagus(c);
    owner.sell_cake(c);
    owner.cleanup_tables();

    owner.sell_cake(c);
    owner.cleanup_tables();
};

TEST(MockRestaurantOwner, TestSatisfiedFoodNameOrder) {
    MockRestaurantOwner owner;
    Customer c = Customer();
    EXPECT_CALL(owner, sell_generic_food(c)).Times(3);

    // Case 1
    // Slightly over budget
    // Slightly over max patience
    c.setFoodName("asparagus");
    c.setBudget(10);
    c.setMaxPatience(10);

    FoodOrder food_name_order1 = owner.sell_generic_food(c);

    EXPECT_EQ(food_name_order1.getFoodName(), "asparagus");
    EXPECT_EQ(food_name_order1.getBudget(), 10);
    EXPECT_EQ(food_name_order1.getMaxPatience(), 10);
    
    EXPECT_TRUE(food_name_order1.getShouldFillOrder());

    // Case 2
    // Equal budget
    // Significantly over-max-patience
    c.setFoodName("cake");
    c.setBudget(24);
    c.setMaxPatience(400);

    FoodOrder food_name_order2 = owner.sell_generic_food(c);

    EXPECT_EQ(food_name_order2.getFoodName(), "cake");
    EXPECT_EQ(food_name_order2.getBudget(), 24);
    EXPECT_EQ(food_name_order2.getMaxPatience(), 400);

    EXPECT_TRUE(food_name_order2.getShouldFillOrder());

    // Case 3
    // Significantly over-budget
    // Equal max-patience
    c.setFoodName("meatloaf");
    c.setBudget(400);
    c.setMaxPatience(10);

    FoodOrder food_name_order3 = owner.sell_generic_food(c);

    EXPECT_EQ(food_name_order3.getFoodName(), "meatloaf");
    EXPECT_EQ(food_name_order3.getBudget(), 400);
    EXPECT_EQ(food_name_order3.getMaxPatience(), 10);

    EXPECT_TRUE(food_name_order3.getShouldFillOrder());
};


TEST(MockRestaurantOwner, TestUnsatisfiedFoodOrder) {
    MockRestaurantOwner owner;
    Customer c = Customer();
    EXPECT_CALL(owner, sell_generic_food(c)).Times(2);

    // Case 1
    // Under-budget case
    c.setFoodName("asparagus");
    c.setBudget(1);
    c.setMaxPatience(10);

    FoodOrder food_name_order1 = owner.sell_generic_food(c);

    EXPECT_EQ(food_name_order1.getFoodName(), "asparagus");
    EXPECT_EQ(food_name_order1.getBudget(), 1);
    EXPECT_EQ(food_name_order1.getMaxPatience(), 10);

    EXPECT_TRUE(!food_name_order1.getShouldFillOrder());

    // Case 2
    // Under-max-patience case
    c.setFoodName("cake");
    c.setBudget(24);
    c.setMaxPatience(20);

    FoodOrder food_name_order2 = owner.sell_generic_food(c);

    EXPECT_EQ(food_name_order2.getFoodName(), "cake");
    EXPECT_EQ(food_name_order2.getBudget(), 24);
    EXPECT_EQ(food_name_order2.getMaxPatience(), 20);

    EXPECT_TRUE(!food_name_order2.getShouldFillOrder());

    // Case 3
    // Under budget and max-patience case
    c.setFoodName("meatloaf");
    c.setBudget(1);
    c.setMaxPatience(1);

    FoodOrder food_name_order3 = owner.sell_generic_food(c);

    EXPECT_EQ(food_name_order3.getFoodName(), "meatloaf");
    EXPECT_EQ(food_name_order3.getBudget(), 1);
    EXPECT_EQ(food_name_order3.getMaxPatience(), 1);

    EXPECT_TRUE(!food_name_order3.getShouldFillOrder());

};


TEST(MockRestaurantOwner, TestDetermineFoodBasedOnBudget) {
    MockRestaurantOwner owner;
    Customer c = Customer();
    EXPECT_CALL(owner, sell_generic_food(c)).Times(4);

    // Case 1
    // Enough budget for cake, meatloaf, and asparagus
    c.setBudget(100);
    c.setMaxPatience(100);

    FoodOrder food_name_order1 = owner.sell_generic_food(c);

    EXPECT_EQ(food_name_order1.getFoodName(), "cake");
    EXPECT_EQ(food_name_order1.getBudget(), 100);
    EXPECT_EQ(food_name_order1.getMaxPatience(), 100);

    EXPECT_TRUE(food_name_order1.getShouldFillOrder());

    // Case 2
    // Enough budget for meatloaf and asparagus
    c.setBudget(20);
    c.setMaxPatience(100);

    FoodOrder food_name_order2 = owner.sell_generic_food(c);

    EXPECT_EQ(food_name_order2.getFoodName(), "meatloaf");
    EXPECT_EQ(food_name_order2.getBudget(), 20);
    EXPECT_EQ(food_name_order2.getMaxPatience(), 100);

    EXPECT_TRUE(food_name_order2.getShouldFillOrder());

    // Case 3
    // Enough budget for asparagus
    c.setBudget(8);
    c.setMaxPatience(100);

    FoodOrder food_name_order3 = owner.sell_generic_food(c);

    EXPECT_EQ(food_name_order3.getFoodName(), "asparagus");
    EXPECT_EQ(food_name_order3.getBudget(), 8);
    EXPECT_EQ(food_name_order3.getMaxPatience(), 100);

    EXPECT_TRUE(food_name_order3.getShouldFillOrder());

    // Case 4
    // Not enough budget for any meals
    c.setBudget(1);
    c.setMaxPatience(100);

    FoodOrder food_name_order4 = owner.sell_generic_food(c);

    EXPECT_EQ(food_name_order4.getFoodName(), "none");
    EXPECT_EQ(food_name_order4.getBudget(), 1);
    EXPECT_EQ(food_name_order4.getMaxPatience(), 100);

    EXPECT_TRUE(!food_name_order4.getShouldFillOrder());
};

