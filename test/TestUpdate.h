#pragma once

#include <string>

class TestUpdate
{
	private:
		std::string updateMsg;

	public:
		TestUpdate(std::string msg);

		const std::string& getUpdateMsg() const;
};
