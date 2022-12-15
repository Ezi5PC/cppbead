#include <iostream>
#include <map>
#define MIN(a, b) (a > b ? b : a;)

template <typename U, typename T> class map_array_util{
	private:
		std::map<U, T> * dataptr;
	public:
		map_array_util(std::map<U, T> map) : data(&map){}
		bool equals(T array[], int max){
			for(int i = 0; i < max; i++){
				if(*dataptr->at(i) != array[i]){
					return false;
				}
			}
			return true;
		}
		void copy(T array[], int to){
			for(int i = 0; i < MIN(MIN(*dataptr->size(), sizeof(array) / sizeof(array[0])), to); i++){
			    if(array[i] != nullptr){
			        *dataptr->at(i) = array[i];
			    }
			}
		}
};
