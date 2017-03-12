%{Cpp:LicenseTemplate}\
#include "%{HdrFileName}"
%{JS: Cpp.openNamespaces('%{Class}')}

@if '%{Base}' === 'LogicComponent'
void %{CN}::RegisterObject(Context* context)
{
	context->RegisterFactory<%{CN}>();
}

@endif
@if '%{Base}' === 'Object' || '%{Base}' === 'Component' || '%{Base}' === 'LogicComponent'
%{CN}::%{CN}(Context* context) : %{Base}(context)
@elsif '%{Base}' === 'Drawable'
%{CN}::%{CN}(Context* context, unsigned char drawableFlags) : Drawable(context, drawableFlags)
@elsif '%{Base}'
%{CN}::%{CN}() : %{Base}()
@else
%{CN}::%{CN}()
@endif
{

}
@if '%{Base}' === 'LogicComponent'

void %{CN}::OnNodeSet(Node* node)
{ (void)node;
}

void %{CN}::Update(float timeStep)
{
}
@endif
%{JS: Cpp.closeNamespaces('%{Class}')}\



