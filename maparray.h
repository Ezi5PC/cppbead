#include <iostream>
#include <map>

template <typename U, typename T> class map_array_util{
	private:
		std::map<U, T> &dataref;
	public:
		map_array_util(std::map<U, T> map) : dataref(map){}
		bool equals(T array[], int max){
			for(int i = 0; i < max; i++){
				if(dataref.at(i) != array[i]){
					return false;
				}
			}
			return true;
		}
		void copy(const T array[], int to){
    		size_t i = 0;
    		for(auto &x : dataref){
				if(i < to){
           	 		x.second = array[i];
        		}
        		i++;
    		}
    		writemap();
		}
		void writemap(){
		    for (auto const& x : dataref)
            {
                std::cout << x.first  // string (key)
                << ':' 
                 << x.second // string's value 
                << std::endl;
            }
		}
};