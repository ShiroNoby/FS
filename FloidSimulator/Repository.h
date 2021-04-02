#ifndef _REPOSITORY_
#define _REPOSITORY_

#include "const.h"


namespace RP
{
	class Repository;
	
	enum class ObjectType
	{
		NON_TYPE,
		WATER,
		STONE
	};
	
	class CreateObject
	{
	public:
		//type object
		ObjectType m_type = ObjectType::NON_TYPE;;


		//position and rotation
		int m_x = 0,	m_y = 0;
		int dx = 0,		dy = 0;

		//construct
		CreateObject() {}

		CreateObject(int x, int y, ObjectType type);

		CreateObject(int* x, int* y, ObjectType& type);


		void update(RP::Repository& array);

		//destruct
		~CreateObject() {}
	}; //->general class(общий класс )

	class Repository
	{
	public:

		CreateObject* m_data;
		int m_length = 1;
		int m_size = 0;


		Repository()
			:m_data(nullptr) {}

		Repository(int lenght);

		void push_back(CreateObject& object);

		void Erase(int index);
		

			//refactroring operator[]/add assert
		CreateObject& operator[](int index)
		{
			if (index >= 0 && index < m_length) { return m_data[index]; }
			return m_data[0];
		}

		void update(RP::Repository &array); 

		~Repository();
	};
}
#endif