template < class T, class U >
Boolean isinst(U u)
{
	return dynamic_cast< T >(u) != nullptr;
}