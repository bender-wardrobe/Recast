/**
 * @file SpellEntity.cpp
 * @author LionZXY
 * @project Recast-server
 * @date 25.06.17
 * @email nikita@kulikof.ru
 **/
#include <Box2D/Box2D.h>
#include "world/wrappers/SpellEntity.h"
#include "spells/Spell.hpp"

SpellEntity::SpellEntity(b2Fixture *fixture1, Spell *spell, Box2DWorld *world) : Entity(fixture1), spell(spell),
                                                                                 listener(this, world) {}

void SpellEntity::update(Box2DWorld *box2DWorld) {
    spell->tickSpell(listener);
}

SpellEntity::~SpellEntity() {
    delete spell;
}
