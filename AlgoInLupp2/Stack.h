#pragma once
#include "DoubleLinkedList.h"

template <class itemType>
class Stack
{
private:
	DoubleLinkedList<itemType> stackList;

public:
	Stack() {}
	Stack(int maxSize)
	{
		stackList.SetMaxSizeOfItemsInList(maxSize);
	}
	~Stack() {}

	ITEM AddItemToStack(itemType item)
	{
		if (isStackFull())
			return ITEM_FAILED_TO_ADD;
		stackList.AddItemFirst(item);
		return ITEM_SUCCESFULLY_ADDED;
	}

	itemType GetItemFromStack()
	{
		if (isStackEmpty())
			throw std::underflow_error("Stack is Empty");
		itemType temp = stackList.GetFirstItem();
		stackList.DeleteFirst();
		return temp;
	}

	int GetNumberOfItemsInStack()
	{
		return stackList.GetSizeOfList();
	}

	bool isStackFull()
	{
		if (stackList.isListFull())
			return true;
		return false;
	}

	bool isStackEmpty()
	{
		if (stackList.isListEmpty())
			return true;
		return false;
	}

	itemType PeekAtFirstItemInStack()
	{
		return stackList.GetFirstItem();
	}
};
