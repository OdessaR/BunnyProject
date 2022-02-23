#pragma once
#include <iostream>
#include <list>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <random>
#include <cmath>
#include <iterator>
#include <algorithm>
#include "bunny.h"

class BunnyFarm {
private:
	int m_tick{ 0 };
	std::list<Bunny> m_bunnyYard;

public:
	void increaseTick() { m_tick++; }
	int checkBunnyNumber() { return m_bunnyYard.size(); }
	void printFarmInfo() {
		std::cout << "This is round " << m_tick << std::endl;
		std::cout << "Bunny yard now has " << m_bunnyYard.size() << " bunnies. " << std::endl;
	};

	// remove too old bunnies
	//bool old_bunny( Bunny& b) {
	//	return b.isOld();
	//}
	//void killOldBunny() {
	//	m_bunnyYard.remove_if(&this->old_bunny);
	//}

	int countAdultMaleBunny() {
		int count{0};
		for (auto b : m_bunnyYard) {
			if (b.getSex() == 'M' && !b.getVamp()&&b.isAdult()){count++;}
		}
		return count;
	}

	Bunny createBunny() {
		//if (countAdultMaleBunny() > 0) {
		//	for (auto b : m_bunnyYard) {	// iterate through bunnyYard
		//		if (!b.getVamp()&&b.getSex()!='M') {	// skip vampire bunny
		//			auto newBorn = b.reproduceBunny();	
		//			m_bunnyYard.push_back(newBorn);
		//			newBorn.printNewBorn();
		//			return newBorn;
		//		}
		//	}
		//}
		Bunny newBorn{};
		newBorn.printNewBorn();
		return newBorn;
	}
	
};