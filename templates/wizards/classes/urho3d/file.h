%{Cpp:LicenseTemplate}\

#ifndef %{GUARD}
#define %{GUARD}

#include <Urho3D/Urho3D.h>

%{JS: Cpp.openNamespaces('%{Class}')}
@if '%{Base}'
class %{CN} : public %{Base}
@else
class %{CN}
@endif
{
	URHO3D_OBJECT(%{CN}, %{Base});
public:
@if '%{Base}' === 'Drawable'
	%{CN}(Context* context, unsigned char drawableFlags);
@elsif %{isUrho3DClass}
	%{CN}(Context* context);
@else	
	%{CN}();
@endif
@if '%{Base}' === 'LogicComponent'
    static void RegisterObject(Context* context);
    virtual void OnNodeSet(Node* node);
    virtual void Update(float timeStep);
@endif
};
%{JS: Cpp.closeNamespaces('%{Class}')}
#endif // %{GUARD}\
