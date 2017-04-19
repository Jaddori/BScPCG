#pragma once

namespace Utilities
{
	template<typename T>
	class Array
	{
	public:
		static const int DEFAULT_SIZE = 10;

		Array(){};
		Array(const Array& ref){};
		Array(int initialSize){};
		virtual ~Array(){};

		Array& operator=(const Array& ref){ return *this;};
		T& operator[](int index){return *data;};
		T& at(int index){ return *data; };

		void add(T item){};
		void removeItem(const T& item){};
		void removeAt(int index){};
		void clear(){};
		void reserve(int size){};

		T* getData(){ return data; };
		int getSize() const{ return 0; };
		int getCapacity() const{ return 0; };

	private:
		T* data;
		int size;
		int capacity;
	};
}