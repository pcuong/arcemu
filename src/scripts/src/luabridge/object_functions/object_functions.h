#pragma once
class luaobject;

namespace lua_engine
{
	void bindObjectMethods(luabridge::module & m)
	{
		 m	.class_<Object>("Object")
			.method("GetGUID", &Object::GetGUID)
			.method("GetHighGUID", &Object::GetHighGUID)
			.method("GetLowGUID", &Object::GetLowGUID)
			.method("GetNewGUID", &Object::GetNewGUID)
			.method("GetEntry", &Object::GetEntry)
			.method("GetScale", &Object::GetScale)
			.method("SetScale", &Object::SetScale)
			.method("GetTypeFromGUID", &Object::GetTypeFromGUID)
			.method("GetEntryFromGUID", &Object::GetEntryFromGUID)
			.method("GetTypeID", &Object::GetTypeId)
			.method("IsUnit", &Object::IsUnit)
			.method("IsGameObject", &Object::IsGameObject)
			.method("IsPlayer", &Object::IsPlayer)
			.method("IsItem", &Object::IsItem)
			.method("IsCreature", &Object::IsCreature)
			.method("IsPet", &Object::IsPet)
			.method("SetPosition", ( bool(Object::*)(float,float,float,float,bool) )&Object::SetPosition)
			.method("GetPositionX", &Object::GetPositionX)
			.method("GetPositionY", &Object::GetPositionY)
			.method("GetPositionZ", &Object::GetPositionZ)
			.method("GetOrientation", &Object::GetOrientation)
			.method("GetO", &Object::GetOrientation)
			//.method("SetO", &Object::SetOrientation)
			//.method("SetOrientation", &Object::SetOrientation)		
			.method("GetSpawnX", &Object::GetSpawnX)
			.method("GetSpawnY", &Object::GetSpawnY)
			.method("GetSpawnZ", &Object::GetSpawnZ)
			.method("GetSpawnO", &Object::GetSpawnO)
			//.method("GetPosition", &Object::GetPosition)
			.method("CalcDistance2Object", ( float(Object::*)(Object*) )&Object::CalcDistance)
			.method("CalcDistance2Location", ( float(Object::*)(float,float,float) )&Object::CalcDistance)
			.method("CalcDistanceBtwnObjects", (float (Object::*)(Object*,Object*) )&Object::CalcDistance)
			.method("CalcDistanceObject2Location", (float(Object::*)(Object*,float,float,float) )&Object::CalcDistance)
			.method("CalcDistanceLocation2Location", (float(Object::*)(float,float,float,float,float,float) )&Object::CalcDistance)
			//.method("GetMapMgr", &Object::GetMapMgr)
			.method("GetMapID", &Object::GetMapId)
			.method("GetZoneID", &Object::GetZoneId)
			.method("SetZoneID", &Object::SetZoneId)
			.method("SetMapID", &Object::SetMapId)
			.method("GetUInt32Value", &Object::GetUInt32Value)
			.method("GetUInt64Value", &Object::GetUInt64Value)
			.method("SetUInt32Value", &Object::SetUInt32Value)
			.method("SetUInt64Value", &Object::SetUInt64Value)
			.method("GetFloatValue", &Object::GetFloatValue)
			.method("ModFloatValue", &Object::ModFloatValue)
			.method("ModFloatValueByPCT", &Object::ModFloatValueByPCT)
			.method("ModSignedUInt32Value", &Object::ModSignedInt32Value)
			.method("ModUnsignedUInt32Value", &Object::ModUnsigned32Value)
			.method("GetByte", &Object::GetByte)
			.method("SetByte", &Object::SetByte)
			.method("SetByteFlag", &Object::SetByteFlag)
			.method("RemoveByteFlag", &Object::RemoveByteFlag)
			.method("HasByteFlag", &Object::HasByteFlag)
			.method("EventSetUInt32Value", &Object::EventSetUInt32Value)
			.method("SetFloatValue", &Object::SetFloatValue)
			.method("SetFlag", &Object::SetFlag)
			.method("HasFlag", &Object::HasFlag)
			.method("IsInRange", &Object::isInRange)
			.method("IsInFront", &Object::isInFront)
			//.method("SetInFront", &Object::setInFront)
			.method("IsBehind", &Object::isInBack)
			.method("IsInArc", &Object::isInArc)
			.method("calcAngle", &Object::calcAngle)
			.method("calcRadAngle", &Object::calcRadAngle)
			.method("getEasyAngle", &Object::getEasyAngle)
			.method("GetDistance2Object", (const float(Object::*)(Object*) )&Object::GetDistanceSq)
			//.method("GetDistanceSq", (float(Object::*)(LocationVector&) )&Object::GetDistanceSq)
			.method("GetDistance", (const float(Object::*)(float,float,float) )&Object::GetDistanceSq)
			.method("GetCurrentSpell", &Object::GetCurrentSpell)
			.method("SetCurrentSpell", &Object::SetCurrentSpell);

		 //creatable and destroyable in the lua environment.
		 m	.class_<Arcemu::Gossip::Menu>("GossipMenu", true)
			.constructor< void(*)(Object*, uint32, uint32) > ()
			.method("AddItem", ( void(Arcemu::Gossip::Menu::*)(uint8,const char*, uint32, bool) )&Arcemu::Gossip::Menu::AddItem)
			.method("AddMenuItem", ( void(Arcemu::Gossip::Menu::*)(uint8, const char *, uint32, uint32, const char*, bool) )&Arcemu::Gossip::Menu::AddItem)
			.method("Send", &Arcemu::Gossip::Menu::Send)
			.method("getLanguage", &Arcemu::Gossip::Menu::getLanguage)
			.method("setLanguage", &Arcemu::Gossip::Menu::setLanguage)
			.method("setTextID", &Arcemu::Gossip::Menu::setTextID)
			.method("getTextID", &Arcemu::Gossip::Menu::getTextID);
		 
		 m	.subclass<DynamicObject, Object>("DynamicObject")
			.constructor< void(*)(uint32,uint32) >()
#define BIND(name) .method(#name, &DynamicObject::name)
			 BIND(Create)
			 BIND(Remove);
#undef BIND

	}
}