/* objc-class.h */

/* Types */
typedef struct objc_class objc_object;
typedef struct objc_object *id;

struct objc_super{
		id reciver;
		Class class;
};

struct objc_class{ // defines an Objective-C class
		struct objc_class *isa;
		struct objc_class *super_class;
		const char *name;
		long version;
		long info;
		long instance_size;
		struct objc_ivar_list *ivars;
		struct objc_method_list **methodList;
		struct objc_cache *cache;
		struct objc_protocol_list *protocols;
};

struct objc_ivar{ // specifies the name, type and location of one instance variable
	char *ivar_name;
	char *ivar_type;
	int var_offset;
};

struct objc_ivar_list{ // specifies the instance variables of each instance of a class
		int ivar_count;
		struct objc_ivar ivar_list[1];
};

id (*IMP)(id, SEL, ...); // pointer to the start of a method implementation

typedef void *marg_list; // reference to an argument list

typedef struct objc_selector SEL; // represents a method selector

struct objc_method{ // represents a method in a class definition
		SEL method_name;
		char *method_types;
		IMP method_imp;
};

struct objc_method_list{ // Contains an array of method definitions
		struct objc_method_list *obsolete;
		int method_count;
		struct objc_method_list method_list[1];
};

struct objc_cache{ // pointers to recently used methods
		unsigned int mask;
		unsigned int occupied;
		Method buckets[1];
};

struct objc_protocol_list{ // represents a list of formal protocols
		struct objc_protocol_list *next;
		int count;
		Protocol *list[1];
};

/* Accessing Methods */
Method class_getInstanceMethod(Class aClass, SEL aSelector);
Method class_getClassMethod(Class aClass, SEL aSelector);
struct objc_method_list *class_nextMethodList(Class theClass, void **iterator);
void class_addMethods(Class aClass, struct objc_method_list *methodList);
void class_removeMethods(Class aClass, struct objc_method_list *methodList);
unsigned method_getNumberOfArguments(Method method);
unsigned method_getSizeOfArguments(Method method);
unsigned method_getArgumentInfo(Method method, int argIndex, const char **type, int offset);

/* Accessing Instance Variable Definition */
Ivar class_getInstanceVariable(Class aClass, const char *aVariableName);

/* Accessing the Class Version */
void class_setVersion(Class theClass, int version);
int class_getVersion(Class theClass);

/* Posing As Another Class */
Class class_poseAs(Class imposter, Class original);

/* Instantiating Classes */
id class_createInstance(Class theClass, unsigned additionalByteCount);
id class_createInstanceFromZone(Class theClass, unsigned additionalByteCount, void *zone);

/* Accessing Instance Variables */
Ivar object_setInstanceVariable(id object, const char *name, void *value);
Ivar object_getInstanceVariable(id object, const char *name, void **value);

