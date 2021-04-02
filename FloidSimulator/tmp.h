#pragma once


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

	CreateObject(int* x, int* y, ObjectType &type);


	void update(RP::Repository& array) {}

	//destruct
	virtual ~CreateObject() {}
};

CreateObject::CreateObject(int x, int y, ObjectType type)
	: m_x(x), m_y(y), m_type(type) {}

CreateObject::CreateObject(int* x, int* y, ObjectType& type)
	: m_x(*x), m_y(*y), m_type(type) {}

CreateObject::update(RP::Repository& array)
{
	if (this->m_type == ObjectType::WATER) 
	{ 
		//defoult for water 
		dx = 0, dy = 1;

		//position point
		int x0 = 0, x1 = 0, x2 = 0, x3 = 0, x4 = 0;

		//collision v.1
		for (int index = 0; index < array.m_size; index++)
		{
			if (array[index].m_y == (this->m_y + 1))
			{
				if (array[index].m_x == (this->m_x - 2)) { x0 = index; }
				if (array[index].m_x == (this->m_x - 1)) { x1 = index; }

				if (array[index].m_x == this->m_x) { x2 = index; }

				if (array[index].m_x == (this->m_x + 1)) { x3 = index; }
				if (array[index].m_x == (this->m_x + 2)) { x4 = index; continue; }
			}
		}


		//collision v.2
		if (!(array[x2].m_type == RP::ObjectType::STONE) && !(array[x2].m_type == RP::ObjectType::WATER)) { this->m_y += this->dy; return; }

		if (!(array[x1].m_type == RP::ObjectType::STONE) && !(array[x1].m_type == RP::ObjectType::WATER))
		{
			dx = 1;
			this->m_x -= this->dx, this->m_y += this->dy;
			return;
		}
		if (!(array[x3].m_type == RP::ObjectType::STONE) && !(array[x3].m_type == RP::ObjectType::WATER))
		{
			dx = 1;
			this->m_x += this->dx, this->m_y += this->dy;
			return;
		}

		if (!(array[x0].m_type == RP::ObjectType::STONE) && !(array[x0].m_type == RP::ObjectType::WATER))
		{
			dx = 2;
			this->m_x -= this->dx, this->m_y += this->dy;
			return;
		}
		if (!(array[x4].m_type == RP::ObjectType::STONE) && !(array[x4].m_type == RP::ObjectType::WATER))
		{
			dx = 2;
			this->m_x += this->dx, this->m_y += this->dy;
			return;
		}
	
	}
	else { dx = 0, dy = 0; }
}





