#pragma once

#include <iostream>

#define MAX_DICT_SIZE 100

template <typename T, typename J>
struct Node
{
    T key;
    J value;
    Node* next;
};

template <typename V>
class Dictionary
{
private:
    Node<const char*, V>** hash;

public:
    Dictionary()
    {
        // Create a new hash list with null pointers
        hash = new Node<const char*, V>*[MAX_DICT_SIZE] {};
    }

    void add(const char* key, V value)
    {
        // Discovery the hash number
        int pos = Dictionary::hashFunction(key);
        Node<const char*, V>* node = this->hash[pos];
        Node<const char*, V>* newNode = new Node<const char*, V>{ key, value };

        // Case is the first element
        if (node == NULL)
            this->hash[pos] = newNode; // Append itself as first element
        
        // Case exists colision
        else
        {
            // Pass by all the elements in linked list
            while (node)
            {
                if (node->next == NULL) // Compare if the next node is empty
                {
                    node->next = newNode; // Append itself in linked list
                    break;
                }

                node = node->next; // Call the next node
            }
        }
    }

    V get(const char* key)
    {
        // Discovery the hash number
        int pos = Dictionary::hashFunction(key);
        Node<const char*, V>* node = this->hash[pos];

        // Loop through the colision list
        while (node)
        {
            // Compare the key
            if (strcmp(node->key, key) == 0)
                return node->value;

            node = node->next; // Call the next node
        }

        return *(new V());
    }

    void pop(const char* key)
    {
        // Discovery the hash number
        int pos = Dictionary::hashFunction(key);
        Node<const char*, V>* node = this->hash[pos];
        Node<const char*, V>* previousNode = NULL;

        // Loop through the colision list
        while (node)
        {
            // Compare the key
            if (strcmp(node->key, key) == 0)
            {
                if (previousNode)
                    previousNode->next = node->next; // Case isn't the firt element
                else
                    this->hash[pos] = node->next; // Case is the first element

                return;

            }
            

            previousNode = node; // Atual node becoumes the previos nod
            node = node->next; // Call the next node
        }
    }

    static int hashFunction(const char* key, unsigned long seed = 4242)
    {
        unsigned long hash = seed;
        unsigned char c;

        // Interrate over the key
        while (c = *key++)
        {
            // Sum the hash
            hash = ((hash << 5) / 3) + hash + c;
        }

        // Limit the value from 0 to above of array size
        return hash % MAX_DICT_SIZE;
    }
};