//#include "bunnyFarm.h"
//#include <stdlib.h>     /* srand, rand */
//#include <random>
//#include <cmath>
//#include <iterator>
//#include <algorithm>
//
//
//
//
//
//void createBunny(std::list<Bunny>& bunnyYard) {
//	std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
//	std::rand(); // get rid of first result
//
//	//	So long as there is at least one male age 2 or older, for each female bunny in the list age 2 or older;
//	//	a new bunny is created each turn. (i.e. if there was 1 adult male and 3 adult female bunnies, three new bunnies would be born each turn)
//	//	New bunnies born should be the same color as their mother.
//	std::list<Bunny> femaleYard{};
//	std::list<Bunny> maleYard{};
//	for (Bunny& b : bunnyYard) {
//		if (!b.getVamp()) { // vamp bunnies are excluded.
//			if (b.getAge() >= 2) {
//				b.getSex() == 'F' ? femaleYard.push_back(b) : maleYard.push_back(b);
//			}
//		}
//	}
//	if(maleYard.size()!=0){
//
//		for (Bunny& b : femaleYard) {
//			bunnyYard.push_back(Bunny::getRandomBunny(&b));
//		}
//
//	}
//}
//
//
//void mutantBunny(std::list<Bunny>& bunnyYard) {
//
//	std::list<Bunny> normalYard{};
//	std::list<Bunny> mutantYard{};
//
//	for (Bunny& b : bunnyYard) {
//		b.getVamp() ? mutantYard.push_back(b) : normalYard.push_back(b);
//	}
//
//	if (mutantYard.size() != 0)
//	{
//		for (int i = 0; i < mutantYard.size(); i++) {
//			int randomMutant = getRandomNumber(0, normalYard.size());
//			// Create iterator pointing to first element
//			std::list<Bunny>::iterator it = normalYard.begin();
//			// Advance the iterator by 2 positions,
//			std::advance(it, randomMutant);
//			Bunny mutantBunny = *it;
//			std::cout << "Bunny " << mutantBunny.getName() << " becomes a mutant bunny!" << std::endl;
//			mutantBunny.makeMutant();
//		}
//	}
//}