#pragma once
#include <string>
#include <iostream>
class Animation ;
struct Position {
	int x ;
	int y ;
	friend std::ostream & operator<<(std::ostream &out, Position p) {
		return out <<'(' << p.x << ',' << p.y << ')' ;
	}
};
class Vehicle
{
	int m_Speed{} ;
	int m_HitPoints{} ;
	std::string m_Name{} ;
	Animation *m_pAnimation{} ;
	Position m_Position{} ;
public:
	Vehicle()=default ;
	Vehicle(int mSpeed, int mHitPoints,
	        const std::string& mName,
	        std::string_view animFile,
	        const Position& mPosition);
	virtual ~Vehicle() ;
	Vehicle(const Vehicle &other) ;
	Vehicle & operator=(const Vehicle &other) ;

	Vehicle(Vehicle &&other)noexcept ;
	Vehicle & operator=(Vehicle &&other)noexcept ;
	int GetSpeed()const {
		return m_Speed ;
	}
	Position GetPosition()const {
		return m_Position ;
	}
	const std::string & GetName()const {
		return m_Name ;
	}
	int GetHitPoints()const {
		return m_HitPoints ;
	}
	const std::string & GetAnimation()const ;
	void SetSpeed(int speed) {
		m_Speed = speed ;
	}
	void SetPosition(Position position) {
		m_Position = position ;
	}
	void SetName(const std::string &name) {
		m_Name = name ;
	}
	void SetHitPoints(int hitpoints) {
		m_HitPoints = hitpoints ;
	}
	void SetAnimationData(const std::string &animData);
	virtual void Update() =0;
	virtual Vehicle * Clone() = 0 ;
};

