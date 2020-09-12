#include "Vehicle.h"
#include "Animation.h"
Vehicle::Vehicle() {
	m_pAnimation = new Animation{} ;
}


Vehicle::Vehicle(
	int mSpeed, 
	int mHitPoints,
	const std::string& mName, 
	std::string_view animFile,
	const Position& mPosition, 
	const std::string &color) :
m_Speed{ mSpeed },
m_HitPoints{ mHitPoints },
m_Name{ mName },
m_Position{ mPosition },
m_Color{color}{
		m_pAnimation = new Animation{ animFile };
}

Vehicle::~Vehicle() {
	delete m_pAnimation;
}

Vehicle::Vehicle(const Vehicle& other) :
	m_Speed{ other.m_Speed },
	m_Name{ other.m_Name },
	m_HitPoints{ other.m_HitPoints },
	m_Position{ other.m_Position },
	m_Color{other.m_Color}{
	m_pAnimation = new Animation{};
	m_pAnimation->SetAnimationData(other.GetAnimation());
}

Vehicle& Vehicle::operator=(const Vehicle& other) {
	if (this != &other) {
		m_Speed = other.m_Speed;
		m_Name = other.m_Name;
		m_HitPoints = other.m_HitPoints;
		m_Position = other.m_Position;
		m_Color = other.m_Color ;
		m_pAnimation->SetAnimationData(other.GetAnimation());
	}
	return *this;
}

Vehicle::Vehicle(Vehicle&& other) noexcept :
	m_Speed{ other.m_Speed },
	m_Name{ std::move(other.m_Name) },
	m_HitPoints{ other.m_HitPoints },
	m_Position{ other.m_Position },
	m_Color{std::move(other.m_Color)}{
	m_pAnimation = other.m_pAnimation;

	other.m_pAnimation = nullptr;
	other.m_Position = { 0,0 };
	other.m_HitPoints = 0;
	other.m_Speed = 0;
	other.m_Name.clear();
	other.m_Color.clear() ;

}

Vehicle& Vehicle::operator=(Vehicle&& other) noexcept {
	if (this != &other) {
		m_Speed = other.m_Speed;
		m_Name = std::move(other.m_Name);
		m_HitPoints = other.m_HitPoints;
		m_Position = other.m_Position;
		m_Color = other.m_Color ;
		delete m_pAnimation;
		m_pAnimation = other.m_pAnimation;

		other.m_pAnimation = nullptr;
		other.m_Position = { 0,0 };
		other.m_HitPoints = 0;
		other.m_Speed = 0;
		other.m_Name.clear();
		other.m_Color.clear() ;
	}
	return *this;
}

void Vehicle::SetAnimationData(const std::string& animData) {
	m_pAnimation->SetAnimationData(animData);
}
const std::string& Vehicle::GetAnimation() const {
	return m_pAnimation->GetAnimationData();
}
