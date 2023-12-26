// LED Flashing Library
#include "Arduino.h"

/*
Example usage:
Flasher slowFlasher(13, 500);
*/
class Flasher
{
	public:
		Flasher(int pin, int duration);
		void flash(int times);
	private:
		int _pin;
		int _d;
};
