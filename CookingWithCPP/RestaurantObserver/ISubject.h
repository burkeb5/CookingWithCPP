#pragma once

#include "IObserver.h"
namespace IObserver
/**
* <summary> Class that all other Subjects inherit.</summary>
*
* The suggested implementation is for methods to rely on support from methods in [Core](@ref Core).
*/
class RESTAURANTOBSERVER_API ISubject {
public:
	virtual ~ISubject() {};

	/**
	* <summary> Attaches a given subject to a given observer.</summary>
	* 
	* The Observer will be updated whenever the subject issues a Notify().
	*/
	virtual void Attach(IObserver* observer) = 0;

	/**
	* <summary> Detaches a given subject from a given observer.</summary>
	*
	* The Observer will no longer be updated whenever the subject issues a Notify().
	*/ 
	virtual void Detach(IObserver* observer) = 0;

	/**
	* <summary> Notifies all attached observers for this subject generically.</summary> 
	*/
	virtual void Notify() = 0;

	/**
	* <summary> Notifies, with the stated event type, all attached observers for this subject.</summary>
	*/
	virtual void Notify(IObserver::EventTypes eventType) = 0;
};