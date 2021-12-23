 #pragma once
 #include <chrono>
  

class CodeTimer
{
public:
	CodeTimer();
	
	CodeTimer(std::string );
	
	~CodeTimer();
	
private:
	std::chrono::steady_clock::time_point start,end;
	std::string str;
};