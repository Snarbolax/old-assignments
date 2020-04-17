#include <queue>
#include <stdexcept>
#include <string>

#include "ClaimCheck.hpp"
#include "ParkingLot.hpp"


/*******************************************************************************
** ParkingLot Member function definitions
*******************************************************************************/
ClaimCheck ParkingLot::dropOff( const Automobile& vehicle ) {
  ///   Create a claim check called ticket passing in the vehicle
	ClaimCheck ticket(vehicle);

  ///   Add the vehicle and the ticket's claim number to the collection of parked cars.
  ///   Hint:  Create a ParkedCar and set its vehicle and claim number attributes, then push it on to the stack.

	ParkedCar addedCar;
	addedCar.vehicle_ = vehicle;
	addedCar.claimNumber_ = ticket.claimNumber_;

	parkedCars_.push(addedCar);


  return ticket;
}




Automobile ParkingLot::pickUp(const ClaimCheck& ticket) {
	///   Move cars from the front of the queue to the back of the queue until you
	///   find the one you're looking for or until you looked at them all.
	///   Hint:  The vehicle you're looking for has a ticket claim number that matches the parked car's claim number.

	size_t count = 0;
	do
	{
		if (ticket.claimNumber() != parkedCars_.front().claimNumber_)
		{
			parkedCars_.push(parkedCars_.front());
			parkedCars_.pop();
			count++;
		}
		else if (ticket.claimNumber() == parkedCars_.front().claimNumber_)
		{
			parkedCars.pop();
			count = parkedCars_.size();
		}
	} while (count != parkedCars_.size())

		///   If you reach this point, the vehicle you're looking for wasn't in the parking lot.
		///   Optional:  Throw an invalid argument exception (highly recommended but not required).  Otherwise
		///              print out an error message and return the ticket's vehicle.

		throw std::invalid_argument;
		return ticket.vehicle();
}




size_t ParkingLot::quantity()
{
  ///   Return the number of parked cars that are currently in the parking lot
	return parkedCars_.size();
}

