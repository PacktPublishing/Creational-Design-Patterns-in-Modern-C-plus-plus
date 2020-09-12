#pragma once
#include <string_view>
struct Position;
class Vehicle ;
Vehicle * Create(
	std::string_view type, 
	int mSpeed, 
	int mHitPoints,
	const std::string& mName,
	std::string_view animFile,
	const Position& mPosition);

