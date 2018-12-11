#pragma once

typedef enum
{
	ITEM_SUCCESFULLY_ADDED,
	ITEM_FAILED_TO_ADD
}ITEM;

typedef enum
{
	SIZEOFLIST_INFINITE
}SIZEOFLIST;

template <class itemType>
class DoubleLinkedList
{

private:
	class DoubleNode
	{
	private:
		itemType item;
		DoubleNode *next;
		DoubleNode *prev;

		DoubleNode()
		{
			this->next = nullptr;
			this->prev = nullptr;
		}

		DoubleNode(itemType item)
		{
			this->next = nullptr;
			this->prev = nullptr;
			this->item = item;
		}
		~DoubleNode()
		{
		}
		friend class DoubleLinkedList;
	};
	DoubleNode *head;
	DoubleNode *tail;
	int numberOfItemInList;
	int maxSizeOfItemsInList;

public:
	DoubleLinkedList()
	{
		this->head = nullptr;
		this->tail = nullptr;
		this->numberOfItemInList = 0;
		this->maxSizeOfItemsInList = SIZEOFLIST_INFINITE;
	}
	DoubleLinkedList(int maxSize)
	{
		this->head = nullptr;
		this->tail = nullptr;
		this->numberOfItemInList = 0;
		this->maxSizeOfItemsInList = maxSize;
	}

	~DoubleLinkedList()
	{
		DoubleNode* current = this->head;
		DoubleNode* next;

		while (current != NULL) {
			next = current->next;
			//delete current->item; //måste ha template specialization 
			delete current;
			current = next;
		}
	}


	ITEM AddItemFirst(itemType item)
	{
		DoubleNode *newNode = new DoubleNode(item);

		if (isListFull())
			return ITEM_FAILED_TO_ADD;

		if (isListEmpty())
			this->tail = newNode;
		else
		{
			newNode->next = this->head;
			this->head->prev = newNode;
		}

		this->head = newNode;
		this->numberOfItemInList++;
		return ITEM_SUCCESFULLY_ADDED;
	}

	ITEM AddItemLast(itemType item)
	{
		DoubleNode *newNode = new DoubleNode(item);

		if (isListFull())
			return ITEM_FAILED_TO_ADD;

		if (isListEmpty())
			this->head = newNode;
		else
		{
			this->tail->next = newNode;
			newNode->prev = this->tail;
		}

		this->tail = newNode;
		this->numberOfItemInList++;
		return ITEM_SUCCESFULLY_ADDED;
	}

	ITEM AddItemBeforePosition(itemType item, int position)
	{
		DoubleNode *newNode = new DoubleNode(item);
		DoubleNode *tempNode = new DoubleNode;
		if (position == 0)
			return AddItemFirst(item);
		else
		{
			if (isListFull() || position > numberOfItemInList || position < 0)
				return ITEM_FAILED_TO_ADD;
			if (isListEmpty())
			{
				this->head = newNode;
				this->tail = newNode;
			}
			tempNode = this->head;
			for (int i = 0; i <= position; i++)
			{
				if (i == position)
				{
					tempNode->prev->next = newNode;
					newNode->prev = tempNode->prev;
					newNode->next = tempNode;
					tempNode->prev = newNode;
					this->numberOfItemInList++;
					return ITEM_SUCCESFULLY_ADDED;
				}
				tempNode = tempNode->next;
			}
		}
	}

	bool IsPositionValid(int position)
	{
		if (position >= numberOfItemInList || position < 0)
			return false;
		return true;
	}

	void DeleteFirst()
	{
		DoubleNode *nodeToBeDeleted = this->head;
		if (numberOfItemInList == 1)
		{
			this->head = nullptr;
			this->tail = nullptr;
		}
		else
		{
			this->head = this->head->next;
			this->head->prev = nullptr;
		}
		delete nodeToBeDeleted;
		numberOfItemInList--;
	}

	void DeleteLast()
	{
		DoubleNode *nodeToBeDeleted = this->tail;
		if (numberOfItemInList == 1)
		{
			this->head = nullptr;
			this->tail = nullptr;
		}
		else
		{
			this->tail = this->tail->prev;
			this->tail->next = nullptr;
		}
		delete nodeToBeDeleted;
		numberOfItemInList--;
	}

	void DeletePosition(int positionToDelete)
	{
		if (positionToDelete == 0)
		{
			DeleteFirst();
			return;
		}
		if (positionToDelete == numberOfItemInList - 1)
		{
			DeleteLast();
			return;
		}
		DoubleNode *tempNode = new DoubleNode;
		tempNode = this->head;
		for (int position = 0; position <= positionToDelete; position++)
		{
			if (position == positionToDelete)
			{
				tempNode->next->prev = tempNode->prev;
				tempNode->prev->next = tempNode->next;
				delete tempNode;
				numberOfItemInList--;
				return;
			}
			tempNode = tempNode->next;
		}
	}

	itemType GetItemAtPosition(int positionToGet)
	{
		DoubleNode *tempNode = new DoubleNode;
		tempNode = this->head;
		for (int position = 0; position <= positionToGet; position++)
		{
			if (position == positionToGet)
			{
				return tempNode->item;
			}
			tempNode = tempNode->next;
		}
	}

	itemType GetFirstItem()
	{
		return this->head->item;
	}

	itemType GetLastItem()
	{
		return this->tail->item;
	}

	itemType& operator[] (int positionToGet)
	{
		DoubleNode *tempNode = new DoubleNode;
		tempNode = this->head;
		for (int position = 0; position <= positionToGet; position++)
		{
			if (position == positionToGet)
			{
				return tempNode->item;
			}
			tempNode = tempNode->next;
		}
	}

	bool isListEmpty()
	{
		if (numberOfItemInList == 0)
			return true;
		else
			return false;
	}

	bool isListFull()
	{
		if (numberOfItemInList < maxSizeOfItemsInList || maxSizeOfItemsInList == SIZEOFLIST_INFINITE)
			return false;
		else
			return true;
	}

	int GetSizeOfList()
	{
		return this->numberOfItemInList;
	}

	void SetMaxSizeOfItemsInList(int size)
	{
		this->maxSizeOfItemsInList = size;
	}

	int GetMaxSizeOfItemsInList()
	{
		return this->maxSizeOfItemsInList;
	}
};

