#include <stdlib.h>


namespace ads_exp{

    template <typename T>
    class vector{
        
        private:
            int length;
            int capacity;
            T* array;
        
        public:
            class iterator;

        public:
            vector(int _length = 1, T initial_value = 0): length(_length), capacity(_length), array(nullptr){
                array = new T[_length];
                for(int i = 0; i < length; i++) array[i] = initial_value;
            }

            ~vector(){
                delete [] array;
            }

            void push_back(T new_element){
                if(length == capacity){
                    capacity = 2*capacity;
                    T* new_array = (T*)calloc(capacity, sizeof(T));
                    for(int i = 0; i < length; i++) new_array[i] = array[i];
                    free(array);
                    array = new_array;
                }
                
                array[length] = new_element;
                length += 1;
            }

            void pop_back(){
                length -= 1;
            }

            int size() { return length; };
            
            bool empty() { return (length == 0); };

            T& front() { return array[0]; };

            T& back() { return array[length-1]; };

            T* data() { return array; };
    };
}