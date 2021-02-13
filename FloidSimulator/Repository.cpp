#include "Repository.h"

namespace RP 
{
	CreateObject::CreateObject(int* x, int* y, int lenght, int weight) 
		: m_x(*x), m_y(*y), m_lenght(lenght), m_weight(weight) 
	{
		m_type = ObjectType::NON_TYPE;
	}

	CreateObject::CreateObject(int x, int y, int lenght, int weight)
		:m_x(x), m_y(y), m_lenght(lenght), m_weight(weight) 
	{
		m_type = ObjectType::NON_TYPE;
	}
	
	Repository::Repository(int lenght) 
		: m_length(lenght) 
	{
		if (m_length > 0) { m_data = new CreateObject[m_length]; }
		else m_data = nullptr;
	}

	void Repository::push_back(CreateObject &object) 
	{
		if (m_size == m_length) 
		{
			m_length *= 2;
			CreateObject *tmp = new CreateObject[m_length];
			tmp = m_data; delete[] m_data; m_data = tmp;
		}

		m_data[m_size++] = object;
	}
	
	void Repository::Erase(int index)
	{
		for (index; index < this->m_size; index++) 
		{
			this->m_data[index] = this->m_data[index + 1];
			this->m_size--;
		}
	}
		
	void Repository::update(RP::Repository &array)
	{
		for (int index = 0; index < m_size; index++) 
		{
			if (m_data[index].m_type == ObjectType::WATER) { m_data[index].update(array); }
			
		} 
	}
		
	Repository::~Repository() 
	{
		delete[] m_data;
		m_data = nullptr;
	}
}