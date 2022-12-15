#include <iostream>
#define MIN(a, b) (a > b ? b : a;)

template <typename U, typename T> class map_array_util{
	private:
		std::map<U, T> data;
	public:
		map_array_util(std::map<U, T> map) : data(map){}
		bool equals(T[] array, int max){
			for(int i = 0; i < max; i++){
				if(data.at(i) != array[i]){
					return false;
				}
			}
			return true;
		}
		void copy(T[] array, int to){
			
		}
};