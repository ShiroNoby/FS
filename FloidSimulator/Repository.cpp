#include "Repository.h"
#include "const.h"
#include "GameLogic.h"

namespace RP 
{
	CreateObject::CreateObject(int x, int y, ObjectType type)
		: m_x(x), m_y(y), m_type(type) {}


	CreateObject::CreateObject(int* x, int* y, ObjectType& type)
		: m_x(*x), m_y(*y), m_type(type) {}


	void CreateObject::update(RP::Repository& array)
	{
		if (this->m_y > cnst::W_Weight) { GL::Erase(this->m_x, this->m_y, array); }
			
		//defoult for water 
		dx = 0, dy = 1;

		//collision
		//проверка пространства под блоком(x,y+1)
						//проверка пространства(x+1,y+1)
						//проверка пространства(x-1,y+1)
						//проверка пространства(x+2,y+1)
						//проверка пространства(x-2,y+1)

		//проверка пространства под блоком(x,y+1)
			for (int index = 0; index < array.m_size;index++)
			{
				if (array[index].m_y == (this->m_y + 1))
				{
					if (array[index].m_x == (this->m_x)) { dy = 0; continue; }

				}
			}this->m_y += dy;
			if (dy) { dy = 1; return; }
			
			dy = 1, dx = 1;

			//проверка пространства(x+1,y+1)
			for (int index = 0; index < array.m_size;index++)
			{
				if (array[index].m_y == (this->m_y + 1))
				{
					if (array[index].m_x == (this->m_x + 1)) { dx = 0, dy = 0; continue; }

				}
			}this->m_y += dy, this->m_x+=dx;
			if (dy) { dy = 1; return; }


			dy = 1, dx = 1;

			//проверка пространства(x-1,y+1)
			for (int index = 0; index < array.m_size;index++)
			{
				if (array[index].m_y == (this->m_y + 1))
				{
					if (array[index].m_x == (this->m_x - 1)) { dx = 0, dy = 0; continue; }

				}
			}this->m_y += dy, this->m_x -= dx;
			if (dy) { dy = 1; return; }


			dy = 1, dx = 2;

			//проверка пространства(x+2,y+1)
			for (int index = 0; index < array.m_size;index++)
			{
				if (array[index].m_y == (this->m_y + 1))
				{
					if (array[index].m_x == (this->m_x + 2)) { dx = 0, dy = 0; continue; }

				}
			}this->m_y += dy, this->m_x += dx;
			if (dy) { dy = 1; return; }


			dy = 1, dx = 2;

			//проверка пространства(x-2,y+1)
			for (int index = 0; index < array.m_size;index++)
			{
				if (array[index].m_y == (this->m_y + 1))
				{
					if (array[index].m_x == (this->m_x - 2)) { dx = 0, dy = 0; continue; }

				}
			}this->m_y += dy, this->m_x -= dx;
			dy = 1;
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
			m_data[index] = m_data[(index + 1)];
		}
		m_size--;
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