/* Object.h */

@implementation Object
+ initialize
{
	return self;
}
- init
{
	return self;
}
+ new
{
	return [[self alloc] init];
}
+ alloc
{
	return class_create_instance(self);
}
- free
{
	return object_dispose(self);
}
- copy
{
	return [[self shallowCopy] deepen];
}
- shallowCopy
{
	return object_copy(self);
}
- deepen
{
	return self;
}
- deepenCopy
{
	return [self copy];
}
- (Class) class
{
	return object_get_class(self);
}
- (Class) superClass
{
	return object_get_super_class(self);
}
- (MetaClass) metaclass
{
	return object_get_meta_class(self);
}
- (const char *) name
{
	return object_get_class_name(self);
}
- self
{
	return self;
}
- (unsigned int) hash
{
	return (size_t) self;
}
- (BOOL) isEqual: anObject
{
	return self==anObject;
}
- (int) compare: anotherObject;
{
	if([self isEqual: anotherObject]) return 0;
	else if(self > anotherObject) return 1;
	else return -1;
}
