# CookingWithCPP

# softarchfinal - Problem 1

Significant modifications to the repo:

CookingWithCPP/MockRestaurantOwner/test.cpp
- Contains mock test cases
CookingWithCPP/RestaurantOwner/MockRestaurantOwner.h
- Builds off RestaurantOWner class as a Mock test class
CookingWithCPP/FoodOrder/
- New class used to track attributes of a food order and whether it should be satisfied or not
CookingWithCPP/Customer/
- Adding budget and patience attributes to customer class


Mock Tests:
1) Basic Test
    a.  Test one/multiple runs of selling each known foodtype and cleaning tables
2) Interesting Test Case 1:
These tests should result in a successful interaction between a RestaurantOwner and a Customer that results in a FoodOrder that indicates that the meal should be prepared.
    a.  Selling “asparagus”, slightly over budget, slightly over max patience.
    b.  Selling “cake”, equal to cost budget, significantly over max patience.
    c.  Selling “meatloaf”, significantly over budget, equal to time to prepare max patience.
3) Interesting Test Case 2:
These tests should result in a unsuccessful interaction between a RestaurantOwner and a Customer that results in a FoodOrder that indicates that the meal should not be prepared.
    a.  Selling “asparagus”, under budget, over max patience.
    b.  Selling “cake”, equal to cost budget, under max patience.
    c.  Selling “meatloaf”, under budget, under max patience.
4) Interesting Test Case 3:
    a.  No provided food name, enough budget for “cake”, “meatloaf”, and “asparagus”, order should be filled with a food type of “cake”.
    b.  No provided food name, enough budget for “meatloaf” and “asparagus”, order should be filled with a food type of “meatloaf”.
    c.  No provided food name, enough budget for “asparagus”, order should be filled with a food type of “asparagus”.
    d.  No provided food name, not enough budget for any food types, order should not be filled with a food type of “none”.


General Interaction Case Between RestaurantOwner/Customer/FoodOrder:
1) Construct RestaurantOwner and Customer objects
2) Add a set of values attributed to the Customer
    a.  food_name (optional)
    b.  budget
    c.  max_patience
3) The RestaurantOwner and Customer interact with a “sell_generic_food” call
    a.  If necessary, processes and determines which food type to put in the order for based on budget
    b.  Constructs a FoodOrder object based on the customer’s food_name, budget, and max_patience
    c.  Uses the FoodOrder object to determine if the RestaurantOwner is able to satisfy the order, and indicates this with the should_fill_order boolean value that is determined based on whether the budget and max_patience exceed a threshold based on the food.
    d.  If the order should be satisfied, the order is satisfied with a call to “sell_asparagus”, “sell_cake”, or “sell_meatloaf”.
    e.  Returns the generated FoodOrder object.
4) Additional notes:
    a.  The RestaurantOwner keeps track of the cost of the meal and adds the this to their tracked total sales for the day
    b.  The RestaurantOwner keeps track of the number of tables that have become dirty by based on the meals sold since the last time the tables were cleaned.

