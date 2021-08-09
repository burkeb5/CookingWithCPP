#pragma once
#include "..\RestaurantOwner\RestaurantOwner.h"
#include "..\gmock\gmock.h"  // Brings in gMock.


class MockRestaurantOwner : public RestaurantOwner {
public:

	MOCK_METHOD0(cleanup_tables, void());
	MOCK_METHOD0(get_total_sales, void());
	MOCK_METHOD1(sell_meatloaf, void(Customer c));
	MOCK_METHOD1(sell_cake, void(Customer c));
	MOCK_METHOD1(sell_asparagus, void(Customer c));
	MOCK_METHOD1(sell_generic_food, FoodOrder(Customer c));

};