

#include<iostream>
#include<random>
#include<string>
#include <time.h>


class Dice {
public: 
		Dice(); // default constructor
		Dice(int numSides); //full-arg Constructor
		virtual int rollDice()const; //virutal function that is not yet defined 

protected:
	int numSides; 
};

Dice::Dice() { // dice function that uses the dice class 
	numSides = 6; 
	srand(time(NULL)); // seeds the random number generator 

}

Dice::Dice(int numSides) {
	this->numSides = numSides;
	srand(time(NULL)); // seeds the random number generator 

}

int Dice::rollDice()const {
	return (rand() % numSides) + 1; 
}

//returns the sum of two diced rolled
int rollTwoDice(const Dice& die1, const Dice& die2) {
	return die1.rollDice() + die2.rollDice(); // implements the virtual function 
}

//creating the loaded dice class 

class LoadedDice: public Dice { // the class loaded dice is a child class of dice 
public:
	int numofsides = 6; 

	//constructors 

	LoadedDice(); 
	LoadedDice(int numofsides); 
	int rollDice()const;

	
};

LoadedDice::LoadedDice() { // dice function that uses the dice class 
	numofsides = 6;
	srand(time(NULL)); // seeds the random number generator 

}

LoadedDice::LoadedDice(int numofsides) { // dice function that uses the dice class 
	this->numofsides = numofsides; // the -> are used to reference individual members of a class 
	srand(time(NULL)); // seeds the random number generator 

}

int LoadedDice::rollDice() const { // this function takes a greater value of the two dice and return 50% more a redefiniton of the roll dice function
	if ((rand() % 2 + 1 == 1)) {
		return(rand() % numofsides + 1);
	}
	else {
		return numofsides;
	}
}
int main() {

	//dice objects 
	Dice a(6);
	Dice b(6); 
	int i = 0; 
	std::cout << "The two regular dice are: " << std::endl;
	int aAdd=0; 


	while (i != 10) { //rolling the two regular dice 
		std::cout << "Object a Rolls: " <<a.rollDice() << std::endl; 
		//std::cout << "Object B Rolls: "<< b.rollDice() << std::endl; 
		aAdd += a.rollDice(); 
		i++; 
	}
	

	//loaded dice objects 
	LoadedDice c(6); 
	LoadedDice d(6); 
	int q = 0;
	int cAdd = 0; 
	std::cout << "The loaded dice added are: " << std::endl; 
	while (q != 10) {
		std::cout << "Object C rolls are: " << c.rollDice() << std::endl;
		//std::cout <<"Object D rolls are: " <<d.rollDice() << std::endl; 
		cAdd += c.rollDice(); 
		q++;
	}

	//adding the dice and comparing averages from loaded versus not loaded dice 
	double aAvg = aAdd / 10;
	std::cout << "The average of A's dice rolls are(NOT loaded dice): " << aAvg << std::endl;
	double cAvg = cAdd / 10; 
	std::cout << "The average of C's dice rolls are (loaded dice): " << cAvg << std::endl;
}
