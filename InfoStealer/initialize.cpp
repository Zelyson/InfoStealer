#include "initialize.hpp"
#include "persistance.hpp"

void initialize::init(char const* argv[]) {
	persistance* persist = new persistance(argv);
	persist->persist(argv);
	delete(persist);


}

void test() {

}