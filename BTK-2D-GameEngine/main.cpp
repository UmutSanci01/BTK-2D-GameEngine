#include <iostream>
#include <SDL2/SDL.h>

class Deneme
{
	public:
		Deneme(int a)
		{
			std::cout << a << std::endl;
		}
};

int main(int argc, char** argv)
{
	Deneme denek(25), denememek(12);


	return 0;
}