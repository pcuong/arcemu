/*
 * ArcEmu MMORPG Server
 * Copyright (C) 2005-2007 Ascent Team <http://www.ascentemu.com/>
 * Copyright (C) 2008-2010 <http://www.ArcEmu.org/>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "StdAfx.h"

initialiseSingleton( SpellFactoryMgr );

void SpellFactoryMgr::AddByEntry(SpellEntry *info, spell_factory_function spell_func)
{
	if( info != NULL )
		info->SpellFactoryFunc = (void*(*)) spell_func;
}

void SpellFactoryMgr::AddById(uint32 spellId, spell_factory_function spell_func)
{
	AddByEntry( dbcSpell.LookupEntryForced(spellId), spell_func );
}

void SpellFactoryMgr::AddByNameHash(uint32 name_hash, spell_factory_function spell_func)
{
	uint32 cnt = dbcSpell.GetNumRows();
	SpellEntry * sp;

	for( uint32 x= 0; x < cnt; x++ )
	{
		sp = dbcSpell.LookupRow(x);

		if( sp->NameHash != name_hash )
			continue;

		AddByEntry( sp, spell_func );
	}
}

Spell* SpellFactoryMgr::NewSpell(Object* Caster, SpellEntry *info, bool triggered, Aura* aur)
{
	if( info->SpellFactoryFunc == NULL )
		return new Spell(Caster, info, triggered, aur);
	else
	{
		spell_factory_function ptr;
		ptr = *spell_factory_function(info->SpellFactoryFunc);
		return (*ptr)(Caster, info, triggered, aur); 
	}
}

void SpellFactoryMgr::Setup()
{
	SetupDeathKnight();
	SetupDruid();
	SetupHunter();
	SetupMage();
	SetupPaladin();
	SetupPriest();
	SetupRogue();
	SetupShaman();
	SetupWarlock();
	SetupWarrior();
}
