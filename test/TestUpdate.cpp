#include "TestUpdate.h"

TestUpdate::TestUpdate(std::string msg) :
	updateMsg(msg)
{
}

const std::string& TestUpdate::getUpdateMsg() const
{
	return updateMsg;
}
