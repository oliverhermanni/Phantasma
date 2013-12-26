//
//  Area.cpp
//  Phantasma
//
//  Created by Thomas Harte on 25/12/2013.
//  Copyright (c) 2013 Thomas Harte. All rights reserved.
//

#include "Area.h"

Object *Area::objectWithIDFromMap(ObjectMap *map, uint16_t objectID)
{
	if(!map) return NULL;
	if(!map->count(objectID)) return NULL;
	return (*map)[objectID].get();
}

Object *Area::objectWithID(uint16_t objectID)
{
	return objectWithIDFromMap(objectsByID, objectID);
}

Object *Area::entranceWithID(uint16_t objectID)
{
	return objectWithIDFromMap(entrancesByID, objectID);
}

uint16_t Area::getAreaID()
{
	return areaID;
}

Area::Area(
	uint16_t _areaID,
	ObjectMap *_objectsByID,
	ObjectMap *_entrancesByID)
{
	areaID = _areaID;
	_objectsByID = objectsByID;
	_entrancesByID = entrancesByID;
}

Area::~Area()
{
	delete objectsByID;
	delete entrancesByID;
}