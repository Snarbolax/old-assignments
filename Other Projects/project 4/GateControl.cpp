//****************************************************************************************
//
//	INCLUDE FILES
//
//****************************************************************************************
#include	<iostream>

#include	"GateControl.hpp"

using namespace std;

//****************************************************************************************
//
//	CONSTANT DEFINITIONS
//
//****************************************************************************************

//****************************************************************************************
//
//	CLASSES, TYPEDEFS AND STRUCTURES
//
//****************************************************************************************

//****************************************************************************************
//
//	PUBLIC DATA
//
//****************************************************************************************
extern	string	gCurrentDate;

extern	string	gCurrentTime;

//****************************************************************************************
//
//	PRIVATE DATA
//
//****************************************************************************************

//****************************************************************************************
//
//	FUNCTION PROTOTYPES
//
//****************************************************************************************

//****************************************************************************************
//
//	GateControl::AccessAllowed
//
//****************************************************************************************
bool	GateControl::AccessAllowed(CardNumber number)
{
	if (GetOneAuthorization == true)
	{
		if ((authorizationMap_.find(number)->second.startTime_) >= gCurrentTime && (authorizationMap_.find(number)->second.endTime_) <= gCurrentTime)
		{
			Transaction tranT(number, authorizationMap_.find(number)->second.name_, gCurrentDate, gCurrentTime, true);
			//transactionMap_.insert(number, tranT);
			transactionVector_.push_back(tranT);

			return true
		}
	}

	Transaction tranF(number, authorizationMap_.find(number)->second.name_, gCurrentDate, gCurrentTime, false);
	//transactionMap_.insert(number, tranF);
	transactionVector_.push_back(TranF);

	return false;
}

//****************************************************************************************
//
//	GateControl::AddAuthorization
//
//****************************************************************************************
bool	GateControl::AddAuthorization(CardNumber number, const string& name,
									  const string& startTime, const string& endTime)
{
	Authorization auth(number, name, startTime, endTime);

	pair<AuthorizationIterator, bool> check;
	check = authorizationMap_.insert(number, auth);

	return check.second;

}

bool	GateControl::GetOneAuthorization(CardNumber number, Authorization& authorization)
{

	if (&(authorizationMap_.find(number)->second) == authorization)
	{
		return true;
	}

	return false;
}

//****************************************************************************************
//
//	GateControl::ChangeAuthorization
//
//****************************************************************************************
bool	GateControl::ChangeAuthorization(CardNumber number, const string& name,
										 const string& startTime, const string& endTime)
{

	for (AuthorizationIterator it = authorizationMap_.begin(); it != authorizationMap_.end(); ++it)
	{
		if (GetOneAuthorization(number, &(it->second)) == true)
		{
			it->second.name_ = name;
			it->second.startTime_ = startTime;
			it->second.endTime_ = endTime;
			return true;
		}
	}	

	return false;
}

//****************************************************************************************
//
//	GateControl::DeleteAuthorization
//
//****************************************************************************************
bool	GateControl::DeleteAuthorization(CardNumber number)
{

	for (AuthorizationIterator it = authorizationMap_.end(); it != authorizationMap_.begin(); --it)
	{
		if (GetOneAuthorization(number, &(it->second)) == true)
		{
			authorizationMap_.erase(it);
			return true;
		}
	}
	
	return false;

}

//****************************************************************************************
//
//	GateControl::GetAllAuthorizations
//
//****************************************************************************************
void	GateControl::GetAllAuthorizations(AuthorizationVector& authorizationVector)
{
	if (authorizationMap_.empty() == true)
	{
		authorizationVector->clear();
	}

	AuthorizationIterator	iterator;
	int count = 0;
	for (iterator = authorizationMap_.begin(); iterator != authorizationMap_.end(); ++iterator)
	{
		*(authorizationVector+count) = iterator->second;
		count++;
	}


}

//****************************************************************************************
//
//	GateControl::GetAllTransactions
//
//****************************************************************************************
void	GateControl::GetAllTransactions(TransactionVector& transactionVector)
{
	if (transactionVector_.empty() == true)
	{
		transactionVector->clear();
	}

	int count = 0;
	for (std::vector<Transaction>::iterator i = transactionVector_.begin(); i != transactionVector_.end(); ++i)
	{
		*(transactionVector + count) = *i;
		count++;
	}

}

//****************************************************************************************
//
//	GateControl::GetCardAuthorization
//
//****************************************************************************************
bool	GateControl::GetCardAuthorization(CardNumber number, Authorization& authorization)
{

	if (&(authorizationMap_.find(number)->second) == authorization)
	{
		return true;
	}

	return false;
}

//****************************************************************************************
//
//	GateControl::GetCardTransactions
//
//****************************************************************************************
bool	GateControl::GetCardTransactions(CardNumber number,
										 TransactionVector& transactionVector)
{

	if (transactionVector_.empty() == true)
	{
		transactionVector->clear();
		return false;
	}
	
	for (std::vector<Transaction>::iterator i = transactionVector_.begin(); i != transactionVector_.end(); ++i)
	{
		if (number == i->number_)
		{
			transactionVector.push_back(i->number_);
			return true;
		}
	}

	return false;
}