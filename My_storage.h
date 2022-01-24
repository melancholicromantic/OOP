#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#include "Thing.h"
#include <iostream>

class My_storage
{
private:
    Thing** objects;
    int size;

public:
    My_storage(int size)
    {
        this->size = size;
        objects = new Thing * [size];
    }

    ~My_storage()
    {
        delete[] objects;
    }

    void setObject(int i, Thing* object)
    {
        objects[i] = object;
    }

    int getCount()
    {
        return size;
    }

    Thing& getObject(int i)
    {
        return *objects[i];
    }

    void nullObject(int i)
    {
        objects[i] = NULL;
    }

    void deleteObject(int index)
    {
        size--;

        Thing** new_objects = new Thing * [size];

        for (int i = 0; i < index; i++)
        {
            new_objects[i] = objects[i];
        }

        for (int i = index; i < size; i++)
        {
            new_objects[i] = objects[i + 1];
        }

        delete[] objects;

        objects = new_objects;
    }

    void addObjects(int index, Thing* object)
    {
        size = index + 1;
        Thing** new_objects = new Thing * [size];

        for (int i = 0; i < index; i++)
            new_objects[i] = objects[i];

        delete[] objects;

        objects = new_objects;

        objects[index] = object;
    }

    int getVolume()
    {
        int volume = 0;

        for (int i = 0; i < size; i++)
            if (objects[i] != NULL)
                volume++;

        return volume;
    }
};

