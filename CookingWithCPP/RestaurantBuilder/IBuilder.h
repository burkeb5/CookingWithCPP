#pragma once

/**
* <summary> Class that all other Builders inherit.</summary>
*
* The suggested implementation is for methods to rely on support from methods in [Core](@ref Core).
*/
class RESTAURANTBUILDER_API IBuilder {
public:
	/**
	* <summary> Returns this unique ID for this IBuilder-inherited object.</summary>
	* The suggested implementation is for methods to rely on support from methods in [Core](@ref Core).
	*/
	virtual int getUniqueID();
};