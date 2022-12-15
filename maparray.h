#ifndef MAPARRAY_H
#define MAPARRAY_H

#include <iostream>
#include <map>
#include <memory>

template <typename U, typename T> class map_array_util{
	private:
		std::map<U, T> dataref;
		std::map<U, T> themap;
	public:
		map_array_util(std::map<U, T> map){
			dataref = &map;
			themap = map;
		}
		void* getData(){
			return dataref;
		}
		bool equals(const T array[], const int max) const{
			int i = 0;
			for(auto const &x : themap){
				if(themap.at(x.first) != array[i]){
					std::cout << themap.at(x.first) << " != " << array[i] << std::endl;
					return false;
				}
				i++;
			}
			return i == max;
		}
		void copy(const T array[], int to){
		    int i = 0;
			for(auto &x : themap){
				if(i < to){
					x.second = array[i];
					(*dataref)[x.first] = array[i];
					i++;
				}
			}
			*dataref = themap;
		}
		void writemap(){
		    for (auto const &x : themap)
            {
                std::cout << x.first << ", " << x.second << std::endl;
            }
		}
};

#endif