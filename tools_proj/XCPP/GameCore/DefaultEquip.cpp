/*
 * <auto-generated>
 *	 The code is generated by tools
 *	 Edit manually this code will lead to incorrect behavior
 * </auto-generated>
 */

#include "DefaultEquip.h"

DefaultEquip::DefaultEquip(void)
{
	name = UNITY_STREAM_PATH + "Table/DefaultEquip.bytes";
	ReadTable();
}

void DefaultEquip::ReadTable()
{
	Open(name.c_str());
	long long filesize =0;
	int lineCnt = 0;
	Read(&filesize);
	Read(&lineCnt);
	m_data.clear();
	for(int i=0;i<lineCnt;i++)
	{
		DefaultEquipRow *row = new DefaultEquipRow();
		
		Read(&(row->profid));
		ReadString(row->profname);
		ReadString(row->face);
		ReadString(row->hair);
		ReadString(row->helmet);
		ReadString(row->body);
		ReadString(row->leg);
		ReadString(row->glove);
		ReadString(row->boots);
		ReadString(row->weapon);
		ReadString(row->secondweapon);
		ReadString(row->wing);
		ReadString(row->tail);
		ReadString(row->decal);
		ReadString(row->weaponpoint);
		ReadString(row->wingpoint);
		ReadString(row->tailpoint);
		ReadString(row->fishingpoint);
		ReadString(row->sideweaponpoint);
		m_data.push_back(row);
		m_map.insert(std::make_pair(row->profid, row));
	}
	this->Close();
}

void DefaultEquip::GetRow(int idx,DefaultEquipRow* row)
{
	size_t len = m_data.size();
	if(idx<(int)len)
	{
		*row = *m_data[idx];
	}
	else
	{
		LOG("eror, DefaultEquip index out of range, size: "+tostring(len)+" idx: "+tostring(idx));
	}
}

void DefaultEquip::GetByUID(uint idx, DefaultEquipRow* row)
{
 *row = *m_map[idx];
}

int DefaultEquip::GetLength()
{
	return (int)m_data.size();
}


extern "C"
{
	DefaultEquip *defaultequip;

	int iGetDefaultEquipLength()
	{
		if(defaultequip==NULL)
		{
			defaultequip = new DefaultEquip();
		}
		return defaultequip->GetLength();
	}

	void iGetDefaultEquipRow(int id,DefaultEquipRow* row)
	{
		if(defaultequip==NULL)
		{
			defaultequip = new DefaultEquip();
		}
		defaultequip->GetRow(id,row);
	}

	void iGetDefaultEquipRowByID(uint id, DefaultEquipRow* row)
	{
		if (defaultequip == NULL)
		{
		   defaultequip = new DefaultEquip();
		}
		defaultequip->GetByUID(id, row);
	}
}