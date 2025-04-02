#include "pch.h"
#include "CInventory.h"
#include "CItemSlot.h"
#include "CConsumeItem.h"

void CInventory::Initialize()
{
	m_vecConsumeInven.reserve(5);

	for (int i = 0; i < m_vecConsumeInven.capacity(); ++i)
	{
		m_vecConsumeInven.push_back(new CItemSlot);
	}
}

void CInventory::Release()
{
	for (vector<CItemSlot*>::iterator iter = m_vecConsumeInven.begin();
		iter != m_vecConsumeInven.end(); ++iter)
	{
		Safe_Delete<CItemSlot*>(*iter);
	}
	m_vecConsumeInven.clear();
}

void CInventory::Render()
{
	int iInput = 0;
	while (true)
	{
		Clear();
		
		for (vector<CItemSlot*>::iterator iter = m_vecConsumeInven.begin();
			iter != m_vecConsumeInven.end(); ++iter)
		{
			cout << "==========" << endl;
			(*iter)->Render();
			cout << "==========" << endl;
		}
		
		cout << "(나가기 0) : ";
		cin >> iInput;
		if (InputValid(iInput, 0, 5))
		{
			if (iInput) useItem(m_vecConsumeInven[iInput - 1]);
			break;
		}
	}
}

CItemSlot* CInventory::getEmptySlot()
{
	vector<CItemSlot*>::iterator iter = find_if(m_vecConsumeInven.begin(), m_vecConsumeInven.end(), [](CItemSlot* _pSlot)
		{
			return !_pSlot->getItem();
		});

	if (iter != m_vecConsumeInven.end()) return (*iter);
	else return nullptr;
}

void CInventory::addItem(CItem* _pItem, int _iAmount)
{
	if (getEmptySlot())
	{
		getEmptySlot()->setItem(_pItem, _iAmount);
		cout << "아이템 추가 완료" << endl;
		Sleep(1000);
	}
	else
	{
		cout << "인벤토리가 꽉 찼습니다" << endl;
		Sleep(1000);
	}
}

void CInventory::useItem(CItemSlot* _pItemSlot)
{
	CItem* pTmp = _pItemSlot->getItem();

	if (pTmp)
	{
		static_cast<CConsumeItem*>(pTmp)->Use();
		_pItemSlot->setItemAmount(-1);
		cout << "아이템을 사용하였습니다" << endl;
		Sleep(1000);
	}
	else
	{
		cout << "빈 슬롯 입니다" << endl;
		Sleep(1000);
	}
}

void CInventory::initInventory()
{
	for (auto& inven : m_vecConsumeInven)
	{
		(*inven).initSlot();
	}
}

