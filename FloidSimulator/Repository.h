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

		ObjectType m_type;

		int m_x = 0, m_y = 0;
		int m_lenght = cnst::horizontal;
		int m_weight = cnst::vertical;

		CreateObject() { m_type = ObjectType::NON_TYPE; }
		CreateObject(int x, int y, int lenght = cnst::horizontal, int weight = cnst::vertical);
		CreateObject(int* x, int* y, int lenght = cnst::horizontal, int weight = cnst::vertical);

		virtual void update(RP::Repository& array) {}

		virtual ~CreateObject() {}
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

		virtual void update(RP::Repository &array); 

		~Repository();
	};
}
#endif