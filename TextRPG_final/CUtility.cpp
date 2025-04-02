#include "pch.h"
#include "CUtility.h"

int CUtility::calculateAttack(int _iAttack, int _iDefence)
{
    int iDamage = _iAttack - _iDefence;
    if (iDamage <= 0) iDamage = 1;

    return iDamage;
}
