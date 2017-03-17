# QtCreator Urho3D Wizards

Placing (or linking to) the _templates_ folder inside the `~/.config/QtProject/qtcreator/` folder (in Linux) will add both an **Urho3D Project** and an **Urho3D C++ Class** to the _New File or Project_ dialog in QtCreator.

In case of the class wizard this will open a dialog allowing you to name your new class and specify its base class. Instead of typing the name of the base class there's also a drop down containing a selection of commonly inherited-from Urho3D classes to pick from.

- A `Context*` is added to the constructor's parameters if a class is created with an Urho3D class - that is known by the wizard - as its base class.
- For classes inheriting from Drawable it also adds `unsigned char drawableFlags`.
- When LogicComponent is picked as a subclass _RegisterObject_, _OnNodeSet_ and _Update_ functions are added.

Both the header and source file will be added to the .pro file and version control.
