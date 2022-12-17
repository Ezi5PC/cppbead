#ifndef MAPARRAY_H
#define MAPARRAY_H

#include <iostream>
#include <map>
#include <memory>

template <typename U, typename T> class map_array_util{
	private:
		std::map<U, T> * dataptr;
	public:
		map_array_util(std::map<U, T> map) : dataptr(&map){}
		bool equals(T array[], int max){
			for(int i = 0; i < max; i++){
				if(*dataptr->at(i) != array[i]){
					return false;
				}
				i++;
			}
			return i == max;
		}
		void copy(T array[], int to){
		    int i = 0;
		    for (auto &x : *dataptr)
            {
                if(i < to){
                    x.second = array[i];
                }
                i++;
            }
		    writemap();
		}
		void writemap(){
		    for (auto const& x : *dataptr)
            {
                std::cout << x.first << ", " << x.second << std::endl;
            }
		}
};

#endif