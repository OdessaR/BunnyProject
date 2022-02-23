#pragma once
#include <iostream>
#include <list>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <random>
#include <cmath>
#include <iterator>
#include <algorithm>

//	Each bunny object must have
//	Sex: Male, Female(random at creation 50 / 50)
//	color : white, brown, black, spotted
//	age : 0 - 10 (years old)
//	Name : randomly chosen at creation from a list of bunny names.
//	radioactive_mutant_vampire_bunny : true / false (decided at time of bunny creation 2 % chance of true)

class Bunny {
protected:
	char m_sex{};
	std::string m_color{};
	int m_age{};
	std::string m_name{};
	bool m_vamp{};

	enum class ColorType {
		white,
		brown,
		black,
		spotted,
		max_color_type
	};

	static std::string getColorType(ColorType color)
	{
		switch (color)
		{
		case ColorType::white: return "white";
		case ColorType::brown:   return "brown";
		case ColorType::black:  return "black";
		case ColorType::spotted:  return "spotted";
		default:    return "???";
		}
	}

public:
	// constructor
	Bunny(char sex, std::string color, int age, std::string name, bool vamp)
		: m_sex{ sex }, m_color{ color }, m_age{ age }, m_name{name}
		, m_vamp{vamp}
	{}

	Bunny() { reproduceBunny(); }

	// a bunch of get properties
	const std::string& getName() const { return m_name; }
	const std::string& getColor() const { return m_color; }
	const char getSex() const { return m_sex; }
	const int getAge() const { return m_age; }
	const bool getVamp() const { return m_vamp; }
	void makeOlder() { m_age++; }
	void makeVamp() { m_vamp = true; }

	bool isAdult() { return m_age >= 2; };

	virtual bool isOld() {
		std::cout << "Bunny " << getName() << " died! " << std::endl;
		return m_age > 10; }
	// Generate a random bunny

	//static Bunny getRandomBunny() { return getRandomBunny(nullptr); }

	int getRandomNumber(int min, int max) { // random

		std::random_device rd;  //Will be used to obtain a seed for the random number engine
		std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
		std::uniform_int_distribution<> distrib(min, max);

		return distrib(gen);
	}

	bool getRandomMutant() {
		bool vamp{}; // chance of 2%
		if (getRandomNumber(0, 50) == 1) { vamp = true; }
		else { vamp = false; }
		return vamp;
	}

	char getRandomSex() {// random sex
		char sex{};
		if (getRandomNumber(1, 2) == 1) { sex = 'M'; }
		else { sex = 'F'; }
		return sex;
	}

	std::string getRandomName() {
		//std::string name{};
		static std::string bunny_names[20] = {
			"Fluffy", "Dolly", "Tulip", "Miffy", "Olive",
			"Oreo", "Coco", "Daisy", "Cinnamon", "Snowball",
			"Inaba", "Ares", "Jupiter", "Mars", "Weather",
			"Thumper", "Buster", "Benjamin", "Freddie", "Chester" };
		int size = bunny_names->size();
		std::string name{ bunny_names[getRandomNumber(0, size-1)] };
		std::cout << name << std::endl;
		return name;
	}

	std::string getRandomColor() {
		std::string color{};
		int num = getRandomNumber(0, static_cast<int>(ColorType::max_color_type) - 1);
		color = getColorType(static_cast<ColorType>(num));
		return color;
	}

	void printNewBorn() {
		if (getVamp() == false)
			std::cout << "Bunny " << getName() << " was born! " << std::endl;
		else
			std::cout << "Radioactive Mutant Vampire Bunny " << m_name << " was born! " << std::endl;
	}


	virtual Bunny reproduceBunny() {
		std::string name = getRandomName();
			return Bunny{ 'M', getRandomColor(),0,name,false };
	}

};


class FemaleBunny : public Bunny {
public:
	Bunny reproduceBunny() {
		std::string babyColor = getColor();

		if (getRandomSex() == 'F') {
			return FemaleBunny{ babyColor,getRandomName() };
		}
	}
	FemaleBunny(std::string color, std::string name)
		: Bunny{'F', color, 0, name, false}
	
	{}

};

class VampBunny : public Bunny {
public:
	// Bunny():  // make a constructor for vampire bunny, m_vamp{1}
	VampBunny(char sex, std::string color, std::string name)
		: Bunny{sex, color, 0, name, true}
	{};

	void infectBunny(Bunny& regularBunny) {
		regularBunny.makeVamp();
	}

	bool isOld() { 
		std::cout << "Ridioactive mutant vampire bunny " << getName() << " died! " << std::endl;
		return m_age > 50; }

};

