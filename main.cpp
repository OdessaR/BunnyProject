#include <iostream>
#include "bunnyFarm.h"
#include "bunny.h"
#include <list>

void createBunny(std::list<Bunny>& bunnyYard);
void checkOldBunny(std::list<Bunny>& bunnyYard);
void mutantBunny(std::list<Bunny>& bunnyYard);

int main() {

	//At program initialization 5 bunnies must be created and given random colors.
	// 
	// *************** Begin of initialization **************

	BunnyFarm bunnyYard{};
	for (int i = 0 ; i < 5; i++) {
		bunnyYard.createBunny();
	}
	

	//std::list<Bunny> bunnyYard{};
	//for (int i = 0; i < 5; i++) {
	//	bunnyYard.push_back(Bunny::getRandomBunny());
	//}

	//int round{0};
	////while (bunnyYard.size() != 0) {
	//while (round < 10) {
	//	std::cout << "This is round " << round << std::endl;
	//	std::cout << "Bunny yard now has " << bunnyYard.size() << " bunnies. " << std::endl;
	//	// check of number exceed

	//	// continue with rounds.
	//	createBunny(bunnyYard);
	//	checkOldBunny(bunnyYard);
	//	mutantBunny(bunnyYard);
	//	// each turn bunnies age one year. 
	//	for (Bunny& b : bunnyYard) {
	//		b.makeOlder();
	//	}
	//	round++;
	//}


	// *************** End of initialization **************




	return 0;
}