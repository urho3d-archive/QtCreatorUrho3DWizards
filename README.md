# QtCreator Urho3D Wizards

Placing (or linking to) the _templates_ folder inside the `~/.config/QtProject/qtcreator/` folder (in Linux) will add both an **Urho3D Project** and an **Urho3D C++ Class** to the _New File or Project_ dialog in QtCreator under _Files and Classes_. (Ctrl+N)
In case of the class wizard this will open a dialog allowing you to name your new class and specify its base class. Instead of typing the name of the base class there's also a drop down containing a selection of commonly inherited-from Urho3D classes to pick from.

- A `Context*` is added to the constructor's parameters if a class is created with an Urho3D class - that is known by the wizard - as its base class.
- For classes inheriting from Drawable it also adds `unsigned char drawableFlags`.
- When LogicComponent is picked as a subclass _RegisterObject_, _OnNodeSet_ and _Update_ functions are added.

Example of a resulting .h file:

```
//License template is inserted here

#ifndef MYCLASS_H
#define MYCLASS_H

#include <Urho3D/Urho3D.h>


class MyClass : public LogicComponent
{
    URHO3D_OBJECT(MyClass, LogicComponent);
public:
    MyClass(Context* context);
    static void RegisterObject(Context* context);
    virtual void OnNodeSet(Node* node);
    virtual void Update(float timeStep);
};

#endif // MYCLASS_H
```

...and .cpp file:

```
//License template is inserted here

#include "myclass.h"


void MyClass::RegisterObject(Context* context)
{
    context->RegisterFactory<MyClass>();
}

MyClass::MyClass(Context* context) : LogicComponent(context)
{
}

void MyClass::OnNodeSet(Node* node)
{ if(!node) return;
}

void MyClass::Update(float timeStep)
{
}
```

Both will be added to the .pro file and version control.
