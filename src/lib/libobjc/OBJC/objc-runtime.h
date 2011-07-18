/* objc-runtime.h */

/* Sending Messages */
id objc_msgSend(id theReciver, SEL theSelector, ...);
void objc_msgSend_stret(void *stretAddr, id theReciver, SEL theSelector, ...);
id objc_msgSendSuper(struct objc_super *superContext, SEL theSelector, ...);
void objc_msgSendSuper_stret(void *stretAddr, struct objc_super *superContext, SEL theSelector, ...);

/* Forwarding Messages */
id objc_msgSendv(id self, SEL op, unsigned arg_size, marg_list arg_frame);
void objc_msgSendv_stret(void *stretAddr, id self, SEL op, unsigned arg_size, marg_list arg_frame);
#define marg_malloc(margs, method)
#define marg_free(margs)
#define marg_getRef(margs, offset, type)
#define marg_getValue(margs, offset, type)
#define marg_setValue(margs, offset, type, value)

/* Adding Classes */
void objc_addClass(Class myClass);

/* Obtaining Class Definition */
int objc_getClassList(Class *buffer, int bufferLen);
id objc_getClass(const char *aClassName);
id objc_lookUpClass(const char *aClassName);
id objc_getMetaClass(const char *aClassName);
void objc_setClassHandler(int (*callback)(const char *));

