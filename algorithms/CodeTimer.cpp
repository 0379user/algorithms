 #pragma once
 #include <chrono>
 #include <iostream>
 #include "CodeTimer.hpp"
 #include <string>


CodeTimer::CodeTimer()
	{
		start = std::chrono::high_resolution_clock::now();
		str = "base \n";
	}
CodeTimer::CodeTimer(std::string str)
	{
		start = std::chrono::high_resolution_clock::now();
		this->str = str;
	}
CodeTimer::~CodeTimer()
	{
	end= std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> result = end - start;
	std::cout << "timer name : " << str << "\n";
	std::cout << "time worked   "<< result.count() << " seconds\n";
	}
