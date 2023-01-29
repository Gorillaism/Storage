#include <iostream>

using namespace std;

//Node Class
class Node
{
public:
    int data;
    Node *next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Constructor with data
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

};

//Storage Class
class Storage
{
public:
    Node *head;

    /** Default constructor
     * 
    */
    Storage()
    {
        head = NULL;
    }

    /** Create a Node to hold the data, then put it at the head of the list.
     * @param data The data for the new node
    */
    void push(int data)
    {
        Node *temp = new Node(data);
    if (this->head == NULL)
    {
        this->head = temp;
    }
    else   
    {
        temp->next = this->head;
        this->head = temp;
    }
    }

    /** Remove the head Node and return its data.
     * 
     * @param [out] data (only valid if return true)
     * @return True if there is a node to return
    */
    bool pop(int &data)
    {
    if (this->head == NULL)
    {
        return false;
    }
    else
    {
        data = this->head->data;
        this->head = this->head->next;
        return true;
    }
    }

    /**
     * Return the data from the head Node, without removing it.
     * 
     * @param [out] data (only valid if return true)
     * @return True if text has been returned successfully (there is a node)
    */    
    bool peek(int &data)
    {
    if (this->head == NULL)
    {
        return false;
    }
    else
    {
        data = this->head->data;
        return true;
    }
    }

    /**
     * Return the data from the head Node, without removing it.
     * 
     * @param [out] data (only valid if return true)
     * @return True if text has been returned successfully (there is a node)
    */
    bool isEmpty()
    {
    if (this->head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
    }

    /**
     * Swaps the nodes at position i and j.
     * 
     * @return Returns true if successful, otherwise false (e.g. outside range)
    */
    bool swap(int i, int j)
    {
    // Counter to check how many linked list
    int counter = 0;
    for(Node *temp = this->head; temp != NULL; temp = temp->next)
    {
        counter++;
    }
    if (j == i)
    {
        return true;
    }

    //Create temp pointers
    Node *p1 = NULL;
    Node *p2 = NULL;
    Node *p3 = NULL;
    Node *p4 = NULL;

    //Error message if head is NULL, either of the given positions are out of the range or same position was given
    if (this->head == NULL || i > counter-1 || j > counter-1)
    {
        return false;
    }
    else
    {
    Node *count1 = this->head;
    Node *count2 = this->head;
    if (i > 1 && j > 1)
    {
        if(i % j == 1)
        {   
        for (int t = 1; t < i; t++)
            {
            count1 = count1->next;
            }
            for (int t = 1; t < j; t++)
            {
            count2 = count2->next;
            }
            p1 = count1->next;
            p2 = count1->next->next;
            p3 = count2->next;

            count1->next = p2;
            count2->next = p1;
            count2->next->next = p3;
            return true;
        } else if(j % i == 1)
        {
            for (int t = 1; t < j; t++)
            {
            count1 = count1->next;
            }
            for (int t = 1; t < i; t++)
            {
            count2 = count2->next;
            }
            p1 = count1->next;
            p2 = count1->next->next;
            p3 = count2->next;

            count1->next = p2;
            count2->next = p1;
            count2->next->next = p3;
            return true;
        }
    }
        if (i == 1 && j == 2 || i == 2 && j == 1)
        {
            p1 = count1->next;
            p2 = count1->next->next;
            p3 = count1->next->next->next;

            p1->next = p3;
            p2->next = p1;
            count1->next = p2;

        } else if (i > 1 && j == 0)
        {
            for (int t = 1; t < i; t++)
            {
            count1 = count1->next;
            }
            p1 = count2->next;
            p2 = count1->next;
            p3 = count1->next->next;

            count1->next = count2;
            count2->next = p3;
            this->head = p2;
            this->head->next = p1;

        } else if (i == 0 && j > 1)
        {
            for (int t = 1; t < j; t++)
            {
            count1 = count1->next;
            }
            p1 = count2->next;
            p2 = count1->next;
            p3 = count1->next->next;

            count1->next = count2;
            count2->next = p3;
            this->head = p2;
            this->head->next = p1;

        } else if (i == 0 && j == 1)
        {
            p1 = count1->next;
            p2 = count1->next->next;

            count1->next = p2;
            this->head = p1;
            this->head->next = count1;

        } else if (i == 1 && j == 0)
        {
            p1 = count1->next;
            p2 = count1->next->next;

            count1->next = p2;
            this->head = p1;
            this->head->next = count1;

        } else
        {
            for (int t = 1; t < i; t++)
            {
            count1 = count1->next;
            }
            for (int t = 1; t < j; t++)
            {
            count2 = count2->next;
            }
            p1 = count1->next;
            p2 = count1->next->next;
            p3 = count2->next;
            p4 = count2->next->next;

            count1->next = p3;
            count1->next->next = p2;
            count2->next = p1;
            count2->next->next =p4;
        }
        return true;
    }
    }
};
